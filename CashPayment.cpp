#include "CashPayment.h"
#include <iostream>
#include <iomanip>
using namespace std;

CashPayment::CashPayment(double cashGiven) : Payment(), change(0.0) {
    setCashGiven(cashGiven);
}

double CashPayment::getCashGiven() const {
    return cashGiven;
}

double CashPayment::getChange() const {
    return change;
}

void CashPayment::setCashGiven(double cashGiven) {
    if (cashGiven < 0) {
        cashGiven = 0;
    }
    this->cashGiven = cashGiven;
}

bool CashPayment::pay(double amount) {
    setAmountDue(amount);
    if (cashGiven < amount) {
        setPaid(false);
        return false;
    }
    change = cashGiven - amount;
    setPaid(true);
    return true;
}

string CashPayment::getType() const {
    return "Қолма-қол ақша";
}

void CashPayment::printInfo() const {
    Payment::printInfo();
    cout << fixed << setprecision(2);
    cout << "Берілген ақша: " << cashGiven << " тг" << endl;
    cout << "Қайтарым: " << change << " тг" << endl;
}
