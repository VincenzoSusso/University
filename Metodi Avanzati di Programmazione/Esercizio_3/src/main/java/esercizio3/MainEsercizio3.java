package esercizio3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class MainEsercizio3 {

    public static void main(String[] args) {

        //---------------------------------------
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String email = null;

        try {
            System.out.print("Enter an email: ");
            email = input.readLine();
            System.out.println();
        } catch (IOException e) {
            e.printStackTrace();
        }

        if(email != null) {
            System.out.println("Email is correct: " + email.matches("[a-zA-Z]+[a-zA-Z0-9._]*[^.][@][\\w]*[.][a-zA-Z]{2,3}"));
        }

    }

}
