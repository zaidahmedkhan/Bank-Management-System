#ifndef CREATEACCOUNTDIALOG_H
#define CREATEACCOUNTDIALOG_H

#include <QDialog>
#include "account.h"

class QLineEdit;

class CreateAccountDialog : public QDialog {
    Q_OBJECT

public:
    explicit CreateAccountDialog(QWidget *parent = nullptr);
    Account getAccount() const;

private:
    QLineEdit *nameEdit;
    QLineEdit *ageEdit;
    QLineEdit *accNumEdit;
    QLineEdit *balanceEdit;
};

#endif
