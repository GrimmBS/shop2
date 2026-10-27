#ifndef SALE_H
#define SALE_H

#include "Catalog.h"
#include "Receipt.h"
#include "Payment.h"

class Sale {
private:
    Catalog* catalog;
    Receipt receipt;
    Payment* payment;
    bool completed;

    static double totalRevenue;

public:
    Sale(Catalog* catalog);

    bool addItem(int productId, int quantity);
    bool pay(Payment* payment);
    void showReceipt() const;

    bool isCompleted() const;
    const Receipt& getReceipt() const;

    static double getTotalRevenue();
};

#endif
