/*



 __          __  _____           ______
 \ \        / / |_   _|         |  ____|
  \ \  /\  / /    | |    _ __   | |__     _ __    ____   ___
   \ \/  \/ /     | |   | '_ \  |  __|   | '_ \  |_  /  / _ \
    \  /\  /     _| |_  | | | | | |____  | | | |  / /  | (_) |
     \/  \/     |_____| |_| |_| |______| |_| |_| /___|  \___/




*/

/*****************************************************************************************************************************************************
*                                                                                                                                                    *
*  Author : WinEnzo                                                                                                                                  *
*  Name : Discount.c                                                                                                                                 *
*  Purpose : The purpose of this program is to give the user the possibility to enter the number of discounts (10%, 20%, 30%, 40%) in input and      *
*            to give the user the possibility to choose which discounts to apply for each product.                                                   *
*  Date : 22/11/2018                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>

#define P10 10 //10% discount
#define P20 20 //20% discount
#define P30 30 //30% discount
#define P40 40 //40% discount
#define P100 100 //Used to calculate the percentual of discount


int main (void)
{  
    //--------------------------------------
    printf(
        " __          __  _____           ______\n"
        " \\ \\        / / |_   _|         |  ____|\n"
        "  \\ \\  /\\  / /    | |    _ __   | |__     _ __    ____   ___\n"
        "   \\ \\/  \\/ /     | |   | '_ \\  |  __|   | '_ \\  |_  /  / _ \\\n"
        "    \\  /\\  /     _| |_  | | | | | |____  | | | |  / /  | (_) |\n"
        "     \\/  \\/     |_____| |_| |_| |______| |_| |_| /___|  \\___/\n\n"
    );

    printf(
        "/********************************************************************************************************\n"
        "*  Author : WinEnzo                                                                                     *\n"
        "*  Name : Discount.c                                                                                    *\n"
        "*  Purpose : The purpose of this program is to give the user the possibility to enter the number of     *\n"
        "*            discounts in input and to give the user the possibility to choose which discounts          *\n"
        "*            (10%%, 20%%, 30%%, 40%%) to apply for each product.                                            *\n"
        "*  Date : 22/11/2018                                                                                    *\n"
        "********************************************************************************************************/\n\n"
    );
    //--------------------------------------

    //--------------------------------------
    printf("Discount\n\n");
    //--------------------------------------

    //--------------------------------------
    int n_discount = 0, i = 0, choose = 0; /* 1 --> Used to know how many discount the user want to apply
                                              2 --> Used to count the number of repeats 
                                              3 --> Used to choose a discount */

    float price = 0, discount = 0, discount_price = 0; /* 1 --> Used to take the price of the object that the user 
                                                                want to discount
                                                          2 --> Used to calculate the discount of the price 
                                                          3 --> Used to store the price discounted */

    printf("1 --> To discount 10%%"); //Menu
    printf("\n2 --> To discount 20%%");
    printf("\n3 --> To discount 30%%");
    printf("\n4 --> To discount 40%%\n\n");

    do
    {
        printf("Insert how many object do you want to discount: "); //Used to select the number of the object > 0
        scanf("%d", &n_discount);
    }
    while(n_discount <= 0);

    do
    {
        printf("\nInsert the price of the %d^ object: ", i+1); //Used to take the price of the object
        scanf("%f", &price);

        printf("Insert the discount that you want to apply to the %d^ object : ", i+1); //Used to choose the 
        scanf("%d", &choose);                                                           //price of the object

        switch(choose)
        {
            case 1: //10% Discount
                printf("You've chosen the %d%% discount", P10);

                discount = (price * P10) / P100; //Calculate the discount
                discount_price = price - discount; //Calculate the real price 

                printf("\nThe price of the %d^ object is: %.2f$, the discount is %.2f$ so the total is %.2f$", i+1, price, discount, discount_price); //Output
                break;
            case 2: //20% Discount
                printf("You've chosen the %d%% discount", P20);

                discount = (price * P20) / P100; //Calculate the discount
                discount_price = price - discount; //Calculate the real price
                
                printf("\nThe price of the %d^ object is: %.2f$, the discount is %.2f$ so the total is %.2f$", i+1, price, discount, discount_price); //Output
                break;
            case 3: //30% Discount
                printf("You've chosen the %d%% discount",P30);

                discount = (price * P30) / P100; //Calculate the discount
                discount_price = price - discount; //Calculate the real price

                printf("\nThe price of the %d^ object is: %.2f$, the discount is %.2f$ so the total is %.2f$", i+1, price, discount, discount_price); //Output
                break;
            case 4: //40% Discount
                printf("You've chosen the %d%% discount",P40);

                discount = (price * P40) / P100; //Calculate the discount
                discount_price = price - discount; //Calculate the real price

                printf("\nThe price of the %d^ object is: %.2f$, the discount is %.2f$ so the total is %.2f$", i+1, price, discount, discount_price); //Output
                break;
            default: //Wrong choice
                printf("Error --> You've choosen a wrong discount"); //Output
                break; 
        }

        printf("\n");

        i++;
    }
    while(i < n_discount);

    exit(EXIT_SUCCESS);
}