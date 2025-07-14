#ifndef CONTACT_H
#define CONTACT_H

#include <QString>
#include <QList>

class Contact
{
public:
    Contact();
    Contact(QString name, QString phone);

    // Basic contact functions
    QString getName() const;
    QString getPhone() const;

    void setName(const QString &name);
    void setPhone(const QString &phone);

    // Static functions for managing contact lists
    static void addContact(QList<Contact> &list, const Contact &contact);
    static void removeContact(QList<Contact> &list, int index);
    static QList<Contact> searchByName(const QList<Contact> &list, const QString &name);

private:
    QString m_name;
    QString m_phone;
};



#endif // CONTACT_H
