#include "display.h"
#include "ui_display.h"
#include <QMessageBox>
#include <QDebug>
#include <algorithm>
#include <QFont>
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

inline bool cmp(student a, student b) {
    return a.num<b.num;
}

Display::Display(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Display)
{
    this->setFixedSize(1200, 800);
    ui->setupUi(this);
    qSort(m, m+people, cmp);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
}

Display::~Display()
{
    delete ui;
}

void Display::on_pushButton_2_clicked()
{
    ui->textBrowser->clear();
    emit mySignal_ptn();
}

void Display::setStr(QString s) {
    str_in = s;
}

void Display::on_pushButton_clicked()
{
    ui->textBrowser->clear();
    tt.append("学号                             姓名                  个人课设   团队课设  平时成绩  上机测试     最终成绩\r\n");
    tt.append("=========================================================\r\n");
    for(int i = 0;i < people; i++)
    {
        QString ab = QString::number(m[i].score);
        int count;
        tt.append(m[i].num);
        for(int i =0;i < 10;i++) {
            tt.append(" ");
        }
        tt.append(m[i].name);
        count = 30-4*m[i].name.length();
        //cout<<"cnsdocsodicn   "<<m[i].name.size()<<" "<<m[i].name.length();
//        for(int i=0;i<m[i].name.length();i++)
//        {
//            if(m[i].name[i] == '·')
//            {
//                count += 2;
//                break;
//            }
//        }
        for(int i =0;i < count;i++) {
            tt.append(" ");
        }
        tt.append(" ");
        tt.append(m[i].a[0]);
        count = 6 - 2*m[i].a[0].length() + 10;
        for(int i =0;i < count;i++)
            tt.append(" ");
        tt.append(" ");
        tt.append(m[i].a[1]);
        count = 6 - 2*m[i].a[1].length() + 10;
        for(int i =0;i < count;i++)
            tt.append(" ");
        tt.append(" ");
        tt.append(m[i].a[2]);
        count = 6 - 2*m[i].a[2].length() + 8;
        for(int i =0;i < count;i++)
            tt.append(" ");
        tt.append(" ");
        tt.append(m[i].a[3]);
        count = 6 - 2* m[i].a[3].length()+ 10;
        for(int i =0;i < count;i++)
            tt.append(" ");
        tt.append(" ");
        tt.append(ab);
        tt.append("\r\n");
    }
    tt.append("=========================================================\r\n");
    QFont font("Microsoft YaHei", 15, 75);
    ui->textBrowser->setFont(font);
    ui->textBrowser->setText(tt);
    tt.clear();
}

void Display::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.drawPixmap(rect(), QPixmap(":/new/prefix1/image/add_back.png"));
}

void Display::mouseMoveEvent(QMouseEvent *e) {
    if(e->buttons() & Qt::LeftButton) {
        move(e->globalPos() - p);
    }
}

void Display::mousePressEvent(QMouseEvent *e) {
    if(e->button() == Qt::LeftButton) {
        p = e->globalPos() - this->frameGeometry().topLeft();
    }
}
