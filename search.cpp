#include "search.h"
#include "ui_search.h"
#include<QDebug>
#include<QMessageBox>
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

Search::Search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
    this->setWindowTitle("查询成绩");
    this->setFixedSize(1200, 800);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
}

Search::~Search()
{
    delete ui;
}

void Search::on_pushButton_2_clicked()
{
    emit mySignal_ptn();
    ui->textEdit->clear();
}

void Search::on_pushButton_clicked()
{
    QString tmp = ui->lineEdit->text();
    int p=0;
        for(int i=0;i<people;i++)
        {
            if(m[i].num==tmp)
            {
                QString tt="";
                if(ui->textEdit->document()->isEmpty() == true)
                {
                    tt.append("学号                             姓名                  个人课设   团队课设  平时成绩  上机测试     最终成绩\r\n");
                    tt.append("=========================================================\r\n");
                }
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
                QFont font("Microsoft YaHei", 15, 75);
                ui->textEdit->setFont(font);
                ui->textEdit->textCursor().insertText(tt);
                p=1;
            }
        }
     if(!p)
     {
         QMessageBox::about(this,QStringLiteral("提醒"),QStringLiteral("查无此人"));
     }

}


void Search::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.drawPixmap(rect(), QPixmap(":/new/prefix1/image/template (10).png"));
}

void Search::mouseMoveEvent(QMouseEvent *e) {
    if(e->buttons() & Qt::LeftButton) {
        move(e->globalPos() - p);
    }
}

void Search::mousePressEvent(QMouseEvent *e) {
    if(e->button() == Qt::LeftButton) {
        p = e->globalPos() - this->frameGeometry().topLeft();
    }
}
