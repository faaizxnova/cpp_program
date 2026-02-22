
#ifndef MENUWINDOW_H
#define MENUWINDOW_H
#include <QWidget>
class QListWidget;
class QLabel;

class MenuWindow : public QWidget {
    Q_OBJECT
public:
    MenuWindow(QWidget *parent=nullptr);
private slots:
    void addItem();
    void removeItem();
    void placeOrder();
    void cancelOrder();
    void logout();
private:
    QListWidget *menu;
    QListWidget *cart;
    QLabel *bill;
    int total;
};
#endif
