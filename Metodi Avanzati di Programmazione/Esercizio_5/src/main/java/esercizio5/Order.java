package esercizio5;

import java.util.HashMap;
import java.util.Map;

public class Order {
    //--------------------------------
    private Map<Item, Integer> order = new HashMap<>();
    private double orderItemsPrice = 0.0;
    private double orderShipmentPrice = 0.0;
    //--------------------------------

    public void setOrderItemsPrice(double orderItemsPrice) {
        this.orderItemsPrice = orderItemsPrice;
    }

    public double getOrderItemsPrice() {
        return orderItemsPrice;
    }

    public void setOrderShipmentPrice(double orderShipmentPrice) {
        this.orderShipmentPrice = orderShipmentPrice;
    }

    public double getOrderShipmentPrice() {
        return orderShipmentPrice;
    }

    public double getTotalOrderPrice() {
        return (this.getOrderItemsPrice() + this.getOrderShipmentPrice());
    }

    public void addItem(Item item, int numberItems) {
        this.order.put(item, numberItems);
    }

    //--------------------------------

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();

        string.append("Order ").append(" --> \n");
        for(Map.Entry<Item, Integer> entry : this.order.entrySet()) {
            Item key = entry.getKey();
            Integer value = entry.getValue();

            string.append(key.toString()).append(" - Quantity: ").append(value.toString()).append('\n');
        }
        string.append("Items Price: ").append(this.getOrderItemsPrice()).append("$\n");
        string.append("Shipment Price: ").append(this.getOrderShipmentPrice()).append("$\n");
        string.append("Order Price: ").append(this.getTotalOrderPrice()).append('$');

        return string.toString();
    }


    //--------------------------------
}
