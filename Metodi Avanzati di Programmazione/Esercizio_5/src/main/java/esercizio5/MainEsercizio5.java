package esercizio5;

public class MainEsercizio5 {

    public static void main(String[] args) {

        //----------------------------------------
        User user1 = new User("FooBar");
        User user2 = new UserPrime("HiEveryone");

        Item item1 = new Item("Animal Crossing", 60.0, 4);
        Item item2 = new Item("Nintendo Switch", 320.0, 1500);
        Item item3 = new Item("Tv Philips 43 LED Full HD", 200.0, 7000);
        Item item4 = new Item("Huawei P30 Lite", 240.0, 600);
        Item item5 = new Item("Echo Plus (2^ Generazione)", 119.99, 800);
        Item item6 = new Item("Apple AirPods", 139.99, 46);
        Item item7 = new Item("Huawei MateBook D 14 Notebook", 648.95, 1380);

        Warehouse warehouse = new Warehouse();

        warehouse.addItem(item1, 20);
        warehouse.addItem(item2, 5);
        warehouse.addItem(item3);
        warehouse.addItem(item4, 2);
        warehouse.addItem(item5, 15);
        warehouse.addItem(item6, 8);
        warehouse.addItem(item7);

        System.out.println("\n------------------------------------------- Users ---------------------------------------------------------");
        System.out.println(user1);
        System.out.println(user2);
        System.out.println("-----------------------------------------------------------------------------------------------------------\n");

        System.out.println("----------------------------------------- Warehouse --------------------------------------------------------");
        System.out.print(warehouse);
        System.out.println("------------------------------------------------------------------------------------------------------------\n\n");

        // First order
        try {
            user1.addItemCart(item1);
            warehouse.buyItem(item1);

            user1.addItemCart(item2);
            warehouse.buyItem(item2);

            user1.addItemCart(item3);
            warehouse.buyItem(item3);

            System.out.println("----------------------------------------- User1 Cart -------------------------------------------------------");
            System.out.println(user1.cartToString());
            System.out.println("------------------------------------------------------------------------------------------------------------\n");

            user1.buyItems();
        } catch (Exception e) {
            System.err.println(e.toString());
        }

        // Second order
        try {
            user1.addItemCart(item1, 3);
            warehouse.buyItem(item1, 3);

            user1.addItemCart(item2, 3);
            warehouse.buyItem(item2, 3);

            user1.addItemCart(item4);
            warehouse.buyItem(item4);

            user1.addItemCart(item6);
            warehouse.buyItem(item6);

            System.out.println("----------------------------------------- User1 Cart -------------------------------------------------------");
            System.out.println(user1.cartToString());
            System.out.println("------------------------------------------------------------------------------------------------------------\n");

            user1.buyItems();
        } catch (Exception e) {
            System.err.println(e.toString());
        }

        // Third order
        try {
            user2.addItemCart(item4);
            warehouse.buyItem(item4);

            user2.addItemCart(item5, 3);
            warehouse.buyItem(item5, 3);

            user2.addItemCart(item6, 2);
            warehouse.buyItem(item6, 2);

            user2.addItemCart(item7);
            warehouse.buyItem(item7);

            user2.removeItemCart(item5);
            warehouse.addItem(item5);

            System.out.println("----------------------------------------- User2 Cart -------------------------------------------------------");
            System.out.println(user2.cartToString());
            System.out.println("------------------------------------------------------------------------------------------------------------\n\n");

            user2.buyItems();
        } catch (Exception e) {
            System.err.println(e.toString());
        }

        System.out.println("----------------------------------------- Warehouse --------------------------------------------------------");
        System.out.print(warehouse);
        System.out.println("------------------------------------------------------------------------------------------------------------\n\n");

        System.out.println("------------------------------ Warehouse Most Purchased Items ---------------------------------------------");
        System.out.print(warehouse.mostPurchasedItemsToString());
        System.out.println("-----------------------------------------------------------------------------------------------------------\n");

        System.out.println("---------------------------------------- User1 Orders -----------------------------------------------------");
        System.out.print(user1.allOrderToString());
        System.out.println("------------------------------------------------------------------------------------------------------------\n");

        System.out.println("---------------------------------------- User2 Orders ------------------------------------------------------");
        System.out.print(user2.allOrderToString());
        System.out.println("------------------------------------------------------------------------------------------------------------\n");
    }
}
