#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "contact.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addButton_clicked();
    void removeButton_clicked();
    void searchButton_clicked();

private:
    void refreshList(const QList<Contact> &list);

    Ui::MainWindow *ui;
    QList<Contact> contactList;
};

#endif // MAINWINDOW_H
