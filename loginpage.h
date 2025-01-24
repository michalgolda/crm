#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include <QStackedWidget>

namespace Ui {
class LoginPage;
}

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

private:
    Ui::LoginPage *ui;

signals:
    void loginSuccess();

private slots:
    void handleSubmit();
};

#endif // LOGINPAGE_H
