#include "alter.h"
#include "ui_alter.h"
#include<QMessageBox>
#include <QPainter>
#include <QMouseEvent>



struct student{
    QString num,name;
    QString a[4] = {"0", "0", "0", "0"};
    double score;
};

extern struct student m[200];

extern int people;
extern int t;

Alter::Alter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Alter)
{
    ui->setupUi(this);
    this->setWindowTitle("修改成绩");
    this->setFixedSize(800, 400);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

}

Alter::~Alter()
{
    delete ui;
}

void Alter::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    emit mySignal_ptn();
}

void Alter::on_pushButton_clicked()
{
    QString tmp1=ui->lineEdit->text();   //学号
    QString tmp2=ui->lineEdit_2->text();  //科目
    QString tmp3=ui->lineEdit_3->text();    //需要修改的分数
    int num=-1;
    for(int i=0;i<people;i++)
    {
        if(m[i].num==tmp1)
        {
           num=i;
        }
    }
    if(num==-1)
    {
        QMessageBox::about(this,QStringLiteral("提醒"),QStringLiteral("查无此人"));
    }
    else{
        bool ok;
        int dec=tmp2.toInt(&ok,10)-1; //dec=255 ; ok=true    //QString 转 int
        m[num].a[dec]=tmp3;
        QMessageBox::about(this,QStringLiteral("提醒"),QStringLiteral("修改成功"));
    }
}

void Alter::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.drawPixmap(rect(), QPixmap(":/new/prefix1/image/template (6).png"));
}

void Alter::mouseMoveEvent(QMouseEvent *e) {
    if(e->buttons() & Qt::LeftButton) {
        move(e->globalPos() - p);
    }
}

void Alter::mousePressEvent(QMouseEvent *e) {
    if(e->button() == Qt::LeftButton) {
        p = e->globalPos() - this->frameGeometry().topLeft();
    }
}
