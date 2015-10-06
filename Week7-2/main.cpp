/******************************************************************************
 Week 7 - Assignment 2
 Cash Register
 CISS 242-B
 
 <description>  This program will present the user with a list of products
                available for purchase, then ask the use which item they
                would like to purchase. Next the program will ask the quantity
                desired, then output the subtotal, tax, and total price. The
                program will then ask the user if they would like to make
                another selection.
 
 <author> John Carty
 <date> 4 - Oct - 2015
 <revision> NONE
 
 ******************************************************************************/

#include <iostream>
#include <iomanip>
#include "InventoryItem.h"
#include "CashRegister.h"

const int SIZE = 5;

using namespace std;

int main() {
    int selection = 0,
        qty = 0;
    char cont;
    
    InventoryItem items[]{
        InventoryItem("Adjustable Wrench", 6.99, 10),
        InventoryItem("Screwdriver", 8.99, 20),
        InventoryItem("Pliers", 7.99, 35),
        InventoryItem("Ratchet", 5.99, 10),
        InventoryItem("Socket Wrench", 6.99, 7)
    };
    
    CashRegister checkout;
    
    //Output the menu options
    do{
        cout << setw(5) << left << "#" << setw(30) << "Item" << setw(8) << "Quantity" << endl;
        cout << "--------------------------------------------" << endl;
        for (int i = 0; i < SIZE; i++) {
            cout << setw(5) << left << i+1 << setw(30) << items[i].getDescription() << setw(8) << items[i].getUnits() << endl;
        }
        do{
            //ask the user their selection and validate
            cout << "Which item would you like to purchse? ";
            cin >> selection;
            if (selection < 0 || selection > SIZE) {
                cout << "Please make a valid selection!" << endl;
            }
        }while (selection < 0 || selection > SIZE);
        selection--;
        do{
            //ask the user for the quantity and validate
            cout << "Please enter the quantity you would like to purchse (max " << items[selection].getUnits() << "): ";
            cin >> qty;
            if (qty < 0 || qty > items[selection].getUnits()) {
                cout << "Please make a valid selection!" << endl;
            }
        }while (qty < 0 || qty > items[selection].getUnits());
        
        //output the subtoal, tax, and total
        checkout.setFields(items[selection].getCost(), qty);
        cout << setprecision(2) << fixed << "Subtotal $" << checkout.getSubtotal() << endl << "Tax: $" <<checkout.getTax();
        cout << endl << "Total: $" << checkout.getTotal() << endl;
        items[selection].adjustUnits(qty);
        
        cout << "Press Y to make another selection, any other key to end: ";
        cin >> cont;
        
    }while (cont == 'y' || cont == 'Y');
    
    
    return 0;
}
