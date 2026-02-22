#include "loginwindow.h"
#include "menuwindow.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <fstream>

LoginWindow::LoginWindow(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Food Ordering - Login");

    user = new QLineEdit;
    user->setPlaceholderText("Username");

    pass = new QLineEdit;
    pass->setPlaceholderText("Password");
    pass->setEchoMode(QLineEdit::Password);

    QPushButton *loginBtn = new QPushButton("Login");
    QPushButton *signupBtn = new QPushButton("Sign Up");

    QVBoxLayout *lay = new QVBoxLayout;
    lay->addWidget(user);
    lay->addWidget(pass);
    lay->addWidget(loginBtn);
    lay->addWidget(signupBtn);
    setLayout(lay);

    connect(loginBtn, &QPushButton::clicked, this, &LoginWindow::login);
    connect(signupBtn, &QPushButton::clicked, this, &LoginWindow::signup);
}

void LoginWindow::signup() {
    std::ofstream file("users.dat", std::ios::app);
    file << user->text().toStdString() << " "
         << pass->text().toStdString() << "\n";
    QMessageBox::information(this, "Success", "User Registered");
}

void LoginWindow::login() {
    std::ifstream file("users.dat");
    std::string u, p;
    while (file >> u >> p) {
        if (u == user->text().toStdString() &&
            p == pass->text().toStdString()) {
            MenuWindow *mw = new MenuWindow;
            mw->show();
            close();
            return;
        }
    }
    QMessageBox::warning(this, "Error", "Invalid Login");
}
