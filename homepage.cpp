#include "homepage.h"
#include "ui_homepage.h"
#include "appstate.h"
#include <QDebug>
#include <QMessageBox>

HomePage::HomePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomePage)
{
    ui->setupUi(this);

    connect(ui->logoutButton, &QPushButton::clicked, this, &HomePage::handleLogout);
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::handleLogout()
{
    QMessageBox::StandardButton reply = QMessageBox::question(
        this,
        tr("Potwierdzenie"),
        tr("Czy na pewno chcesz się wylogować?"),
        QMessageBox::Yes | QMessageBox::No
    );

    if (reply == QMessageBox::No)
    {
        return;
    }

    emit logout();
}
