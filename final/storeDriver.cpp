#include <iostream>
#include "Inventory.h"
#include "Manager.h"
#include "Store.h"

int main()
{
    Store myStore;
    /*
        1. The program will load data from respective text files.
        2. The customer will be prompted to enter their name to see if they already exist in the records.
            -If they dont they  will be added and they will be prompted to add money to the system which is called the "bank" right now but its really just the store account.
            -If they exist they will be welcomed back.
        3. They can look at all the items in the store with prices, or they can search for items and filter by item categories of food, electronics,and clothing.
        4. If they don't find an item they can ask an manager to order it(anything can get ordered)
            -There is a manager account that will take charge of ordering things
            - Customers can come back to the store in n days if they have asked the manager to order something to buy it.
        5.Customers keep loading their cart with items and then they have an option to view their money before buying or to try to buy something.
            -If they view their money and they think its too low they can try to shoplift but have to be careful about being caught by the manager.
                -If they get caught they lose all their money and are banned from the store meaning they cant create an account essentially.
            -If they try to buy without enough money they can remove items from their cart to buy
        6.Customers can leave and the items in their cart get returned to inventory.
        7.After all transactions happen and the customer leaves or after the customer shoplifts the program ends and updates the days the store has been open and updates inventory.

    */
    myStore.~Store();
    return 0;
}