#include "transactionmanagment.h"
#include "ui_transactionmanagment.h"

TransactionManagment::TransactionManagment(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TransactionManagment)
{
    ui->setupUi(this);
}

TransactionManagment::~TransactionManagment()
{
    delete ui;
}
