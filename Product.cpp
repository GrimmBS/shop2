#include "Product.h"
#include <iostream>
#include <iomanip>
using namespace std;

int Product::nextId = 1;

Product::Product() : id(0), name(""), price(0.0), stock(0) {
}

Product::Product(const string& name, double price, int stock) {
    this->id = nextId++;
    this->name = name;
    setPrice(price);
    setStock(stock);
}

int Product::getId() const {
    return id;
}

string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

int Product::getStock() const {
    return stock;
}

void Product::setName(const string& name) {
    this->name = name;
}

void Product::setPrice(double price) {
    if (price < 0) {
        price = 0;
    }
    this->price = price;
}

void Product::setStock(int stock) {
    if (stock < 0) {
        stock = 0;
    }
    this->stock = stock;
}

bool Product::reduceStock(int quantity) {
    if (quantity <= 0 || quantity > stock) {
        return false;
    }
    stock -= quantity;
    return true;
}

void Product::print() const {
    cout << fixed << setprecision(2);
    cout << "ID: " << id << " | " << name << " | " << price
         << " тг | қоймада: " << stock << endl;
}

int Product::getCreatedCount() {
    return nextId - 1;
}
