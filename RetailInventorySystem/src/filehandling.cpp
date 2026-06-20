#include "../include/product.h"
#include "../include/filehandling.h"

#include <fstream>

using namespace std;

void saveData()
{
    ofstream file("inventory.txt");

    if(!file)
    {
        cout << "\nError Saving File!";
        return;
    }

    for(auto p : products)
    {
        file << p.id << "|"
             << p.code << "|"
             << p.name << "|"
             << p.category << "|"
             << p.price << "|"
             << p.stock << endl;
    }

    file.close();

    cout << "\nInventory Saved Successfully!";
}

void loadData()
{
    ifstream file("inventory.txt");

    if(!file)
    {
        return;
    }

    products.clear();

    Product p;
    string temp;

    while(getline(file,temp,'|'))
    {
        p.id = stoi(temp);

        getline(file,p.code,'|');
        getline(file,p.name,'|');
        getline(file,p.category,'|');

        getline(file,temp,'|');
        p.price = stod(temp);

        getline(file,temp);
        p.stock = stoi(temp);

        products.push_back(p);
    }

    file.close();
}