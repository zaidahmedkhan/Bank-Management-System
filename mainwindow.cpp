#include "mainwindow.h"
#include "createaccountdialog.h"
#include "depositdialog.h"
#include "withdrawdialog.h"
#include "transferdialog.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;

    createBtn = new QPushButton("Create Account");
    depositBtn = new QPushButton("Deposit");
    withdrawBtn = new QPushButton("Withdraw");
    transferBtn = new QPushButton("Transfer");
    viewBtn = new QPushButton("View Account");
    exitBtn = new QPushButton("Exit");

    layout->addWidget(createBtn);
    layout->addWidget(depositBtn);
    layout->addWidget(withdrawBtn);
    layout->addWidget(transferBtn);
    layout->addWidget(viewBtn);
    layout->addWidget(exitBtn);

    connect(createBtn, &QPushButton::clicked, this, &MainWindow::openCreateAccountDialog);
    connect(depositBtn, &QPushButton::clicked, this, &MainWindow::openDepositDialog);
    connect(withdrawBtn, &QPushButton::clicked, this, &MainWindow::openWithdrawDialog);
    connect(transferBtn, &QPushButton::clicked, this, &MainWindow::openTransferDialog);
    connect(viewBtn, &QPushButton::clicked, this, &MainWindow::viewAccount);
    connect(exitBtn, &QPushButton::clicked, this, &MainWindow::close);

    central->setLayout(layout);
    setCentralWidget(central);
    setWindowTitle("Bank Management System");
}

MainWindow::~MainWindow() {}

void MainWindow::openCreateAccountDialog() {
    CreateAccountDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        Account account = dialog.getAccount();
        manager.addAccount(account);
        QMessageBox::information(this, "Success", "Account created successfully.");
    }
}

void MainWindow::openDepositDialog() {
    DepositDialog dialog(&manager, this);
    dialog.exec();
}

void MainWindow::openWithdrawDialog() {
    WithdrawDialog dialog(&manager, this);
    dialog.exec();
}

void MainWindow::openTransferDialog() {
    TransferDialog dialog(&manager, this);
    dialog.exec();
}

void MainWindow::viewAccount() {
    QString accNum = QInputDialog::getText(this, "View Account", "Enter Account Number:");
    Account *account = manager.findAccount(accNum);
    if (account) {
        QString info = QString("Name: %1-\nAge: %2\nBalance: %3")
        .arg(account->getName())
            .arg(account->getAge())
            .arg(account->getBalance());
        QMessageBox::information(this, "Account Info", info);
    } else {
        QMessageBox::warning(this, "Error", "Account not found.");
    }
}
