#include "Sale.h"
#include <iostream>
#include <iomanip>
using namespace std;

double Sale::totalRevenue = 0.0;

Sale::Sale(Catalog* catalog) {
    this->catalog = catalog;
    this->payment = nullptr;
    this->completed = false;
}

bool Sale::addItem(int productId, int quantity) {
    if (completed) {
        cout << "Қате: сату аяқталған, жаңа тауар қосуға болмайды." << endl;
        return false;
    }

    Product* product = catalog->findById(productId);
    if (product == nullptr) {
        cout << "Қате: ID " << productId << " бойынша тауар табылмады." << endl;
        return false;
    }

    if (!product->reduceStock(quantity)) {
        cout << "Қате: \"" << product->getName() << "\" тауары қоймада жеткіліксіз." << endl;
        return false;
    }

    if (!receipt.addLine(product->getName(), product->getPrice(), quantity)) {
        product->setStock(product->getStock() + quantity);
        cout << "Қате: чекке жол қосу мүмкін емес." << endl;
        return false;
    }
    return true;
}

bool Sale::pay(Payment* payment) {
    if (completed) {
        cout << "Қате: бұл сату бұрын төленген." << endl;
        return false;
    }

    double total = receipt.getTotal();
    if (total <= 0) {
        cout << "Қате: чек бос." << endl;
        return false;
    }

    if (!payment->pay(total)) {
        cout << "Төлем өтпеді." << endl;
        return false;
    }

    this->payment = payment;
    this->completed = true;
    totalRevenue += total;
    return true;
}

void Sale::showReceipt() const {
    printReceipt(receipt);
    if (payment != nullptr) {
        payment->printInfo();
    }
}

bool Sale::isCompleted() const {
    return completed;
}

const Receipt& Sale::getReceipt() const {
    return receipt;
}

double Sale::getTotalRevenue() {
    return totalRevenue;
}
