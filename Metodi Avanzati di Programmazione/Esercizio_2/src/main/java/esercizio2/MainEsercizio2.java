package esercizio2;

public class MainEsercizio2 {

    public static void main(String[] args) {

        // -------------------------------------------------------
        double arg0 = Double.parseDouble(args[0]);
        double arg1 = Double.parseDouble(args[1]);

        System.out.println("Sum between arg0 and arg1: " + (arg0 + arg1));
        System.out.println("Arg0 to the power of arg1: " + Math.pow(arg0, arg1));

        if(arg0 < 100)
        {
            if(arg0 < (Math.random() * 100))
            {
                System.out.println("True");
            }
        }
    }
}
