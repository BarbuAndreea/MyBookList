#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"adminwindow.h"
#include"userwindow.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AdminBtn_clicked();

    void on_UserBtn_clicked();

private:
    Ui::MainWindow *ui;
    AdminWindow *adminWindow;
    UserWindow *userWindow;
};
#endif // MAINWINDOW_H
