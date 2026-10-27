#ifndef CATALOG_H
#define CATALOG_H

#include "Product.h"

class Catalog {
private:
    static const int MAX_PRODUCTS = 50;

    Product products[MAX_PRODUCTS];
    int count;

public:
    Catalog();

    bool addProduct(const Product& product);
    Product* findById(int id);
    int getCount() const;
    void print() const;
};

#endif
