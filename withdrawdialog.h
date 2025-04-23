#ifndef WITHDRAWDIALOG_H
#define WITHDRAWDIALOG_H

#include <QDialog>
#include "accountmanager.h"

class QLineEdit;

class WithdrawDialog : public QDialog {
    Q_OBJECT

public:
    explicit WithdrawDialog(AccountManager *manager, QWidget *parent = nullptr);

private slots:
    void withdraw();

private:
    AccountManager *manager;
    QLineEdit *accNumEdit;
    QLineEdit *amountEdit;
};

#endif
