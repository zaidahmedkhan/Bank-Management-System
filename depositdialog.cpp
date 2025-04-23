#include "depositdialog.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

DepositDialog::DepositDialog(AccountManager *manager, QWidget *parent)
    : QDialog(parent), manager(manager) {
    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(new QLabel("Account Number:"));
    accNumEdit = new QLineEdit;
    layout->addWidget(accNumEdit);

    layout->addWidget(new QLabel("Amount to Deposit:"));
    amountEdit = new QLineEdit;
    layout->addWidget(amountEdit);

    QPushButton *depositBtn = new QPushButton("Deposit");
    layout->addWidget(depositBtn);

    connect(depositBtn, &QPushButton::clicked, this, &DepositDialog::deposit);

    setLayout(layout);
    setWindowTitle("Deposit");
}

void DepositDialog::deposit() {
    QString accNum = accNumEdit->text();
    double amount = amountEdit->text().toDouble();
    Account *acc = manager->findAccount(accNum);
    if (acc) {
        acc->deposit(amount);
        QMessageBox::information(this, "Success", "Deposit successful!");
        close();
    } else {
        QMessageBox::warning(this, "Error", "Account not found.");
    }
}
