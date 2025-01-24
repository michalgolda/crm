#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pageheader.h"
#include "homepage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    PageHeader *pageHeader;
    HomePage *homePage;

private slots:
    void onLoginSuccess();
    void onLogout();
    void onPageHeaderLoad();
    void onHomePageLoad();
};
#endif // MAINWINDOW_H
