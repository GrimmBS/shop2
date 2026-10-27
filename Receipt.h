#ifndef RECEIPT_H
#define RECEIPT_H

#include <string>
using namespace std;

class Receipt {
private:
    class Line {
    private:
        string productName;
        double price;
        int quantity;

    public:
        Line();
        Line(const string& productName, double price, int quantity);

        string getProductName() const;
        double getPrice() const;
        int getQuantity() const;
        double getTotal() const;
    };

    static const int MAX_LINES = 30;
    static int receiptCounter;

    int number;
    Line lines[MAX_LINES];
    int lineCount;

public:
    Receipt();

    bool addLine(const string& productName, double price, int quantity);
    double getTotal() const;
    int getNumber() const;
    int getLineCount() const;

    static int getReceiptCount();

    friend void printReceipt(const Receipt& receipt);
};

void printReceipt(const Receipt& receipt);

#endif
