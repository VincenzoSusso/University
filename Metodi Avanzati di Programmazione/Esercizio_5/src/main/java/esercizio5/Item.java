package esercizio5;

import java.util.Objects;

public class Item {
    //--------------------------------
    private static int ID_GENERATOR = 0;

    private int id;
    private String description;
    private double price; // Expressed in dollars
    private double weight; // Measured in grams
    //--------------------------------

    public Item() {
        this.setId(ID_GENERATOR);
        ID_GENERATOR++;
    }

    public Item(String description, double price, double weight) {
        this.setId(ID_GENERATOR);
        this.setDescription(description);
        this.setPrice(price);
        this.setWeight(weight);
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

    public void setDescription(String description) throws IllegalArgumentException {
        if(description.isEmpty()) {
            throw new IllegalArgumentException("The description is not valid");
        }

        this.description = description;
    }

    public String getDescription() {
        return this.description;
    }

    public void setPrice(double price) throws IllegalArgumentException {
        if(price <= 0) {
            throw new IllegalArgumentException("The price is not valid");
        }

        this.price = price;
    }

    public double getPrice() {
        return this.price;
    }

    public void setWeight(double weight) throws IllegalArgumentException {
        if(weight < 0.0) {
            throw new IllegalArgumentException("The weight is not valid");
        }

        this.weight = weight;
    }

    public double getWeight() {
        return this.weight;
    }

    //--------------------------------

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Item)) return false;
        Item item = (Item) o;
        return getId() == item.getId();
    }

    @Override
    public int hashCode() {
        return Objects.hash(getId());
    }

    @Override
    public String toString() {
        return "Id:" + this.getId() + ", Description:'" + this.getDescription() + '\'' + ", Price:" + this.getPrice() + '$' + ", Weight:" + this.getWeight() + 'g';
    }

    //--------------------------------

}
