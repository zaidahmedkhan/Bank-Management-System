#include "accountmanager.h"

void AccountManager::addAccount(const Account &account) {
    accounts.append(account);
}

Account *AccountManager::findAccount(const QString &accountNumber) {
    for (Account &acc : accounts) {
        if (acc.getAccountNumber() == accountNumber)
            return &acc;
    }
    return nullptr;
}


