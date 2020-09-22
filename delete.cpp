#include "delete.h"
#include "ui_delete.h"
#include<QMessageBox>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#define cout qDebug()


struct student{
    QString num,name;
    QString a[4] = {"0", "0", "0", "0"};
    double score;
};

extern struct student m[200];

extern int people;

extern int t;

Delete::Delete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Delete)
{
    ui->setupUi(this);
    this->setWindowTitle("删除成绩");
    this->setFixedSize(800, 400);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
}

Delete::~Delete()
{
    delete ui;
}

void Delete::on_pushButton_clicked()
{
    ui->lineEdit->clear();

    emit mySignal_ptn();
}

void Delete::on_pushButton_2_clicked()
{
    QString tmp1=ui->lineEdit->text();
    int nu=-1;
    for(int i=0;i<people;i++)
    {
        if(m[i].num==tmp1)
        {
            nu=i;
            break;
        }
    }
    if(nu==-1)
    {
        QMessageBox::about(this,QStringLiteral("提醒"),QStringLiteral("查无此人"));
    }
    else{
        for(int i=nu;i<people-1;i++)
        {
            m[i]=m[i+1];
        }
        m[people-1].num="";
        m[people-1].name="";
        m[people-1].a[0]="0";
        m[people-1].a[1]="0";
        m[people-1].a[2]="0";
        m[people-1].a[3]="0";
        m[people-1].score=0;
        people--;
        QMessageBox::about(this,QStringLiteral("提醒"),QStringLiteral("删除成功"));
    }
}


void Delete::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.drawPixmap(rect(), QPixmap(":/new/prefix1/image/template (8).png"));
}

void Delete::mouseMoveEvent(QMouseEvent *e) {
    if(e->buttons() & Qt::LeftButton) {
        move(e->globalPos() - p);
    }
}

void Delete::mousePressEvent(QMouseEvent *e) {
    if(e->button() == Qt::LeftButton) {
        p = e->globalPos() - this->frameGeometry().topLeft();
    }
}
