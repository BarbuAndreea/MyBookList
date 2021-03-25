#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "Book.h"
#include "RepoBook.h"
#include "Controller.h"
#include <QtCore>
#include <QtGui>
#include <QListWidgetItem>
#include <QMessageBox>
AdminWindow::AdminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    RepoBook* r = new RepoBook(100);
    RepoBook* r2 = new RepoBook(100);
    c = new Controller(r, r2);
    c->loadCtrl();

    books = c->display_all_b();
    for (int i=0;i<c->getLength();i++) {
        if(books[i].get_title()!=""){
            QString str = QString::fromUtf8(books[i].get_string().c_str());
            ui->booksList->addItem(str);
        }
    }
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_addBtn_clicked()
{
    Book* b = new Book(ui->titleTxt->text().toStdString(), ui->authorTxt->text().toStdString(), ui->genreTxt->text().toStdString(), ui->descriptionTxt->text().toStdString(), ui->coverTxt->text().toStdString(), ui->ageTxt->text().toInt());
    if(c->add_b(*b)==true){
        ui->booksList->clear();
        books = c->display_all_b();
        for (int i=0;i<c->getLength();i++) {
            if(books[i].get_title()!=""){
                QString str = QString::fromUtf8(books[i].get_string().c_str());
                ui->booksList->addItem(str);
            }
        }
    }else{
        //        QMessageBox Msgbox;
        //            Msgbox.setText("Operation failed");
        //            Msgbox.exec();
    }
}

void AdminWindow::on_removeBtn_clicked()
{
    if(isBookSelected){
        c->remove_b(books[bookIndex].get_title());
    }
    ui->booksList->clear();
    books = c->display_all_b();
    for (int i=0;i<c->getLength();i++) {
        if(books[i].get_title()!=""){
            QString str = QString::fromUtf8(books[i].get_string().c_str());
            ui->booksList->addItem(str);
        }
    }
}

void AdminWindow::on_updateBtn_clicked()
{
    try{
        Book* b = new Book(ui->titleTxt->text().toStdString(), ui->authorTxt->text().toStdString(), ui->genreTxt->text().toStdString(), ui->descriptionTxt->text().toStdString(), ui->coverTxt->text().toStdString(), ui->ageTxt->text().toInt());
        c->update_b(*b,bookTitle.toStdString());
    }catch(exception e){

    }
    ui->booksList->clear();
    books = c->display_all_b();
    for (int i=0;i<c->getLength();i++) {
        if(books[i].get_title()!=""){
            QString str = QString::fromUtf8(books[i].get_string().c_str());
            ui->booksList->addItem(str);
        }
    }
}


void AdminWindow::on_booksList_currentRowChanged(int currentRow)
{
    bookIndex=currentRow;
    int year = books[currentRow].get_year();
    bookTitle =QString::fromUtf8(books[currentRow].get_title().c_str());
    ui->titleTxt->setText(QString::fromUtf8(books[currentRow].get_title().c_str()));
    ui->authorTxt->setText(QString::fromUtf8(books[currentRow].get_author().c_str()));
    ui->genreTxt->setText(QString::fromUtf8(books[currentRow].get_genre().c_str()));
    ui->descriptionTxt->setText(QString::fromUtf8(books[currentRow].get_description().c_str()));
    ui->coverTxt->setText(QString::fromUtf8(books[currentRow].get_cover().c_str()));
    ui->ageTxt->setText(QString::number(year));

}
