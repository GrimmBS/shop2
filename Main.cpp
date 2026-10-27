#include <iostream>
#include <iomanip>
#include "Catalog.h"
#include "Sale.h"
#include "CashPayment.h"
#include "CardPayment.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "");

    Catalog catalog;
    catalog.addProduct(Product("Сүт", 650, 20));
    catalog.addProduct(Product("Нан", 150, 30));
    catalog.addProduct(Product("Шай", 1200, 10));
    catalog.addProduct(Product("Шоколад", 900, 15));
    catalog.addProduct(Product("Су", 300, 40));

    catalog.print();
    cout << "Жасалған тауарлар саны: " << Product::getCreatedCount() << endl;

    cout << "\n=== 1-сату: қолма-қол ақша ===" << endl;
    Sale sale1(&catalog);
    sale1.addItem(1, 2);
    sale1.addItem(2, 3);
    sale1.addItem(3, 1);
    sale1.addItem(99, 1);
    sale1.addItem(4, 100);

    CashPayment cashSmall(1000);
    sale1.pay(&cashSmall);

    CashPayment cash(3000);
    sale1.pay(&cash);
    sale1.showReceipt();

    cout << "\n=== 2-сату: банк картасы ===" << endl;
    Sale sale2(&catalog);
    sale2.addItem(4, 2);
    sale2.addItem(5, 4);

    CardPayment card("1234567812345678", 1.5);
    sale2.pay(&card);
    sale2.showReceipt();

    cout << "\n=== Полиморфизм: Payment* массиві ===" << endl;
    Payment* payments[2] = {&cash, &card};
    for (int i = 0; i < 2; i++) {
        cout << i + 1 << ") " << payments[i]->getType() << endl;
        payments[i]->printInfo();
    }

    cout << "\n=== Сатудан кейін каталог ===" << endl;
    catalog.print();

    cout << "\nЖасалған чектер саны: " << Receipt::getReceiptCount() << endl;
    cout << fixed << setprecision(2);
    cout << "Жалпы түсім: " << Sale::getTotalRevenue() << " тг" << endl;

    return 0;
}
