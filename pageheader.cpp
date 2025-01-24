#include "pageheader.h"
#include "ui_pageheader.h"
#include <QMessageBox>
#include "appstate.h"

PageHeader::PageHeader(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PageHeader)
{
    ui->setupUi(this);

    connect(ui->logoutButton, &QPushButton::clicked, this, &PageHeader::handleLogout);
}

PageHeader::~PageHeader()
{
    delete ui;
}

void PageHeader::handleLogout()
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

void PageHeader::load()
{
    QString currentUsername = AppState::instance().get("currentUser").toString();
    ui->currentUserLabel->setText(currentUsername);
}
