#include "addscore.h"
#include "ui_addscore.h"
#include <QMessageBox>
#include <QPainter>
#include <QMouseEvent>

struct student{
    QString num,name;
    QString a[4] = {"0", "0", "0", "0"};
    double score;
};

extern struct student m[200];
extern int t;
extern int people;


AddScore::AddScore(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddScore)
{
    ui->setupUi(this);
    this->setWindowTitle("添加成绩");
    this->setFixedSize(800, 400);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
}

AddScore::~AddScore()
{
    delete ui;
}

void AddScore::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    emit mySignal_ptn();
}

void AddScore::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.drawPixmap(rect(), QPixmap(":/new/prefix1/image/ptn_back.png"));
}

void AddScore::mouseMoveEvent(QMouseEvent *e) {
    if(e->buttons() & Qt::LeftButton) {
        move(e->globalPos() - p);
    }
}

void AddScore::mousePressEvent(QMouseEvent *e) {
    if(e->button() == Qt::LeftButton) {
        p = e->globalPos() - this->frameGeometry().topLeft();
    }
}

void AddScore::on_pushButton_clicked()
{
    QString tmp1=ui->lineEdit_3->text();   //学号
    QString tmp2=ui->lineEdit_2->text();  //科目
    QString tmp3=ui->lineEdit->text();    //成绩
    QString tmp4=ui->lineEdit_4->text();   //姓名
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
        num=people++;
        m[num].num=tmp1;
    }
    bool ok;
    int dec=tmp2.toInt(&ok,10)-1; //dec=255 ; ok=true    //QString 转 int
    m[num].a[dec]=tmp3;
    m[num].name = tmp4;
    QMessageBox::about(this, "操作错误", "添加成功");
}
