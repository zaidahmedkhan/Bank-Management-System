#include "transferdialog.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

TransferDialog::TransferDialog(AccountManager *manager, QWidget *parent)
    : QDialog(parent), manager(manager) {
    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(new QLabel("From Account Number:"));
    fromEdit = new QLineEdit;
    layout->addWidget(fromEdit);

    layout->addWidget(new QLabel("To Account Number:"));
    toEdit = new QLineEdit;
    layout->addWidget(toEdit);

    layout->addWidget(new QLabel("Amount to Transfer:"));
    amountEdit = new QLineEdit;
    layout->addWidget(amountEdit);

    QPushButton *transferBtn = new QPushButton("Transfer");
    layout->addWidget(transferBtn);

    connect(transferBtn, &QPushButton::clicked, this, &TransferDialog::transfer);

    setLayout(layout);
    setWindowTitle("Transfer");
}

void TransferDialog::transfer() {
    QString from = fromEdit->text();
    QString to = toEdit->text();
    double amount = amountEdit->text().toDouble();

    Account *fromAcc = manager->findAccount(from);
    Account *toAcc = manager->findAccount(to);

    if (!fromAcc || !toAcc) {
        QMessageBox::warning(this, "Error", "Invalid account number(s).");
        return;
    }

    if (fromAcc->withdraw(amount)) {
        toAcc->deposit(amount);
        QMessageBox::information(this, "Success", "Transfer successful!");
        close();
    } else {
        QMessageBox::warning(this, "Error", "Insufficient funds in sender account.");
    }
}
