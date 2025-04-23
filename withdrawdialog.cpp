#include "withdrawdialog.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

WithdrawDialog::WithdrawDialog(AccountManager *manager, QWidget *parent)
    : QDialog(parent), manager(manager) {
    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(new QLabel("Account Number:"));
    accNumEdit = new QLineEdit;
    layout->addWidget(accNumEdit);

    layout->addWidget(new QLabel("Amount to Withdraw:"));
    amountEdit = new QLineEdit;
    layout->addWidget(amountEdit);

    QPushButton *withdrawBtn = new QPushButton("Withdraw");
    layout->addWidget(withdrawBtn);

    connect(withdrawBtn, &QPushButton::clicked, this, &WithdrawDialog::withdraw);

    setLayout(layout);
    setWindowTitle("Withdraw");
}

void WithdrawDialog::withdraw() {
    QString accNum = accNumEdit->text();
    double amount = amountEdit->text().toDouble();
    Account *acc = manager->findAccount(accNum);
    if (acc) {
        if (acc->withdraw(amount)) {
            QMessageBox::information(this, "Success", "Withdrawal successful!");
            close();
        } else {
            QMessageBox::warning(this, "Error", "Insufficient funds.");
        }
    } else {
        QMessageBox::warning(this, "Error", "Account not found.");
    }
}
