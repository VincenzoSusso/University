package esercizio5;

import java.util.Objects;
import java.util.Queue;
import java.util.concurrent.LinkedBlockingDeque;

public class User {
    //--------------------------------
    private static int ID_GENERATOR = 0;
    private static double PRICE_SHIPMENT = 2.0; // Price to pay for each 100g

    private int id;
    private String username;
    private Cart cart = new Cart();
    private Queue<Order> order = new LinkedBlockingDeque<>();
    //--------------------------------

    public User() {
        this.setId(ID_GENERATOR);
        ID_GENERATOR++;
    }

    public User(String username) {
        this.setId(ID_GENERATOR);
        this.setUsername(username);
        ID_GENERATOR++;
    }

    private void setId(int id) throws IllegalArgumentException {
        if(id < 0) {
            throw new IllegalArgumentException("The id is not valid");
        }

        this.id = id;
    }

    public int getId() {
        return this.id;
    }

    public void setUsername(String username) throws IllegalArgumentException {
        if(username.isEmpty()) {
            throw new IllegalArgumentException("The username is not valid");
        }

        this.username = username;
    }

    public String getUsername() {
        return this.username;
    }

    public static double getPriceShipment() {
        return PRICE_SHIPMENT;
    }

    public void addItemCart(Item item) {
        this.addItemCart(item, 1);
    }

    public void addItemCart(Item item, int numberItems) {
        this.cart.addItem(this, item, numberItems);
    }

    public void removeItemCart(Item item) {
        this.removeItemCart(item, 1);
    }

    public void removeItemCart(Item item, int numberItems) {
        this.cart.removeItem(this, item, numberItems);
    }

    public void buyItems() {
        // Reset cart and add a new order
        this.addOrder(this.cart.closeCart());
    }

    private void addOrder(Order order) {
        this.order.add(order);
    }

    public Order getOrder() {
        return this.order.element();
    }

    public int getOrdersNumber() {
       return this.order.size();
    }

    public String allOrderToString() {
        StringBuilder orderString = new StringBuilder();

        for(Order order : this.order) {
            orderString.append(order.toString()).append('\n');
        }

        return orderString.toString();
    }

    public String cartToString() {
        return this.cart.toString();
    }

    //--------------------------------

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof User)) return false;
        User user = (User) o;
        return getId() == user.getId();
    }

    @Override
    public int hashCode() {
        return Objects.hash(getId());
    }

    @Override
    public String toString() {
        return "Id:" + this.getId() + ", Username:'" + this.getUsername() + '\'';
    }

    //--------------------------------
}
