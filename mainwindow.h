#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "accountmanager.h"

class QPushButton;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openCreateAccountDialog();
    void openDepositDialog();
    void openWithdrawDialog();
    void openTransferDialog();
    void viewAccount();

private:
    AccountManager manager;

    QPushButton *createBtn;
    QPushButton *depositBtn;
    QPushButton *withdrawBtn;
    QPushButton *transferBtn;
    QPushButton *viewBtn;
    QPushButton *exitBtn;
};

#endif
