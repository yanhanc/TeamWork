#include "pattern.h"
#include "ui_pattern.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <search.h>
#include <Qpainter>
#include <QMouseEvent>
#include <QFont>
#include <QPushButton>
#include <algorithm>

#define cout qDebug()
struct student{
    QString num,name;
    QString a[4] = {"0", "0", "0", "0"};
    double score;
};

struct student m[200];
int people;
int t=0;

Pattern::Pattern(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pattern)
{
    ui->setupUi(this);
    this->setWindowTitle("操作栏");
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    this->setFixedSize(1200, 600);
    connect(&cl, &cal::mySignal_ptn,
            [=]()
            {
                this->show();
                cl.hide();
            }
            );

//    QFont font("SimHei", 20, 25);
//    ui->pushButton->setFont(font);
}

Pattern::~Pattern()
{
    delete ui;
}

inline bool cmp(student a, student b) {
    return a.num<b.num;
}

void Pattern::paintEvent(QPaintEvent *e) {
    QPainter p(this);
    p.drawPixmap(rect(), QPixmap(":/new/prefix1/image/ptn_back3.png"));
}
void Pattern::on_pushButton_9_clicked()
{
    emit mySignal_back();
}

void Pattern::on_pushButton_5_clicked()
{
    emit mySignal_add();
}

void Pattern::on_pushButton_2_clicked()
{
    emit mySignal_sch();
}

void Pattern::on_pushButton_6_clicked()
{
    emit mySignal_del();
}

void Pattern::on_pushButton_4_clicked()
{
    emit mySignal_alt();
}

void Pattern::on_pushButton_3_clicked()
{
    qSort(m, m+people, cmp);
    emit mySignal_dpy();
}

void Pattern::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "open", "../");
    if(false == path.isEmpty())
    {
        QFile file;
        file.setFileName(path);

        bool isOk = file.open(QIODevice::ReadOnly);
        if(true == isOk)
        {
            QTextStream stream(&file);
            //指定编码
            stream.setCodec("UTF-8");
            str = stream.readAll();
            //cout << str;
        }
    }
    if(str.size()!=0)
    {
        QMessageBox::information(this, "提示", "导入成功！");
        getdata();
        t=1;
        /*for(int i=0;i<=people;i++)
        {
          qDebug()<<m[i].num<<' '<<m[i].name<<' '<<m[i].a[0]<<' '<<m[i].a[1]<<' '<<m[i].a[1]<<' ';
        }*/
    }
    else QMessageBox::information(this, "提示", "导入错误,请重新输入！");
}


QString Pattern::readStr() {
    return str;
}

void Pattern::getdata()
{
    int  cnt = 0, q=1;
    QString tmp = "";
    for(int i = 0; i <= str.size(); i++)
    {
        if(str[i] == ' '|| str[i] == '\n'|| str[i]=='\0'|| str[i]=='\r')
        {
            if(q){
                if(cnt % 6==0)
                {
                    m[cnt/6].num=tmp;
                }
                else if(cnt % 6==1)
                {
                    m[cnt/6].name=tmp;
                }
                else if(cnt % 6==2)
                {
                    m[cnt/6].a[0]=tmp;
                }
                else if(cnt % 6==3)
                {
                    m[cnt/6].a[1]=tmp;
                }
                else if(cnt % 6==4)
                {
                    m[cnt/6].a[2]=tmp;
                }
                else
                {
                    m[cnt/6].a[3]=tmp;
                }
                tmp = "";
                cnt++;
            }
            q=0;
        }
        else
        {
            q=1;
            tmp+=str[i];
        }
    }
    people=cnt/6;
}

void Pattern::mouseMoveEvent(QMouseEvent *e) {
    if(e->buttons() & Qt::LeftButton) {
        move(e->globalPos() - p);
    }
}

void Pattern::mousePressEvent(QMouseEvent *e) {
    if(e->button() == Qt::LeftButton) {
        p = e->globalPos() - this->frameGeometry().topLeft();
    }
}

void Pattern::on_pushButton_7_released()
{
    QFile file;
    file.setFileName("../成绩单.txt");

    qSort(m, m+people, cmp);
    bool isOk = file.open(QIODevice::WriteOnly);
    if(true == isOk)
    {
        QTextStream stream(&file);
        //指定编码
        stream.setCodec("UTF-8");
        str1.append("学号                           姓名                      个人课设   团队课设    平时成绩    上机测试    最终成绩\r\n");
        str1.append("==========================================================\r\n");
        for(int i = 0;i < people; i++)
        {
            QString ab = QString::number(m[i].score);
            int count;
            str1.append(m[i].num);
            for(int i =0;i < 10;i++) {
                str1.append(" ");
            }
            str1.append(m[i].name);
            count = 30-3*m[i].name.size();
            //cout<<"cnsdocsodicn   "<<m[i].name.size()<<" "<<m[i].name.length();
            /*for(int i=0;i<m[i].name.length();i++)
            {
                if(m[i].name[i] == '·')
                {
                    count -= 2;
                    break;
                }
            }*/
            for(int i =0;i < count;i++) {
                str1.append(" ");
            }
            str1.append(" ");
            str1.append(m[i].a[0]);
            count = 6 - 2 * m[i].a[0].length() + 10;
            for(int i =0;i < count;i++)
                str1.append(" ");
            str1.append(" ");
            str1.append(m[i].a[1]);
            count = 6 - 2 * m[i].a[1].length() + 10;
            for(int i =0;i < count;i++)
                str1.append(" ");
            str1.append(" ");
            str1.append(m[i].a[2]);
            count = 6 - 2 * m[i].a[2].length() + 10;
            for(int i =0;i < count;i++)
                str1.append(" ");
            str1.append(" ");
            str1.append(m[i].a[3]);
            count = 6 - 2 * m[i].a[3].length() + 10;
            for(int i =0;i < count;i++)
                str1.append(" ");
            str1.append(ab);
            str1.append("\r\n");
        }
        str1.append("==========================================================\r\n");
        stream << str1;
        str1.clear();
        file.close();
        QMessageBox::information(this, "提示", "保存成功！");
    }
    else QMessageBox::information(this, "提示", "保存失败！");

}

void Pattern::on_pushButton_8_clicked()
{
    this->hide();
    cl.show();
}
