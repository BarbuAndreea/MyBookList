#ifndef USERWINDOW_H
#define USERWINDOW_H
#include "Controller.h"
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QListWidgetItem>

namespace Ui {
class UserWindow;
}

class UserWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = nullptr);
    ~UserWindow();

private slots:
    void on_SearchBtn_clicked();

    void on_yesBtn_clicked();

    void on_genreBookList_currentRowChanged(int currentRow);

    void on_removeButton_clicked();

    void on_favoriteList_currentRowChanged(int currentRow);

private:
    Ui::UserWindow *ui;
    Controller* c;
    Book selectedBook;
    Book* books;
    int readBookIndex;
    bool isReadBookSelected = false;
};

#endif // USERWINDOW_H
