#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AuthWindow; }
QT_END_NAMESPACE

class AuthWindow : public QMainWindow {
    Q_OBJECT

public:
    AuthWindow(QWidget *parent = nullptr);
    ~AuthWindow();

private slots:
    void on_Login_clicked();
    void on_Register_clicked();

private:
    Ui::AuthWindow *ui;
    bool checkCredentials(const QString &login, const QString &password);
    void saveCredentials(const QString &login, const QString &password);
};

#endif // AUTHWINDOW_H
