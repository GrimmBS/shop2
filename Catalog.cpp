#include "Catalog.h"
#include <iostream>
using namespace std;

Catalog::Catalog() : count(0) {
}

bool Catalog::addProduct(const Product& product) {
    if (count >= MAX_PRODUCTS) {
        return false;
    }
    products[count] = product;
    count++;
    return true;
}

Product* Catalog::findById(int id) {
    for (int i = 0; i < count; i++) {
        if (products[i].getId() == id) {
            return &products[i];
        }
    }
    return nullptr;
}

int Catalog::getCount() const {
    return count;
}

void Catalog::print() const {
    cout << "----- Тауарлар каталогы -----" << endl;
    for (int i = 0; i < count; i++) {
        products[i].print();
    }
    cout << "-----------------------------" << endl;
}
