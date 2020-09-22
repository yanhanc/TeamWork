#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(900, 500);
    //sch.setParent(&ptn);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    connect(&ptn, &Pattern::mySignal_back,
            [=]() {
                this->show();
                ptn.hide();
            }
            );
    //add
    connect(&ptn, &Pattern::mySignal_add,
            [=]() {
                ads.show();
                ptn.hide();
            }
            );
    connect(&ads, &AddScore::mySignal_ptn,
            [=]() {
                ads.hide();
                ptn.show();
            }
            );
    //sch
    connect(&ptn, &Pattern::mySignal_sch,
            [=]() {
                sch.show();
                ptn.hide();
            }
            );
    connect(&sch, &Search::mySignal_ptn,
            [=]() {
                sch.hide();
                ptn.show();
            }
            );
    //del
    connect(&ptn, &Pattern::mySignal_del,
            [=]() {
                del.show();
                ptn.hide();
            }
            );
    connect(&del, &Delete::mySignal_ptn,
            [=]() {
                del.hide();
                ptn.show();
            }
            );
    //alt
    connect(&ptn, &Pattern::mySignal_alt,
            [=]() {
                alt.show();
                ptn.hide();
            }
            );
    connect(&alt, &Alter::mySignal_ptn,
            [=]() {
                alt.hide();
                ptn.show();
            }
            );
    //dpy
    connect(&ptn, &Pattern::mySignal_dpy,
            [=]() {
            if(ptn.str .size() != false) {
                dpy.setStr(ptn.str);
            }
                dpy.show();
                ptn.hide();
            }
            );
    connect(&dpy, &Display::mySignal_ptn,
            [=]() {
                dpy.hide();
                ptn.show();
            }
            );


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.drawPixmap(rect(), QPixmap(":/new/prefix1/image/cover.png"));
}

void MainWindow::mouseMoveEvent(QMouseEvent *e) {
    if(e->buttons() & Qt::LeftButton) {
        move(e->globalPos() - p);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *e) {
    if(e->button() == Qt::LeftButton) {
        p = e->globalPos() - this->frameGeometry().topLeft();
    }
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    ptn.show();
}
