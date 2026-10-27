#include "CardPayment.h"
#include <iostream>
#include <iomanip>
using namespace std;

CardPayment::CardPayment(const string& cardNumber, double commissionPercent) : Payment() {
    setCardNumber(cardNumber);
    setCommissionPercent(commissionPercent);
}

string CardPayment::getCardNumber() const {
    return cardNumber;
}

double CardPayment::getCommissionPercent() const {
    return commissionPercent;
}

void CardPayment::setCardNumber(const string& cardNumber) {
    this->cardNumber = cardNumber;
}

void CardPayment::setCommissionPercent(double commissionPercent) {
    if (commissionPercent < 0) {
        commissionPercent = 0;
    }
    this->commissionPercent = commissionPercent;
}

bool CardPayment::pay(double amount) {
    if (cardNumber.length() != 16) {
        setPaid(false);
        return false;
    }
    double total = amount + amount * commissionPercent / 100.0;
    setAmountDue(total);
    setPaid(true);
    return true;
}

string CardPayment::getType() const {
    return "Банк картасы";
}

void CardPayment::printInfo() const {
    Payment::printInfo();
    cout << fixed << setprecision(2);
    if (cardNumber.length() == 16) {
        cout << "Карта: **** **** **** " << cardNumber.substr(12) << endl;
    }
    cout << "Комиссия: " << commissionPercent << "%" << endl;
}
