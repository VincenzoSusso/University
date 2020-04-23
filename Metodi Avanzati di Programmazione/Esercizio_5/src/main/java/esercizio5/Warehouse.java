package esercizio5;

import java.util.*;

public class Warehouse {
    //--------------------------------
    private class Node {
        private int numberItemsStored = 0;
        private int numberItemsPurchased = 0;

        public void setNumberItemsStored(int numberItemsStored) throws IllegalArgumentException{
            if(numberItemsStored < 0) {
                throw new IllegalArgumentException("The number of items is not valid");
            }

            this.numberItemsStored = numberItemsStored;
        }

        public int getNumberItemsStored() {
            return numberItemsStored;
        }

        public void setNumberItemsPurchased(int numberItemsPurchased) {
            if(numberItemsPurchased < 0) {
                throw new IllegalArgumentException("The number of items is not valid");
            }

            this.numberItemsPurchased = numberItemsPurchased;
        }

        public int getNumberItemsPurchased() {
            return numberItemsPurchased;
        }
    }
    //--------------------------------
    private static int MAX_SIZE_PRIORITY_QUEUE = 5;

    private Map<Item, Node> warehouse = new HashMap<>();

    private PriorityQueue<Item> mostPurchasedItem = new PriorityQueue<>(MAX_SIZE_PRIORITY_QUEUE, new Comparator<Item>() {
        @Override
        public int compare(Item o1, Item o2) {
            int comparison = 0;

            if(warehouse.get(o1).getNumberItemsPurchased() > warehouse.get(o2).getNumberItemsPurchased()) {
                comparison = 1;
            } else if(warehouse.get(o1).getNumberItemsPurchased() < warehouse.get(o2).getNumberItemsPurchased()) {
                comparison = -1;
            }

            return comparison;
        }
    });
    //--------------------------------

    public void addItem(Item item) throws IllegalArgumentException {
        this.addItem(item, 1);
    }

    public void addItem(Item item, Integer numberItems) throws IllegalArgumentException {
        if(numberItems <= 0) {
            throw new IllegalArgumentException("The number of items is not valid");
        }

        Node quantity = this.warehouse.get(item);
        if(quantity == null) {
            Node temp = new Node();

            temp.setNumberItemsStored(numberItems);
            this.warehouse.put(item, temp);
        } else {
            quantity.setNumberItemsStored(quantity.getNumberItemsStored() + numberItems);
            this.warehouse.put(item, quantity);
        }
    }

    public void buyItem(Item item) throws IllegalArgumentException{
        this.buyItem(item, 1);
    }

    public void buyItem(Item item, Integer numberItems) throws IllegalArgumentException {
        if(numberItems < 0) {
            throw new IllegalArgumentException("The number of items is not valid");
        }

        if(isNumberItemsValid(item, numberItems)) {
            Node temp = this.warehouse.get(item);

            temp.setNumberItemsStored(temp.getNumberItemsStored() - numberItems);
            temp.setNumberItemsPurchased(temp.getNumberItemsPurchased() + numberItems);
            this.warehouse.put(item, temp);
            this.updatePriorityQueue(item);
        } else {
            throw new IllegalArgumentException("The number of items is not valid");
        }
    }

    public void removeItem(Item item) throws IllegalArgumentException {
        if(this.warehouse.remove(item) == null) {
            throw new IllegalArgumentException("The item is not valid");
        }
    }

    private boolean isNumberItemsValid(Item item, Integer numberItems) throws NullPointerException {
        Node node = this.warehouse.get(item);

        if(node == null)
        {
            throw new NullPointerException();
        }

        return (node.getNumberItemsStored() >= numberItems);
    }

    public int searchItem(Item item) throws NullPointerException {
        Node node = this.warehouse.get(item);

        if(node == null) {
            throw new NullPointerException();
        }

        return node.getNumberItemsStored();
    }

    public String itemMinusQuantityToString(int quantity) {
        StringBuilder itemString = new StringBuilder();

        for(Map.Entry<Item, Node> entry : this.warehouse.entrySet()) {
            Item key = entry.getKey();
            Node value = entry.getValue();

            if(value.getNumberItemsStored() <= quantity) {
                itemString.append(key.toString());
            }
        }

        return itemString.toString();
    }

    private void updatePriorityQueue(Item item) {
        // Used to remove duplicate
        if (this.mostPurchasedItem.contains(item)) {
            this.mostPurchasedItem.remove(item);
        }

        this.mostPurchasedItem.add(item);

        if(this.mostPurchasedItem.size() > MAX_SIZE_PRIORITY_QUEUE) {
            this.mostPurchasedItem.poll();
        }
    }


    public String mostPurchasedItemsToString() {
        StringBuilder string = new StringBuilder();
        int count = 0;

        for(Item item: this.mostPurchasedItem) {
            int itemPurchased = this.warehouse.get(item).getNumberItemsPurchased();

            string.append("Item ").append(count).append(" --> ").append(item).append(" - Purchased: ").append(itemPurchased).append('\n');
            count++;
        }

        return string.toString();
    }

    //--------------------------------

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        int count = 0;

        for(Map.Entry<Item, Node> entry : this.warehouse.entrySet()) {
            Item key = entry.getKey();
            Node value = entry.getValue();

            string.append("Item ").append(count).append(" --> ").append(key.toString()).append(" - Quantity: ").append(value.getNumberItemsStored()).append('\n');
            count++;
        }

        return string.toString();
    }

    //--------------------------------
}
