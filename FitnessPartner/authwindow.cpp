#include "authwindow.h"
#include "ui_authwindow.h"
#include <QMessageBox>
#include <QPixmap>

AuthWindow::AuthWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::AuthWindow) {
    ui->setupUi(this);
    setWindowTitle("Авторизация");
    QPixmap BG(":/authbg/img/authbg.png");
    int w = ui->BG->width();
    int h = ui->BG->width();
    ui->BG->setPixmap(BG.scaled(w,h,Qt::KeepAspectRatio));

}

AuthWindow::~AuthWindow() {
    delete ui;
}


bool AuthWindow::checkCredentials(const QString &login, const QString &password) { // проверка логина и пароля
    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(":");
        if (parts.size() == 2 && parts[0] == login && parts[1] == password) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void AuthWindow::saveCredentials(const QString &login, const QString &password) { // сохранение логина и пароля
    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::critical(this, "Ошибка", "Не удалось создать файл для хранения данных!");
            return;
        }
        file.close();

        if (!file.open(QIODevice::Append | QIODevice::Text)) {
            QMessageBox::critical(this, "Ошибка", "Не удалось сохранить данные!");
            return;
        }
    } else {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(":");
            if (parts.size() >= 1 && parts[0] == login) {
                QMessageBox::warning(this, "Ошибка", "Такой логин уже существует!");
                file.close();
                return;
            }
        }
        file.close();

        if (!file.open(QIODevice::Append | QIODevice::Text)) {
            QMessageBox::critical(this, "Ошибка", "Не удалось сохранить данные!");
            return;
        }
    }


    QTextStream out(&file);
    out << login << ":" << password << "\n";
    file.close();
    QMessageBox::information(this, "Успех", "Регистрация завершена!");
}

void AuthWindow::on_Login_clicked()                                             // слот логина
{
    QString login = ui->loginEdit->text();
    QString password = ui->passwordEdit->text();



    if (login.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Логин и пароль не могут быть пустыми!");
        return;
    }

    if (checkCredentials(login, password)) {
        QMessageBox::information(this, "Успех", "Добро пожаловать!");
        MainWindow *mainWindow = new MainWindow(login);
        mainWindow->show();
        connect(mainWindow, &MainWindow::logoutRequested, this, [this]() {
            this->show();
        });
        this->hide();
        ui->loginEdit->clear();
        ui->passwordEdit->clear();
    } else {
        QMessageBox::critical(this, "Ошибка", "Неверный логин или пароль!");
    }
}


void AuthWindow::on_Register_clicked()                                      //слот регистрации
{
        QString login = ui->loginEdit->text();
        QString password = ui->passwordEdit->text();

        if(login.length() <= 3 || login.length() >= 16 ) {
            QMessageBox::warning(this, "Ошибка", "Логин должен содержать от 4 до 16 символов.");
            return;
        }

        if(password.length() <= 7 || password.length() >= 24 ) {
            QMessageBox::warning(this, "Ошибка", "Пароль должен содержать от 8 до 24 символов.");
            return;
        }


        if (login.isEmpty() || password.isEmpty()) {
            QMessageBox::warning(this, "Ошибка", "Логин и пароль не могут быть пустыми!");
            return;
        }

        saveCredentials(login, password);
    }

