/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QCalendarWidget *calendarWidget;
    QTextEdit *notesEdit;
    QPushButton *generateExercisesButton;
    QPushButton *saveButton;
    QPushButton *deleteButton;
    QPushButton *logoutButton;
    QTextBrowser *textBrowser;
    QLabel *BG;
    QPushButton *clearButton;
    QPushButton *moveButton;
    QTextBrowser *textBrowser_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(360, 0, 441, 241));
        notesEdit = new QTextEdit(centralwidget);
        notesEdit->setObjectName(QString::fromUtf8("notesEdit"));
        notesEdit->setGeometry(QRect(360, 260, 441, 341));
        generateExercisesButton = new QPushButton(centralwidget);
        generateExercisesButton->setObjectName(QString::fromUtf8("generateExercisesButton"));
        generateExercisesButton->setGeometry(QRect(0, 20, 361, 41));
        generateExercisesButton->setStyleSheet(QString::fromUtf8(""));
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(0, 60, 361, 41));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(0, 100, 361, 41));
        logoutButton = new QPushButton(centralwidget);
        logoutButton->setObjectName(QString::fromUtf8("logoutButton"));
        logoutButton->setGeometry(QRect(0, 220, 361, 41));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(360, 240, 461, 21));
        BG = new QLabel(centralwidget);
        BG->setObjectName(QString::fromUtf8("BG"));
        BG->setGeometry(QRect(0, 260, 361, 341));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(0, 180, 361, 41));
        moveButton = new QPushButton(centralwidget);
        moveButton->setObjectName(QString::fromUtf8("moveButton"));
        moveButton->setGeometry(QRect(0, 140, 361, 41));
        textBrowser_2 = new QTextBrowser(centralwidget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(0, 0, 361, 31));
        MainWindow->setCentralWidget(centralwidget);
        BG->raise();
        calendarWidget->raise();
        notesEdit->raise();
        generateExercisesButton->raise();
        saveButton->raise();
        deleteButton->raise();
        logoutButton->raise();
        textBrowser->raise();
        clearButton->raise();
        logoutButton->raise();
        clearButton->raise();
        deleteButton->raise();
        saveButton->raise();
        generateExercisesButton->raise();
        moveButton->raise();
        textBrowser_2->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        generateExercisesButton->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\200\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        saveButton->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\200\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\267\320\260\320\275\321\217\321\202\320\270\320\265", nullptr));
        deleteButton->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\275\321\217\321\202\320\270\320\265", nullptr));
        logoutButton->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270 \320\270\320\267 \320\260\320\272\320\272\320\260\321\203\320\275\321\202\320\260", nullptr));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\240\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265 :</p></body></html>", nullptr));
        BG->setText(QString());
        clearButton->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\200\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        moveButton->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270 \320\267\320\260\320\275\321\217\321\202\320\270\320\265 \321\201 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\271 \320\264\320\260\321\202\321\213", nullptr));
        textBrowser_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">FITNESS PARTNER \360\237\230\203\360\237\244\221\360\237\222\252 </span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
