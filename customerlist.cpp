#include "customerlist.h"
#include "ui_customerlist.h"
#include <QFile>
#include <QStringList>
#include <QMessageBox>

CustomerList::CustomerList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomerList)
{
    ui->setupUi(this);
    model = new QStandardItemModel(this);
    ui->tableView->setModel(model);
    loadData();

    connect(ui->backButton, &QPushButton::clicked, this, [=]{ emit back(); });
}

CustomerList::~CustomerList()
{
    delete ui;
}


void CustomerList::loadData()
{
    model->setHorizontalHeaderLabels({"Imię", "Nazwisko", "Numer telefonu", "E-mail"});

    QFile customersFile(":/customers.txt");
    if (customersFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&customersFile);

        while (!stream.atEnd()) {
            QString line = stream.readLine();
            QStringList values = line.split(' ');
            QList<QStandardItem*> items;
            for (const QString& value : values) {
                items.append(new QStandardItem(value));
            }
            model->appendRow(items);
        }

        customersFile.close();
    } else {
        QMessageBox::critical(this, tr("Błąd"), tr("Wystąpił nieoczekiwany błąd podczas odczytywania pliku z danymi"));
    }
}
