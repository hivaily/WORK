/********************************************************************************
** Form generated from reading UI file 'authwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHWINDOW_H
#define UI_AUTHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *loginEdit;
    QLineEdit *passwordEdit;
    QPushButton *Register;
    QPushButton *Login;
    QLabel *BG;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QLabel *logintext;
    QLabel *passtext;
    QLabel *Rtext;

    void setupUi(QMainWindow *AuthWindow)
    {
        if (AuthWindow->objectName().isEmpty())
            AuthWindow->setObjectName(QString::fromUtf8("AuthWindow"));
        AuthWindow->resize(793, 546);
        centralwidget = new QWidget(AuthWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        loginEdit = new QLineEdit(centralwidget);
        loginEdit->setObjectName(QString::fromUtf8("loginEdit"));
        loginEdit->setGeometry(QRect(340, 130, 113, 21));
        passwordEdit = new QLineEdit(centralwidget);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setGeometry(QRect(340, 170, 113, 21));
        Register = new QPushButton(centralwidget);
        Register->setObjectName(QString::fromUtf8("Register"));
        Register->setGeometry(QRect(340, 260, 121, 21));
        Login = new QPushButton(centralwidget);
        Login->setObjectName(QString::fromUtf8("Login"));
        Login->setGeometry(QRect(360, 210, 80, 21));
        BG = new QLabel(centralwidget);
        BG->setObjectName(QString::fromUtf8("BG"));
        BG->setGeometry(QRect(0, 0, 793, 546));
        BG->setPixmap(QPixmap(QString::fromUtf8("authbg.png")));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(260, 101, 261, 191));
        textBrowser_2 = new QTextBrowser(centralwidget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(320, 20, 151, 41));
        logintext = new QLabel(centralwidget);
        logintext->setObjectName(QString::fromUtf8("logintext"));
        logintext->setGeometry(QRect(380, 110, 47, 13));
        passtext = new QLabel(centralwidget);
        passtext->setObjectName(QString::fromUtf8("passtext"));
        passtext->setGeometry(QRect(380, 150, 47, 13));
        Rtext = new QLabel(centralwidget);
        Rtext->setObjectName(QString::fromUtf8("Rtext"));
        Rtext->setGeometry(QRect(310, 240, 181, 16));
        AuthWindow->setCentralWidget(centralwidget);
        BG->raise();
        textBrowser->raise();
        loginEdit->raise();
        passwordEdit->raise();
        Register->raise();
        Login->raise();
        textBrowser_2->raise();
        logintext->raise();
        passtext->raise();
        Rtext->raise();

        retranslateUi(AuthWindow);

        QMetaObject::connectSlotsByName(AuthWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AuthWindow)
    {
        AuthWindow->setWindowTitle(QApplication::translate("AuthWindow", "MainWindow", nullptr));
        Register->setText(QApplication::translate("AuthWindow", "\320\227\320\260\321\200\320\265\320\263\320\265\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        Login->setText(QApplication::translate("AuthWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        BG->setText(QString());
        textBrowser_2->setHtml(QApplication::translate("AuthWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">Fitness Partner</span></p></body></html>", nullptr));
        logintext->setText(QApplication::translate("AuthWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        passtext->setText(QApplication::translate("AuthWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        Rtext->setText(QApplication::translate("AuthWindow", "\320\235\320\265\321\202 \320\260\320\272\320\272\320\260\321\203\320\275\321\202\320\260? \320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\321\203\320\271\321\202\320\265\321\201\321\214.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthWindow: public Ui_AuthWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHWINDOW_H
