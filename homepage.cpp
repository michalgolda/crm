#include "homepage.h"
#include "ui_homepage.h"
#include <QDebug>
#include <QMessageBox>
#include "menu.h"
#include "customerlist.h"
#include "transactionmanagment.h"
#include "appstate.h"

HomePage::HomePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomePage)
{
    ui->setupUi(this);

    QWidget *menu = new Menu();
    QWidget *customerList = new CustomerList();
    QWidget *transactionManagment = new TransactionManagment();

    ui->stackedWidget->addWidget(menu);
    ui->stackedWidget->addWidget(customerList);
    ui->stackedWidget->addWidget(transactionManagment);
    ui->stackedWidget->setCurrentIndex(0);


    connect(menu, SIGNAL(menuButtonClicked(int)), this, SLOT(onMenuButtonClicked(int)));
    connect(customerList, SIGNAL(back()), this, SLOT(onBack()));
    connect(transactionManagment, SIGNAL(back()), this, SLOT(onBack()));
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::onMenuButtonClicked(int pageIndex)
{
    ui->stackedWidget->setCurrentIndex(pageIndex);
}

void HomePage::load()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void HomePage::onBack()
{
    ui->stackedWidget->setCurrentIndex(0);
}
