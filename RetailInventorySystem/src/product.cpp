#include "../include/product.h"
#include <iomanip>

string shorten(string text, int length)
{
    if(text.length() > length)
    {
        return text.substr(0, length - 3) + "...";
    }

    return text;
}

vector<Product> products;

void initializeProducts()
{
    if(!products.empty())
        return;

    products.push_back({1,"M001","Dior Sauvage Parfum","Men",7500,20});
    products.push_back({2,"M002","Chanel Bleu de Chanel EDT","Men",7200,20});
    products.push_back({3,"M003","Saint Laurent YSL Y EDP Intense","Men",6900,20});
    products.push_back({4,"M004","Versace Eros","Men",4500,20});
    products.push_back({5,"M005","Acqua di Gio Profumo","Men",5800,20});
    products.push_back({6,"M006","Afnan 9PM","Men",2500,20});
    products.push_back({7,"M007","Lattafa Khamrah","Men",2800,20});
    products.push_back({8,"M008","Versace Dylan Blue","Men",4200,20});
    products.push_back({9,"M009","Prada L'Homme","Men",6500,20});
    products.push_back({10,"M010","Tom Ford Oud Wood","Men",12000,20});
    products.push_back({11,"M011","Creed Aventus","Men",18000,20});
    products.push_back({12,"M012","Jean Paul Gaultier Le Male Elixir","Men",6500,20});
    products.push_back({13,"M013","Montblanc Explorer","Men",3500,20});
    products.push_back({14,"M014","Bvlgari Man in Black","Men",5500,20});
    products.push_back({15,"M015","Clinique Happy for Men","Men",3200,20});

    products.push_back({16,"W001","Chanel Coco Mademoiselle","Women",7800,20});
    products.push_back({17,"W002","Libre Eau de Parfum Yves Saint Laurent","Women",7000,20});
    products.push_back({18,"W003","Good Girl","Women",6500,20});
    products.push_back({19,"W004","La Vie Est Belle","Women",6800,20});
    products.push_back({20,"W005","Dior J'adore Eau de Parfum","Women",7500,20});
    products.push_back({21,"W006","Miss Dior","Women",7200,20});
    products.push_back({22,"W007","YSL Black Opium","Women",6900,20});
    products.push_back({23,"W008","Baccarat Rouge 540","Women",18000,20});
    products.push_back({24,"W009","Valentino Donna Born in Roma","Women",6500,20});
    products.push_back({25,"W010","Burberry Her","Women",6200,20});
    products.push_back({26,"W011","Delina","Women",15000,20});
    products.push_back({27,"W012","Cloud","Women",4500,20});
    products.push_back({28,"W013","Mon Paris","Women",6800,20});
    products.push_back({29,"W014","Eilish No. 2","Women",5200,20});
    products.push_back({30,"W015","Chance Eau Tendre","Women",7500,20});
}

void addProduct()
{
    Product p;

    cout << "\nProduct ID: ";
    cin >> p.id;

    cin.ignore();

    cout << "Product Code: ";
    getline(cin,p.code);

    cout << "Product Name: ";
    getline(cin,p.name);

    cout << "Category: ";
    getline(cin,p.category);

    cout << "Price: ";
    cin >> p.price;

    cout << "Stock: ";
    cin >> p.stock;

    products.push_back(p);

    cout << "\nProduct Added Successfully!";
}

void updateProduct()
{
    int id;

    cout << "\nEnter Product ID: ";
    cin >> id;

    for(auto &p : products)
    {
        if(p.id == id)
        {
            cin.ignore();

            cout << "New Name: ";
            getline(cin,p.name);

            cout << "New Price: ";
            cin >> p.price;

            cout << "New Stock: ";
            cin >> p.stock;

            cout << "\nProduct Updated!";
            return;
        }
    }

    cout << "\nProduct Not Found!";
}

void deleteProduct()
{
    int id;

    cout << "\nEnter Product ID: ";
    cin >> id;

    for(int i=0;i<products.size();i++)
    {
        if(products[i].id == id)
        {
            products.erase(products.begin()+i);
            cout << "\nProduct Deleted!";
            return;
        }
    }

    cout << "\nProduct Not Found!";
}

void searchProduct()
{
    int id;

    cout << "\nEnter Product ID: ";
    cin >> id;

    for(auto p : products)
    {
        if(p.id == id)
        {
            cout << "\nID: " << p.id;
            cout << "\nCode: " << p.code;
            cout << "\nName: " << p.name;
            cout << "\nCategory: " << p.category;
            cout << "\nPrice: PHP " << p.price;
            cout << "\nStock: " << p.stock << endl;
            return;
        }
    }

    cout << "\nProduct Not Found!";
}

void viewAllProducts()
{
    cout << "\n==========================================================================\n";

    cout << left
         << setw(5)  << "ID"
         << setw(10) << "CODE"
         << setw(30) << "PRODUCT"
         << setw(15) << "PRICE"
         << setw(10) << "STOCK"
         << endl;

    cout << "==========================================================================\n";


    for(Product p : products)
    {
        string productName = p.name;

        // putol kapag sobrang haba
        if(productName.length() > 27)
        {
            productName = productName.substr(0,27) + "...";
        }


        cout << left
             << setw(5)  << p.id
             << setw(10) << p.code
             << setw(30) << shorten(p.name, 27)
             << setw(15) << ("PHP " + to_string((int)p.price))
             << setw(10) << p.stock
             << endl;
    }


    cout << "==========================================================================\n";
}

void productMenu()
{
    int choice;

    do
    {
        cout << "\n===== PRODUCT MENU =====\n";
        cout << "1. Add Product\n";
        cout << "2. View Products\n";
        cout << "3. Search Product\n";
        cout << "4. Update Product\n";
        cout << "5. Delete Product\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;


        switch(choice)
        {
            case 1:
                addProduct();
                break;

            case 2:
                viewAllProducts();
                break;

            case 3:
                searchProduct();
                break;

            case 4:
                updateProduct();
                break;

            case 5:
                deleteProduct();
                break;
        }

    }while(choice != 0);
}