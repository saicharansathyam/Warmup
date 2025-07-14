/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLabel *label;
    QLineEdit *nameEdit;
    QLineEdit *phoneEdit;
    QHBoxLayout *buttonLayout;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *searchButton;
    QLabel *label_2;
    QListWidget *listWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 450);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");

        verticalLayout->addWidget(titleLabel);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        nameEdit = new QLineEdit(centralwidget);
        nameEdit->setObjectName("nameEdit");

        verticalLayout->addWidget(nameEdit);

        phoneEdit = new QLineEdit(centralwidget);
        phoneEdit->setObjectName("phoneEdit");

        verticalLayout->addWidget(phoneEdit);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");

        buttonLayout->addWidget(addButton);

        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName("removeButton");

        buttonLayout->addWidget(removeButton);

        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName("searchButton");

        buttonLayout->addWidget(searchButton);


        verticalLayout->addLayout(buttonLayout);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Simple Phonebook", nullptr));
        titleLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 18px; font-weight: bold; margin: 10px;", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "My Phonebook", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Add New Contact:", nullptr));
        nameEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter name...", nullptr));
        phoneEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter phone...", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Contacts:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
