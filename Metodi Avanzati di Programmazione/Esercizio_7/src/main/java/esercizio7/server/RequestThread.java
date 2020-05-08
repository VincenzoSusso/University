package esercizio7.server;

import esercizio7.UsernameUsedException;

import java.io.*;
import java.net.Socket;
import java.util.*;

public class RequestThread extends Thread {
    private final Socket socket;
    BufferedReader in; // Used to communicate with the server
    PrintWriter out; // Used to communicate with the server
    private String username;
    boolean exit = false;
    private static final Map<String, Long> usernameTaken = Collections.synchronizedMap(new HashMap<>());

    //--------------------------------------------- REGEX --------------------------------------------------------------
    private static final String START_INPUT_COMAND = "#";
    private static final String START_INPUT_USER = "<";
    private static final String END_INPUT_USER = ">";
    private static final String REGEX_HELP = START_INPUT_COMAND + "help"; // Regex of "#help"
    private static final String REGEX_EXIT = START_INPUT_COMAND + "exit"; // Regex of "#exit"

    // Regex of "#name <username>" (ex. #name <WinEnzo>)
    private static final String REGEX_USERNAME = START_INPUT_COMAND + "name " + START_INPUT_USER + "[\\S]+" + END_INPUT_USER;

    // Regex of "#send <username> <message>" (ex. #send <WinEnzo> <Hi>)
    private static final String REGEX_MESSAGE = START_INPUT_COMAND + "send " + START_INPUT_USER + "[\\S]+" +
            END_INPUT_USER + " " + START_INPUT_USER + "([\\S]+[\\s]*)+" + END_INPUT_USER;
    // ------------------------------------------- END REGEX -----------------------------------------------------------
    private static final String ERROR_MESSAGE = START_INPUT_COMAND + "error";
    private static final String OK_MESSAGE = START_INPUT_COMAND + "ok";

    public RequestThread(Socket socket) {
        this.socket = socket;
    }

    public PrintWriter getOutputStreamThread() {
        return out;
    }

    private static String help() {
        return "Available commands:\n" + "Enter username: #name <username>\n" + "Send message: #send <username> <message>\n" +
                "Exit: #exit\n";
    }

    private void setUsernameClient() throws IOException {
        String input;

        do {
            try {

                username = null;
                input = in.readLine();

                if (input.matches(REGEX_USERNAME)) {
                    // Valid command username
                    username = input.substring(input.indexOf(START_INPUT_USER) + 1, input.indexOf(END_INPUT_USER));
                    if (usernameTaken.containsKey(username)) {
                        throw new UsernameUsedException(username);
                    }
                } else if (input.matches(REGEX_EXIT)) {
                    exit = true;
                } else {
                    out.println("The command that you have entered is wrong, the right command is \"#name <username>\"");
                }
            } catch (UsernameUsedException e) {
                out.println(e.getMessage());
            }
        } while ((username == null || usernameTaken.containsKey(username)) && !exit);
    }

    private void comunicateWithClient() throws IOException {
        String input;

        while (!exit) {
            input = in.readLine();

            if (input.matches(REGEX_MESSAGE)) {
                String[] string = input.split(START_INPUT_USER);
                String receiving = string[1].substring(0, string[1].length() - 2); //Delete the end of the command + one space
                String message = string[2].substring(0, string[2].length() - 1); // Delete the end of the command

                if (usernameTaken.containsKey(receiving)) {
                    findThread(receiving).getOutputStreamThread().println("Message from " + username + ": " + message + "\n");
                    out.println(OK_MESSAGE + "\n");
                } else {
                    out.println(ERROR_MESSAGE + "\n");
                }
            } else if (input.matches(REGEX_HELP)) {
                // Valid command help
                out.println(help());
            } else if (input.matches(REGEX_EXIT)) {
                // Valid command exit
                exit = true;
            } else {
                out.println("The command that you have entered is wrong, try the command " + REGEX_HELP + "\n");
            }
        }
    }

    @Override
    public void run() {
        try {
            System.out.println("New connection" + socket);
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);

            setUsernameClient();

            if (!exit) {
                // Add the user to the hashmap a print a \n into the client's terminal
                usernameTaken.put(username, this.getId());
                out.println();
            }

            comunicateWithClient();

            // Deleting the username from the hashmap in order to be used by others users
            if (username != null) {
                out.println("Bye from the server " + username);
                usernameTaken.remove(username);
            } else {
                out.println("Bye from the server");
            }

        } catch (IOException e) {
            System.err.println("A problem has occured during the communication with the client!");
            if (username != null) {
                usernameTaken.remove(username);
            }
        } finally {
            try {
                socket.close();
            } catch (IOException e) {
                System.out.println("Cannot close the communication with the client!");
            }
        }
    }

    public RequestThread findThread(String username) {
        RequestThread thread = null;

        long idThread = usernameTaken.get(username);
        for (Thread t : Thread.getAllStackTraces().keySet()) {
            if (t.getId() == idThread) {
                thread = (RequestThread) t;
            }
        }

        return thread;
    }
}
