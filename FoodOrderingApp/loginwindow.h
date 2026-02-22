
#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
#include <QWidget>
class QLineEdit;

class LoginWindow : public QWidget {
    Q_OBJECT
public:
    LoginWindow(QWidget *parent = nullptr);
private slots:
    void login();
    void signup();
private:
    QLineEdit *user;
    QLineEdit *pass;
};
#endif
