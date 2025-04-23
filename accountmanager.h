#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include "account.h"
#include <QVector>

class AccountManager {
public:
    void addAccount(const Account &account);
    Account *findAccount(const QString &accountNumber);

private:
    QVector<Account> accounts;
};

#endif



