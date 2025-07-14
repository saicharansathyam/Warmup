#include "contact.h"

Contact::Contact() {}

Contact::Contact(QString name, QString phone)
    : m_name(name), m_phone(phone) {}

QString Contact::getName() const
{
    return m_name;
}

QString Contact::getPhone() const
{
    return m_phone;
}

void Contact::setName(const QString &name)
{
    m_name = name;
}

void Contact::setPhone(const QString &phone)
{
    m_phone = phone;
}

// Static functions for list management
void Contact::addContact(QList<Contact> &list, const Contact &contact)
{
    list.append(contact);
}

void Contact::removeContact(QList<Contact> &list, int index)
{
    if (index >= 0 && index < list.size()) {
        list.removeAt(index);
    }
}

QList<Contact> Contact::searchByName(const QList<Contact> &list, const QString &name)
{
    QList<Contact> result;
    for (const Contact &contact : list) {
        if (contact.getName().contains(name, Qt::CaseInsensitive)) {
            result.append(contact);
        }
    }
    return result;
}

