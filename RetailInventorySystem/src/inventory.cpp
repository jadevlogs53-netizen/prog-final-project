#include "../include/product.h"
#include "../include/inventory.h"

using namespace std;

void displayInventory()
{
    cout << "\n================================================================================";
    cout << "\nID\tCODE\tPRODUCT NAME\t\t\tCATEGORY\tPRICE\tSTOCK";
    cout << "\n================================================================================";

    for(auto p : products)
    {
        cout << "\n" << p.id
             << "\t" << p.code
             << "\t" << p.name
             << "\t" << p.category
             << "\tPHP " << p.price
             << "\t" << p.stock;
    }

    cout << "\n================================================================================\n";
}

void checkStock()
{
    int id;

    cout << "\nEnter Product ID: ";
    cin >> id;

    for(auto p : products)
    {
        if(p.id == id)
        {
            cout << "\nProduct: " << p.name;
            cout << "\nCurrent Stock: " << p.stock << endl;
            return;
        }
    }

    cout << "\nProduct Not Found!";
}

void updateStock()
{
    int id, quantity;

    cout << "\nEnter Product ID: ";
    cin >> id;

    cout << "Enter Additional Stock: ";
    cin >> quantity;

    for(auto &p : products)
    {
        if(p.id == id)
        {
            p.stock += quantity;

            cout << "\nStock Updated Successfully!";
            cout << "\nNew Stock: " << p.stock << endl;
            return;
        }
    }

    cout << "\nProduct Not Found!";
}

void lowStockReport()
{
    cout << "\nLOW STOCK PRODUCTS";
    cout << "\n------------------";

    bool found = false;

    for(const auto& product : products)
    {
        if(product.stock < 5)
        {
            cout << "\nID: " << product.id;
            cout << "\nName: " << product.name;
            cout << "\nStock: " << product.stock;
            cout << "\n------------------";

            found = true;
        }
    }

    if(!found)
    {
        cout << "\nNo low stock products found.";
    }
}

void inventoryMenu()
{
    int choice;

    do
    {
        cout << "\n========== INVENTORY MENU ==========";
        cout << "\n1. Display Inventory";
        cout << "\n2. Check Product Quantity";
        cout << "\n3. Restock Product";
        cout << "\n4. Back";
        cout << "\nChoice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                displayInventory();
                break;

            case 2:
                checkStock();
                break;

            case 3:
                updateStock();
                break;

            case 4:
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 4);
}