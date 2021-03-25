#include "userwindow.h"
#include "ui_userwindow.h"
#include "Book.h"
#include "RepoBook.h"
#include "Controller.h"
#include <QtCore>
#include <QtGui>
#include <QListWidgetItem>
UserWindow::UserWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserWindow)
{
    ui->setupUi(this);
    RepoBook* r = new RepoBook(100);
    RepoBook* r2 = new RepoBook(100);
    c = new Controller(r, r2);
    c->loadCtrl();

}

UserWindow::~UserWindow()
{
    delete ui;
}

void UserWindow::on_SearchBtn_clicked()
{
    ui->genreBookList->clear();
    QString search = ui->searchTxt->text();
    books = c->display_genre_b(search.toStdString());
    for (int i=0;i<c->getLength();i++) {
        if(books[i].get_title()!=""){
            QString str = QString::fromUtf8(books[i].get_string().c_str());
            ui->genreBookList->addItem(str);
        }
    }
}


void UserWindow::on_yesBtn_clicked()
{
    c->add_to_listen_list(selectedBook);
    ui->favoriteList->clear();
    Book* fav = c->display_list();
    for(int i=0;i<c->getLengthList();i++){
        QString str = QString::fromUtf8(fav[i].get_string().c_str());
        ui->favoriteList->addItem(str);
    }
}

void UserWindow::on_genreBookList_currentRowChanged(int currentRow)
{
    QString str = QString::fromUtf8(books[currentRow].get_description().c_str());
    selectedBook =books[currentRow];
    ui->descriptionLbl->setText(str);
}

void UserWindow::on_removeButton_clicked()
{
    if(isReadBookSelected){
        c->r_to_listen_list(readBookIndex);
    }
    ui->favoriteList->clear();
    Book* fav = c->display_list();
    for(int i=0;i<c->getLengthList();i++){
        QString str = QString::fromUtf8(fav[i].get_string().c_str());
        ui->favoriteList->addItem(str);
    }
}

void UserWindow::on_favoriteList_currentRowChanged(int currentRow)
{
    isReadBookSelected =true;
    readBookIndex= currentRow;
}
