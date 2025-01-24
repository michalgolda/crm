#ifndef TRANSACTIONMANAGMENT_H
#define TRANSACTIONMANAGMENT_H

#include <QWidget>

namespace Ui {
class TransactionManagment;
}

class TransactionManagment : public QWidget
{
    Q_OBJECT

public:
    explicit TransactionManagment(QWidget *parent = nullptr);
    ~TransactionManagment();

private:
    Ui::TransactionManagment *ui;
};

#endif // TRANSACTIONMANAGMENT_H
