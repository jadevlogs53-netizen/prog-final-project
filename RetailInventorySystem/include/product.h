#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Product {

    int id;
    string code;
    string name;
    string category;
    double price;
    int stock;

    Product()
    {
        id = 0;
        code = "";
        name = "";
        category = "";
        price = 0;
        stock = 0;
    }

    Product(int i, string c, string n, string cat, double p, int s)
    {
        id = i;
        code = c;
        name = n;
        category = cat;
        price = p;
        stock = s;
    }

};


extern vector<Product> products;


void initializeProducts();
void addProduct();
void updateProduct();
void deleteProduct();
void searchProduct();
void viewAllProducts();
void productMenu();


#endif