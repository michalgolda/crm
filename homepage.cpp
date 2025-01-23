#include "homepage.h"
#include "ui_homepage.h"
#include "appstate.h"
#include <QDebug>

HomePage::HomePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomePage)
{
    ui->setupUi(this);

    qDebug() << "Aktualny użytkownik: " << AppState::instance().username;
    // ui->welcome->setText(AppState::instance().username);
}

HomePage::~HomePage()
{
    delete ui;
}
