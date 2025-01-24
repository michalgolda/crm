#ifndef PAGEHEADER_H
#define PAGEHEADER_H

#include <QWidget>

namespace Ui {
class PageHeader;
}

class PageHeader : public QWidget
{
    Q_OBJECT

public:
    explicit PageHeader(QWidget *parent = nullptr);
    ~PageHeader();
    void load();

private:
    Ui::PageHeader *ui;
    void handleLogout();
signals:
    void logout();
};

#endif // PAGEHEADER_H
