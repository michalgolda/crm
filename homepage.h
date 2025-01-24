#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>

namespace Ui {
class HomePage;
}

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();
    void load();

private slots:
    void onMenuButtonClicked(int pageIndex);

private:
    Ui::HomePage *ui;
};

#endif // HOMEPAGE_H
