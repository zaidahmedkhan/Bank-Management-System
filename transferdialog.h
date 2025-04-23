#ifndef TRANSFERDIALOG_H
#define TRANSFERDIALOG_H

#include <QDialog>
#include "accountmanager.h"

class QLineEdit;

class TransferDialog : public QDialog {
    Q_OBJECT

public:
    explicit TransferDialog(AccountManager *manager, QWidget *parent = nullptr);

private slots:
    void transfer();

private:
    AccountManager *manager;
    QLineEdit *fromEdit;
    QLineEdit *toEdit;
    QLineEdit *amountEdit;
};

#endif
