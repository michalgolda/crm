#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);

    connect(ui->customersListButton, &QPushButton::clicked, this, [=]{ emit menuButtonClicked(1); });
    connect(ui->transactionManagmentButton, &QPushButton::clicked, this, [=]{ emit menuButtonClicked(2); });
}

Menu::~Menu()
{
    delete ui;
}
