#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "loginpage.h"
#include "homepage.h"
#include "pageheader.h"
#include "appstate.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *loginPage = new LoginPage(this);
    homePage = new HomePage(this);

    pageHeader = new PageHeader(homePage);
    pageHeader->move(0, 5);

    ui->stackedWidget->addWidget(loginPage);
    ui->stackedWidget->addWidget(homePage);
    ui->stackedWidget->setCurrentWidget(loginPage);

    connect(loginPage, SIGNAL(loginSuccess()), this, SLOT(onLoginSuccess()));
    connect(loginPage, SIGNAL(loginSuccess()), this, SLOT(onPageHeaderLoad()));
    connect(pageHeader, SIGNAL(logout()), this, SLOT(onLogout()));
    connect(loginPage, SIGNAL(loginSuccess()), this, SLOT(onHomePageLoad()));
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

void MainWindow::onPageHeaderLoad()
{
    pageHeader->load();
}

void MainWindow::onHomePageLoad()
{
    homePage->load();
}
