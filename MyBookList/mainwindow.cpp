#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AdminBtn_clicked()
{
    hide();
    adminWindow = new AdminWindow(this);
    adminWindow->show();
}

void MainWindow::on_UserBtn_clicked()
{
    hide();
    userWindow = new UserWindow(this);
    userWindow->show();
}
