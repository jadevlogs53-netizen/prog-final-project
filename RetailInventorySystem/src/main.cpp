#include <iostream>

#include "product.h"
#include "inventory.h"
#include "order.h"
#include "filehandling.h"

using namespace std;

int main()
{
    int choice;

    do
    {
        cout << "\n=== Retail Inventory System ===\n";
        cout << "1. Product Management\n";
        cout << "2. Inventory\n";
        cout << "3. Order\n";
        cout << "4. Save Data\n";
        cout << "5. Exit\n";
        cout << "Choice: ";
        cin >> choice;

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
                saveData();
                break;
        }

    } while(choice != 5);

    return 0;
}