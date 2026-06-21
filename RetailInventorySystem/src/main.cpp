#include <iostream>

#include "../include/product.h"
#include "../include/inventory.h"
#include "../include/order.h"
#include "../include/filehandling.h"

using namespace std;

int main()
{
    loadData();

    if(products.empty())
    {
        initializeProducts();
    }

    int choice;

    do
    {
        cout << "\n========================================";
        cout << "\n PERFUME RETAIL INVENTORY SYSTEM";
        cout << "\n========================================";
        cout << "\n1. Product Management";
        cout << "\n2. Inventory Management";
        cout << "\n3. Customer Orders";
        cout << "\n4. Low Stock Report";
        cout << "\n5. Save Data";
        cout << "\n6. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        while(cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Invalid input! Enter again: ";
            cin >> choice;
        }

        switch(choice)
        {
            case 1:
                productMenu();
                break;

            case 2:
                inventoryMenu();
                break;

            case 3:
                orderMenu();
                break;

            case 4:
                lowStockReport();
                break;

            case 5:
                saveData();
            cout << "\nData saved successfully!";
                break;

            case 6:
                saveData();
            cout << "\nThank you for using the system.\n";
                break;

                default:
            cout << "\nInvalid Choice!";
        }

    } while(choice != 6);

    return 0;
}