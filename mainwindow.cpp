#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "loginpage.h"
#include "homepage.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *loginPage = new LoginPage(this);
    QWidget *homePage = new HomePage(this);

    ui->stackedWidget->addWidget(loginPage);
    ui->stackedWidget->addWidget(homePage);
    ui->stackedWidget->setCurrentWidget(loginPage);

    connect(loginPage, SIGNAL(loginSuccess()), this, SLOT(onLoginSuccess()));
    connect(homePage, SIGNAL(logout()), this, SLOT(onLogout()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLoginSuccess()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::onLogout()
{
    ui->stackedWidget->setCurrentIndex(0);
    QMessageBox::information(this, tr("Informacja"), tr("Zostałeś pomyślnie wylogowany"));
}
