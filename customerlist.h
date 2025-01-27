#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include <QWidget>
#include <QStandardItem>

namespace Ui {
class CustomerList;
}

class CustomerList : public QWidget
{
    Q_OBJECT

public:
    explicit CustomerList(QWidget *parent = nullptr);
    ~CustomerList();

signals:
    void back();

private:
    Ui::CustomerList *ui;
    void loadData();
    QStandardItemModel* model;
};

#endif // CUSTOMERLIST_H
