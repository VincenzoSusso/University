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
*  Name : DIYShopsManagement.h                                                                                                                          *
*  Purpose : The purpose of this header is to store function prototypes of the program "DIYShopsManagement.c".                                          *
*  Date : 09/01/2019                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

// -- Libraries --
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// -- Constants --
#define MAXSTRING 30 //Maximum size of strings

#define MINSHOP 0 //Minimum number of shops
#define MINIDSHOP 0 //Minimum number of the ID
#define MINMATERIAL 0 //Minimum number of material required

#define MAXMATERIAL 100 //Maximum number of material
#define MINMATERIAL 0 //Minimum number of material
#define MINIDMATERIAL 0 //Minimum number of the ID of material
#define MINPIECES 0 //Minimum number of pieces required
#define MINPRICEPIECE 0.00 //Minimum number of cost per material
 
// -- Data type user defined --
typedef struct
{
     int id_material_required; //Used to store the id of the material
     char material_description[MAXSTRING]; //Used to store a little description of the material
     int n_pieces_required; //Used to store the number of the same material required
} Material_shop_t;

typedef struct
{
     int id_shop; //Used to store the id of the shop
     int n_material_required; //Used to store the number of material that are required
     Material_shop_t material[MAXMATERIAL]; //Used to store information about materials required
} Shop_t;


typedef struct
{
     int id_material; //Used to store the id of the material
     char material_description[MAXSTRING]; //Used to store a little description of the material
     int n_pieces_available; //Used to store the number of the same material required
     float unit_price; //Used to store the price of a unit

} Material_deposit_t;

typedef struct
{
     int n_material_available; //Used to store the id of the shop
     Material_deposit_t material[MAXMATERIAL]; //Used to store information about materials required
} deposit_t;

// -- Functions Prototypes --
int setNShops(void); //Used to set the number of shops
void setShops(Shop_t shop[], const int n_shops); //Used to set information about shops
void getShops(const Shop_t shop[], const int n_shops); //Used to get information about shops

deposit_t setDeposit(void); //Used to set information about deposit
void getDeposit(const deposit_t deposit); //Used to get information about deposit
void sortMaterialDeposit(Material_deposit_t material[], int size); //Used to sort the deposit's material by ID

void manageRequest(const Shop_t shop[], const int n_shops, deposit_t deposit); //Used to manage request

// -- Functions --
int setNShops(void) //Used to set the number of shops
{
     int n_shops = 0;

     do
     {
          printf("\nInsert the number of DIY shops: ");
          scanf("%d", &n_shops);
     }
     while(n_shops < MINSHOP);

     return n_shops;
}

void setShops(Shop_t shop[], const int n_shops) //Used to set information about shops
{
     for(int i = 0; i < n_shops; i++)
     {
          do //Check if the ID is corrected
          {
               printf("\nInsert the ID of the %d^ shop: ", i+1);
               scanf("%d", &shop[i].id_shop);
          }
          while(shop[i].id_shop < MINIDSHOP);

          do //Check if the number of material required is corrected
          {
               printf("Insert the number of material required for the %d^ shop: ", i+1);
               scanf("%d", &shop[i].n_material_required);
          }
          while(shop[i].n_material_required < MINMATERIAL);

          for(int j = 0; j < shop[i].n_material_required; j++)
          {
               do //Check if the ID is corrected
               {
                    printf("Insert the ID of the %d^ material for the %d^ shop: ", j+1, i+1);
                    scanf("%d", &shop[i].material[j].id_material_required);
               }
               while(shop[i].material[j].id_material_required < MINIDMATERIAL);

               printf("Insert a description of the %d^ material for the %d^ shop: ", j+1, i+1); //Input of the description of the material
               scanf("%s", shop[i].material[j].material_description);

               do //Check if the number of pieces required is corrected
               {
                    printf("Insert the number of pieces of %d^ material for the %d^ shop: ", j+1, i+1);
                    scanf("%d", &shop[i].material[j].n_pieces_required);
               }
               while(shop[i].material[j].n_pieces_required < MINPIECES);
          }

          printf("\n");
     }
}

