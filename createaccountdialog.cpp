#include "createaccountdialog.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

CreateAccountDialog::CreateAccountDialog(QWidget *parent) : QDialog(parent) {
    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(new QLabel("Name:"));
    nameEdit = new QLineEdit;
    layout->addWidget(nameEdit);

    layout->addWidget(new QLabel("Age:"));
    ageEdit = new QLineEdit;
    layout->addWidget(ageEdit);

    layout->addWidget(new QLabel("Account Number:"));
    accNumEdit = new QLineEdit;
    layout->addWidget(accNumEdit);

    layout->addWidget(new QLabel("Initial Balance:"));
    balanceEdit = new QLineEdit;
    layout->addWidget(balanceEdit);

    QPushButton *okBtn = new QPushButton("Create");
    QPushButton *cancelBtn = new QPushButton("Cancel");
    layout->addWidget(okBtn);
    layout->addWidget(cancelBtn);

    connect(okBtn, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelBtn, &QPushButton::clicked, this, &QDialog::reject);

    setLayout(layout);
    setWindowTitle("Create Account");
}

Account CreateAccountDialog::getAccount() const {
    return Account(
        nameEdit->text(),
        ageEdit->text().toInt(),
        accNumEdit->text(),
        balanceEdit->text().toDouble()
        );
}
