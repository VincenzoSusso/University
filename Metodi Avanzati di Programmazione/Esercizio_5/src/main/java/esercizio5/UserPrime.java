package esercizio5;

public class UserPrime extends User {
    //--------------------------------
    private static double PRICE_SHIPMENT = 1.0; // Price to pay for each shipment
    //--------------------------------

    public UserPrime() {
        super();
    }

    public UserPrime(String username) {
        super(username);
    }

    public static double getPriceShipment() {
        return PRICE_SHIPMENT;
    }
}
