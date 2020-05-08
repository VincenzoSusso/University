package esercizio7.server;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class MainEsercizio7Server {
    public static void main(String[] args) {
        ServerSocket serverSocket = null;
        Socket socket = null;

        final int port = 10000;

        try {
            serverSocket = new ServerSocket(port);
            System.out.println("The server is running!");
        } catch (IOException e) {
            System.err.println("Cannot start the server!");
        }

        try {
            while (true) {
                if (serverSocket != null) {
                    socket = serverSocket.accept();
                    Thread thread = new RequestThread(socket);
                    thread.start();
                }
            }
        } catch (IOException e) {
            System.err.println("Cannot start the connection with the client!");
        } finally {
            try {
                if (socket != null) {
                    socket.close();
                }
            } catch (IOException e) {
                System.err.println("Cannot close the connection with the client!");
            }

        }
    }
}
