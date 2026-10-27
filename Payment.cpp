#include "Payment.h"
#include <iostream>
#include <iomanip>
using namespace std;

Payment::Payment() : amountDue(0.0), paid(false) {
}

Payment::~Payment() {
}

double Payment::getAmountDue() const {
    return amountDue;
}

bool Payment::isPaid() const {
    return paid;
}

void Payment::setAmountDue(double amountDue) {
    this->amountDue = amountDue;
}

void Payment::setPaid(bool paid) {
    this->paid = paid;
}

bool Payment::pay(double amount) {
    amountDue = amount;
    paid = true;
    return true;
}

string Payment::getType() const {
    return "Жалпы төлем";
}

void Payment::printInfo() const {
    cout << fixed << setprecision(2);
    cout << "Төлем түрі: " << getType() << endl;
    cout << "Төленетін сома: " << amountDue << " тг" << endl;
    cout << "Күйі: " << (paid ? "төленді" : "төленбеді") << endl;
}
