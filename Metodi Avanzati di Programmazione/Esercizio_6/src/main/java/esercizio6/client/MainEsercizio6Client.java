package esercizio6.client;

import java.io.*;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;

public class MainEsercizio6Client {
    public static void main(String[] args) {
        Socket socket = null;
        StringBuilder stringToPrint;
        String keyboardInput;
        boolean exit = false; // Used to close the communication with the server

        final String addressServer = "localhost";
        final int port = 10000;

        final String START_OUTPUT_COMAND = "#";
        final String REGEX_EXIT = START_OUTPUT_COMAND + "exit"; // Regex of "#exit"

        try {
            InetAddress address = InetAddress.getByName(addressServer);
            socket = new Socket(address, port);
        } catch (UnknownHostException e) {
            System.err.println("An error has occurred while obtaining the IP address of the server!");
        } catch (IOException e) {
            System.err.println("An error has occurred while connecting to the server!");
        }

        try {
            BufferedReader in;
            PrintWriter out;
            BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in));
            PrintStream screen = System.out;

            if (socket != null) {
                in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);
            } else {
                throw new IOException();
            }

            while (!exit) {
                Thread.sleep(1000); // Used to take all the messages from the server

                boolean flag = false;
                stringToPrint = new StringBuilder();

                //Used to read ALL the messages from the server
                while (in.ready()) {
                    stringToPrint.append(in.readLine());
                    stringToPrint.append("\n");
                    flag = true;
                }

                if (flag) {
                    stringToPrint.deleteCharAt(stringToPrint.length() - 1); // Remove last \n
                    screen.print(stringToPrint);
                    keyboardInput = keyboard.readLine();
                    out.println(keyboardInput);
                    if (keyboardInput.matches(REGEX_EXIT)) {
                        exit = true;
                        screen.println("Closing the communication with the server");
                    }
                }

                // Used to check if the Server has closed the socket
                if (out.checkError()) {
                    System.err.println("Cannot communicate with the server");
                    exit = true;
                }
            }


        } catch (IOException | InterruptedException e) {
            System.err.println("Cannot communicate with the server");
        } finally {
            try {
                if (socket != null) {
                    socket.close();
                }
            } catch (IOException e) {
                System.err.println("Cannot close the connection with the server!");
            }
        }
    }
}
