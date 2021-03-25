#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H
#include "Controller.h"
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QListWidgetItem>


namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private slots:

    void on_addBtn_clicked();

    void on_removeBtn_clicked();

    void on_updateBtn_clicked();

    void on_booksList_currentRowChanged(int currentRow);

private:
    Ui::AdminWindow *ui;
    Controller* c;
    Book selectedBook;
    Book* books;
    int bookIndex;
    bool isBookSelected=false;
    QString bookTitle;
};

#endif // ADMINWINDOW_H
