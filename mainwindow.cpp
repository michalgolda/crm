#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "loginpage.h"
#include "homepage.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *loginPage = new LoginPage(ui->stackedWidget, this);
    QWidget *homePage = new HomePage(this);

    ui->stackedWidget->addWidget(loginPage);
    ui->stackedWidget->addWidget(homePage);
    ui->stackedWidget->setCurrentWidget(loginPage);

    connect(loginPage, SIGNAL(loginSuccess()), this, SLOT(onLoginSuccess()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLoginSuccess()
{
    ui->stackedWidget->setCurrentIndex(1);
}
