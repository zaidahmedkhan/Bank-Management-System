#ifndef DEPOSITDIALOG_H
#define DEPOSITDIALOG_H

#include <QDialog>
#include "accountmanager.h"

class QLineEdit;

class DepositDialog : public QDialog {
    Q_OBJECT

public:
    explicit DepositDialog(AccountManager *manager, QWidget *parent = nullptr);

private slots:
    void deposit();

private:
    AccountManager *manager;
    QLineEdit *accNumEdit;
    QLineEdit *amountEdit;
};

#endif