void getShops(const Shop_t shop[], const int n_shops) //Used to get information about shops
{
     for(int i = 0; i < n_shops; i++)
     {
          printf("\n--------------------------------------------");
          printf("\nID of the %d^ shop: %d", i+1, shop[i].id_shop);
          printf("\nThe number of material that the %d^ shop has required is: %d", i+1, shop[i].n_material_required);

          for(int j = 0; j < shop[i].n_material_required; j++)
          {
               printf("\nThe ID of the %d^ material for the %d^ shop is: %d", j+1, i+1, shop[i].material[j].id_material_required);
               printf("\nThe description of the %d^ material for the %d^ shop is: %s", j+1, i+1, shop[i].material[j].material_description);
               printf("\nThe number of pieces of %d^ material for the %d^ shop is: %d", j+1, i+1, shop[i].material[j].n_pieces_required);
          }
          printf("\n--------------------------------------------");
     }     
}

deposit_t setDeposit(void) //Used to set information about deposit
{
     deposit_t deposit;

     do //Check if the number of material is corrected
     {
          printf("\nInsert the number of material that are stored: ");
          scanf("%d", &deposit.n_material_available);
     }
     while(deposit.n_material_available < MINMATERIAL);

     for(int i = 0; i < deposit.n_material_available; i++)
     {
          do //Check if the ID is corrected
          {
               printf("\nInsert the ID of the %d^ material: ", i+1);
               scanf("%d", &deposit.material[i].id_material);
          }
          while(deposit.material[i].id_material < MINIDMATERIAL);

          printf("Insert a description of the %d^ material: ", i+1); //Input of the description of the material
          scanf("%s", deposit.material[i].material_description);

          do //Check if the number of pieces available is corrected
          {
               printf("Insert the number of pieces available of the %d^ material: ", i+1);
               scanf("%d", &deposit.material[i].n_pieces_available);
          }
          while(deposit.material[i].n_pieces_available < MINPIECES);

          do //Check if the price is corrected
          {
               printf("Insert the price per unit of the %d^ material (€): ", i+1);
               scanf("%f", &deposit.material[i].unit_price);
          }
          while(deposit.material[i].unit_price < MINPRICEPIECE);
     }

     return deposit;
}

void getDeposit(const deposit_t deposit) //Used to get information about deposit
{
     printf("\nThe deposit has %d materials", deposit.n_material_available);
     for(int i = 0; i < deposit.n_material_available; i++)
     {
          printf("\n--------------------------------------------");
          
          printf("\nThe ID of the %d^ material is: %d", i+1, deposit.material[i].id_material);
          printf("\nThe description of the %d^ material is: %s", i+1, deposit.material[i].material_description);
          printf("\nThe number of pieces of %d^ material is: %d", i+1, deposit.material[i].n_pieces_available);
          printf("\nThe cost per unit of the %d^ material is: %.2f €", i+1, deposit.material[i].unit_price);

          printf("\n--------------------------------------------");
     }          
}

void sortMaterialDeposit(Material_deposit_t material[], int size) //Used to sort the deposit's material by ID
{
     Material_deposit_t temp; //Used to switch two variable
     int i = 0;
     bool sort = false;

     while((i < size) && (!sort))
     {
          sort = true;
          i++;

          for(int j = 0; j < (size - i); j++)
          {
               if(material[j].id_material > material[j+1].id_material)
               {
                    sort = false; //The array is not sorted

                    temp = material[j];
                    material[j] = material[j+1];
                    material[j+1] = temp;
               }
          }
     }
}

void manageRequest(const Shop_t shop[], const int n_shops, deposit_t deposit) //Used to manage request
{
     for(int i = 0; i < n_shops; i++)
     {
          for(int j = 0; j < shop[i].n_material_required; j++)
          {    
               int first = deposit.material[0].id_material, 
                   last = deposit.material[deposit.n_material_available - 1].id_material, 
                   middle, pos = -1;
               while (first <= last)
               {
                    middle = (first + last) / 2 ;

                    if(middle > shop[i].material[j].id_material_required)
                    {
                         last = middle - 1;
                    }
                    else if(middle < shop[i].material[j].id_material_required)
                    {
                         first = middle + 1;
                    }
                    else
                    {
                         middle = pos;
                    }
               }   

               if (pos != -1)
               {
                    if(deposit.material[pos].n_pieces_available >= shop[i].material[j].n_pieces_required)
                    {
                         printf("\nThe material with ID %d can be sent", shop[i].material[j].id_material_required);
                         
                    }
               }
               else
               {
                    printf("\nThe code %d does not exist!", shop[i].material[j].id_material_required);
               }
          }
     }
}