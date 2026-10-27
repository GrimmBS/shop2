#ifndef CARDPAYMENT_H
#define CARDPAYMENT_H

#include "Payment.h"

class CardPayment : public Payment {
private:
    string cardNumber;
    double commissionPercent;

public:
    CardPayment(const string& cardNumber, double commissionPercent);

    string getCardNumber() const;
    double getCommissionPercent() const;
    void setCardNumber(const string& cardNumber);
    void setCommissionPercent(double commissionPercent);

    bool pay(double amount) override;
    string getType() const override;
    void printInfo() const override;
};

#endif
