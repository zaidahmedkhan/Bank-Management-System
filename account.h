#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>

class Account {
public:
    Account(const QString &name, int age, const QString &accNumber, double balance);

    QString getName() const;
    int getAge() const;
    QString getAccountNumber() const;
    double getBalance() const;

    void deposit(double amount);
    bool withdraw(double amount);

private:
    QString name;
    int age;
    QString accountNumber;
    double balance;
};

#endif




