#include "../include/product.h"
#include "../include/order.h"

using namespace std;

void placeOrder()
{
    int id, quantity;

    cout << "\nEnter Product ID: ";
    cin >> id;

    cout << "Enter Quantity: ";
    cin >> quantity;

    for(auto &p : products)
    {
        if(p.id == id)
        {
            if(quantity > p.stock)
            {
                cout << "\nInsufficient Stock!";
                return;
            }

            double total = quantity * p.price;

            p.stock -= quantity;

            cout << "\n====================================";
            cout << "\n           SALES RECEIPT";
            cout << "\n====================================";
            cout << "\nProduct : " << p.name;
            cout << "\nCode    : " << p.code;
            cout << "\nPrice   : PHP " << p.price;
            cout << "\nQuantity: " << quantity;
            cout << "\n------------------------------------";
            cout << "\nTOTAL   : PHP " << total;
            cout << "\n------------------------------------";
            cout << "\nRemaining Stock: " << p.stock;
            cout << "\n====================================";
            cout << "\nThank you for your purchase!\n";

            return;
        }
    }

    cout << "\nProduct Not Found!";
}

void orderMenu()
{
    int choice;

    do
    {
        cout << "\n========== ORDER MENU ==========";
        cout << "\n1. Place Order";
        cout << "\n2. Back";
        cout << "\nChoice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                placeOrder();
                break;

            case 2:
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 2);
}