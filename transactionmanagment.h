#ifndef TRANSACTIONMANAGMENT_H
#define TRANSACTIONMANAGMENT_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class TransactionManagment;
}

class TransactionManagment : public QWidget
{
    Q_OBJECT

public:
    explicit TransactionManagment(QWidget *parent = nullptr);
    ~TransactionManagment();

signals:
    void back();

private:
    Ui::TransactionManagment *ui;
    void loadData();
    QStandardItemModel* model;
};

#endif // TRANSACTIONMANAGMENT_H
