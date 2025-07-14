#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Manual connections
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addButton_clicked);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::removeButton_clicked);
    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::searchButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addButton_clicked()
{
    Contact c(
        ui->nameEdit->text(),
        ui->phoneEdit->text()
        );
    Contact::addContact(contactList, c);
    refreshList(contactList);
}

void MainWindow::removeButton_clicked()
{
    int row = ui->listWidget->currentRow();
    if (row >= 0) {
        Contact::removeContact(contactList, row);
        refreshList(contactList);
    }
}

void MainWindow::searchButton_clicked()
{
    QString keyword = ui->nameEdit->text();
    QList<Contact> result = Contact::searchByName(contactList, keyword);
    refreshList(result);
}

void MainWindow::refreshList(const QList<Contact> &list)
{
    ui->listWidget->clear();
    for (const Contact &c : list) {
        ui->listWidget->addItem(c.getName() + " | " + c.getPhone());
    }
}
