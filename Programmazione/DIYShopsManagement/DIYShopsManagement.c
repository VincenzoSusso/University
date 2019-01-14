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
*  Name : DIYShopsManagement.c                                                                                                                       *
*  Purpose : The purpose of this program is to manage several DIY shops that everyday refound themself requiring to a warehouse different materials. *
*            Every request is formed by: the id of the shop, the number of material required, the id of the material, a description of the material  *
*            the number of material required. The warehouse manage the material storing using a table formed by: the id of the materials, the        *
*            number of the materials and costs per unit. The program should manage every request of the DIY shops and print the total cost of        *  
*            materials.                                                                                                                              *
*  Date : 09/01/2019                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

// -- Libraries --
#include <stdlib.h>
#include <stdio.h>
#include "Introduction.h"
#include "DIYShopsManagement.h"

// -- Main --
int main(void)
{
    int n_shops = 0; //Used to store the number of shops
    deposit_t deposit; //Used to store information about the material in deposit
    float total_cost = 0; //Used to store the cost of all materials

    introduction(); //Used to print the introduction

    n_shops = setNShops(); //Used to set the number of shops

    Shop_t shop[n_shops]; //Used to store information about shops

    setShops(shop, n_shops); //Used to set information about shops
    printf("\n\n");
    getShops(shop, n_shops); //Used to get information about shops

    deposit = setDeposit(); //Used to set information about deposit
    sortMaterialDeposit(deposit.material, deposit.n_material_available); //Used to sort the deposit's material by ID

    manageRequest(shop, n_shops, &deposit, &total_cost); //Used to manage request
    printf("\n\n");
    getDeposit(deposit); //Used to get information about deposit

    if(total_cost != 0) //If none request has been done doesn't show the output
    {
        printf("\n\n\nThe total cost of material is: %.2f€\n", total_cost);
    }
    else
    {
        printf("\n");
    }

    exit(EXIT_SUCCESS);
}