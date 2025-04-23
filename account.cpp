#include "account.h"

Account::Account(const QString &name, int age, const QString &accNumber, double balance)
    : name(name), age(age), accountNumber(accNumber), balance(balance) {}

QString Account::getName() const { return name; }
int Account::getAge() const { return age; }
QString Account::getAccountNumber() const { return accountNumber; }
double Account::getBalance() const { return balance; }

void Account::deposit(double amount) {
    if (amount > 0)
        balance += amount;
}

bool Account::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}
