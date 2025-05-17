/********************************************************************************
** Form generated from reading UI file 'difficultydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFFICULTYDIALOG_H
#define UI_DIFFICULTYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DifficultyDialog
{
public:
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *level1Button;
    QPushButton *level2Button;
    QPushButton *level3Button;
    QPushButton *level4Button;

    void setupUi(QDialog *DifficultyDialog)
    {
        if (DifficultyDialog->objectName().isEmpty())
            DifficultyDialog->setObjectName(QString::fromUtf8("DifficultyDialog"));
        DifficultyDialog->resize(400, 300);
        textBrowser = new QTextBrowser(DifficultyDialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(130, 10, 141, 31));
        textBrowser_2 = new QTextBrowser(DifficultyDialog);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(30, 130, 341, 121));
        widget = new QWidget(DifficultyDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 50, 341, 23));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        level1Button = new QPushButton(widget);
        level1Button->setObjectName(QString::fromUtf8("level1Button"));

        horizontalLayout->addWidget(level1Button);

        level2Button = new QPushButton(widget);
        level2Button->setObjectName(QString::fromUtf8("level2Button"));

        horizontalLayout->addWidget(level2Button);

        level3Button = new QPushButton(widget);
        level3Button->setObjectName(QString::fromUtf8("level3Button"));

        horizontalLayout->addWidget(level3Button);

        level4Button = new QPushButton(widget);
        level4Button->setObjectName(QString::fromUtf8("level4Button"));

        horizontalLayout->addWidget(level4Button);


        retranslateUi(DifficultyDialog);

        QMetaObject::connectSlotsByName(DifficultyDialog);
    } // setupUi

    void retranslateUi(QDialog *DifficultyDialog)
    {
        DifficultyDialog->setWindowTitle(QApplication::translate("DifficultyDialog", "Dialog", nullptr));
        textBrowser->setHtml(QApplication::translate("DifficultyDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\320\222\321\213\320\261\320\276\321\200 \321\201\320\273\320\276\320\266\320\275\320\276\321\201\321\202\320\270 </span></p></body></html>", nullptr));
        textBrowser_2->setHtml(QApplication::translate("DifficultyDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\320\237\320\276\320\264\321\201\320\272\320\260\320\267\320\272\320\260 : \320\276\321\202 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\271 \321\201\320\273\320\276\320\266\320\275\320\276\321\201\321\202\320\270 \320\261\321\203\320\264\320\265\321\202 \320\267\320\260\320\262\320\270\321\201\320\265\321\202\321\214 \320\270\320\275\321\202\320\265\320\275\321\201\320\270\320\262\320\275\320\276\321\201\321\202\321\214 \321\202\321\200\320\265\320\275\320\270\321\200\320\276\320\262\320\276\320\272"
                        " (\320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\203\320\277\321\200\320\260\320\266\320\275\320\265\320\275\320\270\320\271, \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\267\320\260\320\275\321\217\321\202\320\270\320\271, \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\277\320\276\320\264\321\205\320\276\320\264\320\276\320\262)<br /><br />\320\224\320\265\320\273\320\260\320\271\321\202\320\265 \320\262\321\213\320\261\320\276\321\200 \321\201 \320\276\321\201\321\202\320\276\321\200\320\276\320\266\320\275\320\276\321\201\321\202\321\214\321\216, \320\265\321\201\320\273\320\270 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\260\321\217 \321\201\320\273\320\276\320\266\320\275\320\276\321\201\321\202\321\214 \320\261\321\203\320\264\320\265\321\202 \320\264\320\273\321\217 \320\262\320\260\321\201 \321\201\320\273\320\270\321\210\320\272\320\276\320\274 \320\270\320\275\321\202"
                        "\320\265\320\275\321\201\320\270\320\262\320\275\320\276\320\271, \320\262\321\213 \320\262\321\201\320\265\320\263\320\264\320\260 \320\274\320\276\320\266\320\265\321\202\320\265 \321\201\320\276\320\267\320\264\320\260\321\202\321\214 \320\275\320\276\320\262\320\276\320\265 \321\200\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \321\201 \320\274\320\265\320\275\321\214\321\210\320\265\320\271 \321\201\320\273\320\276\320\266\320\275\320\276\321\201\321\202\321\214\321\216. </span></p></body></html>", nullptr));
        level1Button->setText(QApplication::translate("DifficultyDialog", "\320\233\321\221\320\263\320\272\320\260\321\217", nullptr));
        level2Button->setText(QApplication::translate("DifficultyDialog", "\320\241\321\200\320\265\320\264\320\275\321\217\321\217", nullptr));
        level3Button->setText(QApplication::translate("DifficultyDialog", "\320\241\320\273\320\276\320\266\320\275\320\260\321\217", nullptr));
        level4Button->setText(QApplication::translate("DifficultyDialog", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DifficultyDialog: public Ui_DifficultyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFICULTYDIALOG_H
