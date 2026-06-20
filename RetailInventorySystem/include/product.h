#ifndef PRODUCT_H
#define PRODUCT_H

#include "product.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Product
{
    int id;
    string code;
    string name;
    string category;
    double price;
    int stock;
};

extern vector<Product> products;

void initializeProducts();

void productMenu();

void addProduct();
void updateProduct();
void deleteProduct();
void searchProduct();
void viewAllProducts();

#endif