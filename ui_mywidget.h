/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName("MyWidget");
        MyWidget->resize(900, 700);
        MyWidget->setMinimumSize(QSize(800, 600));
        MyWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #f5f5f5;\n"
"    font-family: \"Microsoft JhengHei\", \"\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224\", Arial, sans-serif;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 8px 20px;\n"
"    text-align: center;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border-radius: 6px;\n"
"    min-width: 80px;\n"
"    min-height: 35px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #45a049;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #3d8b40;\n"
"}\n"
"\n"
"QPushButton#pushButton_3 {\n"
"    background-color: #2196F3;\n"
"}\n"
"\n"
"QPushButton#pushButton_3:hover {\n"
"    background-color: #0b7dda;\n"
"}\n"
"\n"
"QPushButton#pushButton_2 {\n"
"    background-color: #FF9800;\n"
"}\n"
"\n"
"QPushButton#pushButton_2:hover {\n"
"    background-color: #e68900;\n"
"}\n"
"\n"
"QPushButton#pushButton_4 {\n"
"    background-color: #f44336;\n"
"}\n"
"\n"
"QP"
                        "ushButton#pushButton_4:hover {\n"
"    background-color: #da190b;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    padding: 8px;\n"
"    border: 2px solid #ddd;\n"
"    border-radius: 4px;\n"
"    background-color: white;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #4CAF50;\n"
"}\n"
"\n"
"QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #333;\n"
"}\n"
"\n"
"QTableWidget {\n"
"    background-color: white;\n"
"    border: 2px solid #ddd;\n"
"    border-radius: 6px;\n"
"    gridline-color: #e0e0e0;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    padding: 8px;\n"
"    border: none;\n"
"    font-weight: bold;\n"
"    font-size: 14px;\n"
"}"));
        verticalLayout = new QVBoxLayout(MyWidget);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        tableWidget = new QTableWidget(MyWidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setAlternatingRowColors(true);

        verticalLayout->addWidget(tableWidget);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(15);
        formLayout->setVerticalSpacing(12);
        formLayout->setContentsMargins(10, 10, 10, 10);
        label = new QLabel(MyWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(MyWidget);
        lineEdit->setObjectName("lineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_2 = new QLabel(MyWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(MyWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_3 = new QLabel(MyWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEdit_3 = new QLineEdit(MyWidget);
        lineEdit_3->setObjectName("lineEdit_3");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_3);

        label_4 = new QLabel(MyWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        lineEdit_4 = new QLineEdit(MyWidget);
        lineEdit_4->setObjectName("lineEdit_4");

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_4);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(MyWidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_3 = new QPushButton(MyWidget);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout->addWidget(pushButton_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        pushButton_2 = new QPushButton(MyWidget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        pushButton_4 = new QPushButton(MyWidget);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout->addWidget(pushButton_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QCoreApplication::translate("MyWidget", "\351\200\232\350\250\212\351\214\204\347\256\241\347\220\206\347\263\273\347\265\261", nullptr));
        label->setText(QCoreApplication::translate("MyWidget", "\345\255\270\350\231\237:", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit->setToolTip(QCoreApplication::translate("MyWidget", "\350\253\213\350\274\270\345\205\245\345\255\270\350\231\237", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit->setPlaceholderText(QCoreApplication::translate("MyWidget", "\350\253\213\350\274\270\345\205\245\345\255\270\350\231\237", nullptr));
        label_2->setText(QCoreApplication::translate("MyWidget", "\347\217\255\347\264\232:", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_2->setToolTip(QCoreApplication::translate("MyWidget", "\350\253\213\350\274\270\345\205\245\347\217\255\347\264\232", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MyWidget", "\350\253\213\350\274\270\345\205\245\347\217\255\347\264\232", nullptr));
        label_3->setText(QCoreApplication::translate("MyWidget", "\345\247\223\345\220\215:", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_3->setToolTip(QCoreApplication::translate("MyWidget", "\350\253\213\350\274\270\345\205\245\345\247\223\345\220\215", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("MyWidget", "\350\253\213\350\274\270\345\205\245\345\247\223\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("MyWidget", "\351\233\273\350\251\261:", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_4->setToolTip(QCoreApplication::translate("MyWidget", "\350\253\213\350\274\270\345\205\245\351\233\273\350\251\261\350\231\237\347\242\274", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("MyWidget", "\350\253\213\350\274\270\345\205\245\351\233\273\350\251\261\350\231\237\347\242\274", nullptr));
#if QT_CONFIG(tooltip)
        pushButton->setToolTip(QCoreApplication::translate("MyWidget", "\346\226\260\345\242\236\350\201\257\347\265\241\344\272\272\345\210\260\345\210\227\350\241\250", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton->setText(QCoreApplication::translate("MyWidget", "\346\226\260\345\242\236", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_3->setToolTip(QCoreApplication::translate("MyWidget", "\345\276\236\346\252\224\346\241\210\345\214\257\345\205\245\350\201\257\347\265\241\344\272\272\350\263\207\346\226\231", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_3->setText(QCoreApplication::translate("MyWidget", "\345\214\257\345\205\245", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_2->setToolTip(QCoreApplication::translate("MyWidget", "\345\260\207\350\201\257\347\265\241\344\272\272\350\263\207\346\226\231\345\214\257\345\207\272\345\210\260\346\252\224\346\241\210", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_2->setText(QCoreApplication::translate("MyWidget", "\345\214\257\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_4->setToolTip(QCoreApplication::translate("MyWidget", "\345\204\262\345\255\230\344\270\246\347\265\220\346\235\237\347\250\213\345\274\217", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_4->setText(QCoreApplication::translate("MyWidget", "\347\265\220\346\235\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
