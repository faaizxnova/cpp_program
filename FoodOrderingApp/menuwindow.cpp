
#include "menuwindow.h"
#include "loginwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <fstream>

MenuWindow::MenuWindow(QWidget *parent) : QWidget(parent), total(0) {
    setWindowTitle("Food Ordering System");
    resize(750, 420);

    menu = new QListWidget;
    cart = new QListWidget;
    bill = new QLabel("Total: ₹0");

    std::ifstream file("menu.dat");
    std::string item;
    int price;
    while (file >> item >> price) {
        menu->addItem(QString::fromStdString(item + " ₹" + std::to_string(price)));
    }

    QPushButton *add = new QPushButton("Add");
    QPushButton *remove = new QPushButton("Remove");
    QPushButton *order = new QPushButton("Place Order");
    QPushButton *cancel = new QPushButton("Cancel Order");
    QPushButton *logoutBtn = new QPushButton("Logout");

    QVBoxLayout *btns = new QVBoxLayout;
    btns->addWidget(add);
    btns->addWidget(remove);
    btns->addWidget(order);
    btns->addWidget(cancel);
    btns->addWidget(logoutBtn);
    btns->addWidget(bill);

    QHBoxLayout *lay = new QHBoxLayout;
    lay->addWidget(menu);
    lay->addLayout(btns);
    lay->addWidget(cart);
    setLayout(lay);

    connect(add, &QPushButton::clicked, this, &MenuWindow::addItem);
    connect(remove, &QPushButton::clicked, this, &MenuWindow::removeItem);
    connect(order, &QPushButton::clicked, this, &MenuWindow::placeOrder);
    connect(cancel, &QPushButton::clicked, this, &MenuWindow::cancelOrder);
    connect(logoutBtn, &QPushButton::clicked, this, &MenuWindow::logout);
}

void MenuWindow::addItem() {
    if (!menu->currentItem()) return;
    QString t = menu->currentItem()->text();
    cart->addItem(t);
    total += t.split("₹")[1].toInt();
    bill->setText("Total: ₹" + QString::number(total));
}

void MenuWindow::removeItem() {
    if (!cart->currentItem()) return;
    QString t = cart->currentItem()->text();
    total -= t.split("₹")[1].toInt();
    delete cart->currentItem();
    bill->setText("Total: ₹" + QString::number(total));
}

void MenuWindow::placeOrder() {
    if (cart->count() == 0) {
        QMessageBox::warning(this, "Empty", "Cart is empty");
        return;
    }

    std::ofstream f("orders.dat", std::ios::app);
    f << "ORDER START\n";
    for (int i = 0; i < cart->count(); i++)
        f << cart->item(i)->text().toStdString() << "\n";
    f << "Total ₹" << total << "\nORDER END\n\n";

    QMessageBox::information(this, "Order Placed", "Order saved successfully");
    // ❌ NOT cancelling automatically anymore
}

void MenuWindow::cancelOrder() {
    cart->clear();
    total = 0;
    bill->setText("Total: ₹0");
    QMessageBox::information(this, "Cancelled", "Order Cancelled");
}

void MenuWindow::logout() {
    LoginWindow *lw = new LoginWindow;
    lw->show();
    close();
}
