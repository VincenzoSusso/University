package esercizio7.client;

import javax.swing.*;
import java.io.*;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;

public class MainEsercizio7Client {
    public static void main(String[] args) {
        Socket socket = null;

        final String addressServer = "localhost";
        final int port = 10000;

        try {
            InetAddress address = InetAddress.getByName(addressServer);
            socket = new Socket(address, port);
        } catch (UnknownHostException e) {
            JOptionPane.showMessageDialog(null, "An error has occurred while obtaining the IP address of the server!", "Error", JOptionPane.ERROR_MESSAGE);
        } catch (IOException e) {
            JOptionPane.showMessageDialog(null, "An error has occurred while connecting to the server!", "Error", JOptionPane.ERROR_MESSAGE);
        }

        try {
            BufferedReader in;
            PrintWriter out;

            if (socket != null) {
                in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);
            } else {
                throw new IOException();
            }

            View view = new View(in, out);

            if (!view.setUsername()) {
                view.setWindowVisible();
                while (!view.isConnectionClosed()) {
                    view.manageInput();
                }
            }

            view.disposeWindow();
        } catch (IOException e) {
            JOptionPane.showMessageDialog(null, "Cannot communicate with the server!", "Error", JOptionPane.ERROR_MESSAGE);
        } finally {
            try {
                if (socket != null) {
                    socket.close();
                }
            } catch (IOException e) {
                JOptionPane.showMessageDialog(null, "Cannot close the connection with the server!", "Error", JOptionPane.ERROR_MESSAGE);
            }
        }
    }
}
