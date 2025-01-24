#include <QDebug>
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include "loginpage.h"
#include "ui_loginpage.h"
#include "appstate.h"

LoginPage::LoginPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);

    connect(ui->submitButton, &QPushButton::clicked, this, &LoginPage::handleSubmit);
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::handleSubmit()
{
    // Wczytanie danych wprowadzonych przez użytkownika
    QString usernameText = ui->usernameLineEdit->text();
    QString passwordText = ui->passwordLineEdit->text();
    if (usernameText.isEmpty() || passwordText.isEmpty())
    {
        QMessageBox::information(this, tr("Informacja"), tr("Wypełnij wymagane pola"));
        return;
    }

    // Wczytanie danych dostępu z pliku
    QString storedUsername;
    QString storedPassword;
    QFile credentialsFile(":/credentials.txt");
    if (credentialsFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&credentialsFile);
        storedUsername = in.readLine();
        storedPassword = in.readLine();
        credentialsFile.close();
    } else {
        QMessageBox::critical(this, tr("Błąd"), tr("Wystąpił nieoczekiwany błąd podczas odczytywania pliku z danymi"));
    }

    //Sprawdzenie poprawności wprowadzonych danych
    if (usernameText != storedUsername || passwordText != storedPassword)
    {
        QMessageBox::information(this, tr("Informacja"), tr("Nieprawidłowa nazwa użytkownika lub hasło"));
        return;
    }

    AppState::instance().set("currentUser", storedUsername);
    emit loginSuccess();
}
