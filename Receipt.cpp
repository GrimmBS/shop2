#include "Receipt.h"
#include <iostream>
#include <iomanip>
using namespace std;

int Receipt::receiptCounter = 0;

Receipt::Line::Line() : productName(""), price(0.0), quantity(0) {
}

Receipt::Line::Line(const string& productName, double price, int quantity) {
    this->productName = productName;
    this->price = price;
    this->quantity = quantity;
}

string Receipt::Line::getProductName() const {
    return productName;
}

double Receipt::Line::getPrice() const {
    return price;
}

int Receipt::Line::getQuantity() const {
    return quantity;
}

double Receipt::Line::getTotal() const {
    return price * quantity;
}

Receipt::Receipt() : lineCount(0) {
    receiptCounter++;
    number = receiptCounter;
}

bool Receipt::addLine(const string& productName, double price, int quantity) {
    if (lineCount >= MAX_LINES || quantity <= 0) {
        return false;
    }
    lines[lineCount] = Line(productName, price, quantity);
    lineCount++;
    return true;
}

double Receipt::getTotal() const {
    double total = 0.0;
    for (int i = 0; i < lineCount; i++) {
        total += lines[i].getTotal();
    }
    return total;
}

int Receipt::getNumber() const {
    return number;
}

int Receipt::getLineCount() const {
    return lineCount;
}

int Receipt::getReceiptCount() {
    return receiptCounter;
}

void printReceipt(const Receipt& receipt) {
    cout << fixed << setprecision(2);
    cout << "========== ЧЕК №" << receipt.number << " ==========" << endl;
    for (int i = 0; i < receipt.lineCount; i++) {
        cout << i + 1 << ". " << receipt.lines[i].getProductName()
             << " | " << receipt.lines[i].getPrice()
             << " x " << receipt.lines[i].getQuantity()
             << " = " << receipt.lines[i].getTotal() << " тг" << endl;
    }
    cout << "Жиыны: " << receipt.getTotal() << " тг" << endl;
    cout << "===============================" << endl;
}
