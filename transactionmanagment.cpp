#include <QMessageBox>
#include <QFile>
#include "transactionmanagment.h"
#include "ui_transactionmanagment.h"

TransactionManagment::TransactionManagment(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TransactionManagment)
{
    ui->setupUi(this);

    model = new QStandardItemModel(this);

    ui->tableView->setModel(model);
    connect(ui->backButton, &QPushButton::clicked, this, [=]{ emit back(); });
    loadData();
}

TransactionManagment::~TransactionManagment()
{
    delete ui;
}

void TransactionManagment::loadData()
{
    model->setHorizontalHeaderLabels({
        "ID Transakcji",
        "Data transakcji",
        "Kwota",
        "Klient",
        "Typ transakcji",
        "Status",
        "Opis",
        "Pracownik",
        "Metoda płatności",
        "Termin płatności",
        "Numer faktury"
    });

    QFile transactionsFile(":/transactions.txt");
    if (transactionsFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&transactionsFile);

        while (!stream.atEnd()) {
            QString line = stream.readLine();
            QStringList values = line.split(';');
            QList<QStandardItem*> items;
            for (const QString& value : values) {
                items.append(new QStandardItem(value));
            }
            model->appendRow(items);
        }

        transactionsFile.close();
    } else {
        QMessageBox::critical(this, tr("Błąd"), tr("Wystąpił nieoczekiwany błąd podczas odczytywania pliku z danymi"));
    }
}
