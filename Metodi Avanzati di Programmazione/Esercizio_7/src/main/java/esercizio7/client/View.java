package esercizio7.client;

import javax.swing.*;
import javax.swing.text.DefaultCaret;
import java.awt.*;
import java.awt.event.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;

public class View {
    private boolean exit = false; // Used to know when the user want to close connection

    private final BufferedReader input;
    private final PrintWriter output;

    private final JFrame JFmainFrame = new JFrame("Client");
    private final JPanel JPmainPanel = new JPanel();

    private final JTextArea JTmainOutputArea = new JTextArea();
    private final JScrollPane JSoutputAreaScroller = new JScrollPane(JTmainOutputArea, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED, JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
    private final DefaultCaret caret = (DefaultCaret) JTmainOutputArea.getCaret();

    private final JPanel JPinputPanel = new JPanel();
    private final JLabel JLinputLabel = new JLabel("Input: ");
    private final JTextField JTmainInputField = new JTextField();
    private final JButton JBenterButton = new JButton("Enter");


    public View(BufferedReader input, PrintWriter output) {
        this.input = input;
        this.output = output;

        initView();
    }

    private void initView() {
        // JFrame options
        JFmainFrame.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE); // Used to check windowListener
        JFmainFrame.setFocusable(false);
        JFmainFrame.setMinimumSize(new Dimension(750, 500));
        JFmainFrame.setSize(750, 500);
        JFmainFrame.setResizable(false);
        JFmainFrame.setLocationRelativeTo(null); // Used to center the window
        JFmainFrame.getContentPane().add(JPmainPanel);
        JFmainFrame.getRootPane().setDefaultButton(JBenterButton); // Used to action the button when the user press enter
        JFmainFrame.addWindowListener(new WindowsListener());

        // Main JPanel options
        JPmainPanel.setLayout(new BoxLayout(JPmainPanel, BoxLayout.PAGE_AXIS));
        JPmainPanel.add(Box.createRigidArea(new Dimension(750, 10))); // Used to add spaces between component
        JPmainPanel.add(JSoutputAreaScroller);
        JPmainPanel.add(Box.createRigidArea(new Dimension(750, 10))); // Used to add spaces between component
        JPmainPanel.add(JPinputPanel);
        JPmainPanel.setBackground(Color.decode("#A0BAB5"));

        // JScrollPane options
        JSoutputAreaScroller.setMinimumSize(new Dimension(720, 400));
        JSoutputAreaScroller.setMaximumSize(new Dimension(720, 400));
        JSoutputAreaScroller.setAutoscrolls(true);
        JSoutputAreaScroller.setForeground(Color.BLACK);

        // Caret management
        caret.setUpdatePolicy(DefaultCaret.ALWAYS_UPDATE);

        // JTextArea options
        JTmainOutputArea.setRows(10);
        JTmainOutputArea.setColumns(10);
        JTmainOutputArea.setEditable(false);
        JTmainOutputArea.setLineWrap(true);
        JTmainOutputArea.setWrapStyleWord(true);
        JTmainOutputArea.setAutoscrolls(true);
        JTmainOutputArea.setForeground(Color.BLACK);
        JTmainOutputArea.setBorder(BorderFactory.createLineBorder(Color.BLACK));
        JTmainOutputArea.setToolTipText("Area used to show other users' messages");

        // Input JPanel options
        JPinputPanel.add(JLinputLabel);
        JPinputPanel.add(JTmainInputField);
        JPinputPanel.add(Box.createRigidArea(new Dimension(20, 50)));
        JPinputPanel.add(JBenterButton);
        JPinputPanel.setMinimumSize(new Dimension(750, 50));
        JPinputPanel.setMaximumSize(new Dimension(750, 50));
        JPinputPanel.setBackground(Color.decode("#A0BAB5"));
        JPinputPanel.setLayout(new FlowLayout());

        // JLabel options
        JLinputLabel.setHorizontalAlignment(SwingConstants.LEFT);

        // JTextField options
        JTmainInputField.setEditable(true);
        JTmainInputField.setAutoscrolls(true);
        JTmainInputField.setEnabled(true);
        JTmainInputField.setColumns(50);
        JTmainInputField.setBorder(BorderFactory.createLineBorder(Color.BLACK));

        // JButton options
        JBenterButton.addActionListener(new ButtonPressed());
    }

    public boolean setUsername() {
        String username = null;
        String serverMessage;

        try {
            do {
                username = JOptionPane.showInputDialog(JFmainFrame, "Insert your username:", "Username", JOptionPane.QUESTION_MESSAGE);

                if (username == null) {
                    output.println("#exit");
                    exit = true;
                } else {
                    output.println(username);
                }
                serverMessage = input.readLine();

                // Dialog that
                if (serverMessage.startsWith("The username") || serverMessage.startsWith("The command that you have entered is wrong")) {
                    JOptionPane.showMessageDialog(JFmainFrame, serverMessage, "Error", JOptionPane.ERROR_MESSAGE);
                }

                if (serverMessage.equalsIgnoreCase("Bye from the server")) {
                    JOptionPane.showMessageDialog(JFmainFrame, serverMessage, "You are now disconnected from the server", JOptionPane.INFORMATION_MESSAGE);
                }

            } while ((serverMessage.startsWith("The username") || serverMessage.startsWith("The command that you have entered is wrong")) && !exit);
        } catch (IOException e) {
            JOptionPane.showMessageDialog(JFmainFrame, "Cannot communicate with the server", "Error", JOptionPane.ERROR_MESSAGE);
            exit = true;
        }

        if (username != null) {
            username = username.substring(username.indexOf("<") + 1, username.indexOf(">"));
            JFmainFrame.setTitle("Client - " + username);
        }

        return exit;
    }

    public void manageInput() {
        try {
            while (input.ready()) {
                JTmainOutputArea.append(input.readLine() + "\n");
            }
        } catch (IOException e) {
            JOptionPane.showMessageDialog(JFmainFrame, "Cannot communicate with the server!", "Error", JOptionPane.ERROR_MESSAGE);
            exit = true;
        }
    }

    public void setWindowVisible() {
        JFmainFrame.setVisible(true);
    }

    public void disposeWindow() {
        JFmainFrame.setVisible(false);
        JFmainFrame.dispose();
    }

    public boolean isConnectionClosed() {
        return exit;
    }

    // Action listeners
    private class WindowsListener implements WindowListener {

        @Override
        public void windowClosing(WindowEvent e) {
            int input = JOptionPane.showConfirmDialog(JFmainFrame, "Are you sure you want to exit?", "Exit", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE);
            if (input == JOptionPane.YES_OPTION) {
                exit = true;
            }
        }

        @Override
        public void windowOpened(WindowEvent e) {

        }

        @Override
        public void windowClosed(WindowEvent e) {

        }

        @Override
        public void windowIconified(WindowEvent e) {

        }

        @Override
        public void windowDeiconified(WindowEvent e) {

        }

        @Override
        public void windowActivated(WindowEvent e) {

        }

        @Override
        public void windowDeactivated(WindowEvent e) {

        }
    }

    private class ButtonPressed implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            String textInput = JTmainInputField.getText();
            if (textInput.equals("#exit")) {
                exit = true;
            }

            if (output.checkError()) {
                JOptionPane.showMessageDialog(JFmainFrame, "Cannot communicate with the server!", "Error", JOptionPane.ERROR_MESSAGE);
                exit = true;
            }

            output.println(textInput);
            JTmainInputField.setText(null);
        }

    }
}
