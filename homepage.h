#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include "appstate.h"

namespace Ui {
class HomePage;
}

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();

private:
    Ui::HomePage *ui;
    void handleLogout();

signals:
    void logout();
};

#endif // HOMEPAGE_H
