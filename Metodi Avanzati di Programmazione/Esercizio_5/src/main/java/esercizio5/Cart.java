package esercizio5;

import java.util.Map;
import java.util.HashMap;

public class Cart {
    //--------------------------------
    private static double WEIGHT_EXPENDITURE = 1000.0; // It is used to know how much weight the user has to pay an extra

    private Map<Item, Integer> cart = new HashMap<>();
    private double itemsPrice = 0.0;
    private double shipmentPrice = 0.0;
    private double totalWeight = 0.0;
    //--------------------------------

    private void setItemsPrice(double itemPrice) {
        this.itemsPrice = itemPrice;
    }

    public double getItemsPrice() {
        return this.itemsPrice;
    }

    private void setShipmentPrice(double shipmentPrice) {
        this.shipmentPrice = shipmentPrice;
    }

    public double getShipmentPrice() {
        return this.shipmentPrice;
    }

    private void setTotalWeight(double totalWeight) {
        this.totalWeight = totalWeight;
    }

    public double getTotalWeight() {
        return this.totalWeight;
    }

    public double getTotalPrice() {
        return this.getItemsPrice() + this.getShipmentPrice();
    }

    private double calculateShipmentPrice(User user) {
        double weight = this.getTotalWeight();
        double shipmentPrice = 0.0;

        if(this.cart.size() != 0) {
            if (user instanceof UserPrime) {
                shipmentPrice = UserPrime.getPriceShipment();
            } else {
                int count = 0;

                // Used to count the price of the shipment
                do {
                    count++;
                    weight -= Cart.WEIGHT_EXPENDITURE;
                } while (weight > 0);

                shipmentPrice = User.getPriceShipment() * count;
            }
        }

        return shipmentPrice;
    }

    public void addItem(User user, Item item) throws IllegalArgumentException {
        this.addItem(user, item, 1);
    }

    public void addItem(User user, Item item, int numberItems) throws IllegalArgumentException {
        // Used to know how many items have been ordered
        Integer quantity = this.cart.get(item);

        if(numberItems <= 0) {
            throw new IllegalArgumentException("The number of items is not valid");
        }

        this.cart.put(item, (quantity == null) ? numberItems : quantity + numberItems);
        this.setTotalWeight(this.getTotalWeight() + (item.getWeight() * numberItems));
        this.setItemsPrice(this.getItemsPrice() + (item.getPrice() * numberItems));
        this.setShipmentPrice(this.calculateShipmentPrice(user));
    }

    private boolean isNumberItemsValid(Item item, Integer numberItems) throws NullPointerException {
        Integer quantity = this.cart.get(item);

        if(quantity == null)
        {
            throw new NullPointerException();
        }

        return (quantity >= numberItems);
    }

    public void removeItem(User user, Item item) throws IllegalArgumentException{
        this.removeItem(user, item, 1);
    }

    public void removeItem(User user, Item item, int numberItems) throws IllegalArgumentException {
        if(numberItems <= 0) {
            throw new IllegalArgumentException("The number of items is not valid");
        }

        if(isNumberItemsValid(item, numberItems)) {
            this.cart.put(item, this.cart.get(item) - numberItems);
            this.setItemsPrice(this.getItemsPrice() - (item.getPrice() * numberItems));
            this.setShipmentPrice(this.calculateShipmentPrice(user));
        }
    }

    public Order closeCart() {
        Order order = new Order();

        for(Map.Entry<Item, Integer> entry : this.cart.entrySet()) {
            Item key = entry.getKey();
            Integer value = entry.getValue();

            order.addItem(key, value);
        }

        order.setOrderItemsPrice(this.getItemsPrice());
        order.setOrderShipmentPrice(this.getShipmentPrice());

        this.resetCart();

        return order;
    }

    public void resetCart() {
        this.cart.clear();
        this.setItemsPrice(0.0);
        this.setShipmentPrice(0.0);
        this.setTotalWeight(0.0);
    }

    //--------------------------------

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();

        string.append("Cart ").append(" --> \n");
        for(Map.Entry<Item, Integer> entry : this.cart.entrySet()) {
            Item key = entry.getKey();
            Integer value = entry.getValue();

            string.append(key.toString()).append(" - Quantity: ").append(value.toString()).append('\n');
        }
        string.append("Items Price: ").append(this.getItemsPrice()).append("$\n");
        string.append("Shipment Price: ").append(this.getShipmentPrice()).append("$\n");
        string.append("Total Weight: ").append(this.getTotalWeight()).append("g\n");
        string.append("Total Price: ").append(this.getTotalPrice()).append('$');

        return string.toString();
    }


    //--------------------------------
}