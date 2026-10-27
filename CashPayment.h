#ifndef CASHPAYMENT_H
#define CASHPAYMENT_H

#include "Payment.h"

class CashPayment : public Payment {
private:
    double cashGiven;
    double change;

public:
    CashPayment(double cashGiven);

    double getCashGiven() const;
    double getChange() const;
    void setCashGiven(double cashGiven);

    bool pay(double amount) override;
    string getType() const override;
    void printInfo() const override;
};

#endif
