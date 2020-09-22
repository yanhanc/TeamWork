#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pattern.h"
#include "addscore.h"
#include "search.h"
#include "delete.h"
#include "alter.h"
#include "display.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QPoint p;
    Pattern ptn;
    AddScore ads;
    Search sch;
    Delete del;
    Alter alt;
    Display dpy;

};

#endif // MAINWINDOW_H
