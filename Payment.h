#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
using namespace std;

class Payment {
private:
    double amountDue;
    bool paid;

public:
    Payment();
    virtual ~Payment();

    double getAmountDue() const;
    bool isPaid() const;

    void setAmountDue(double amountDue);
    void setPaid(bool paid);

    virtual bool pay(double amount);
    virtual string getType() const;
    virtual void printInfo() const;
};

#endif
