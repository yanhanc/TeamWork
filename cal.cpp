#include "cal.h"
#include "ui_cal.h"
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

extern bool cmp1(student a, student b) {
    return a.score>b.score;
}

cal::cal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cal)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
//    百分比
//    四个人数和百分比
//    均分
//    综测排名
    this->setFixedSize(1200, 800);


}

cal::~cal()
{
    delete ui;
}

void cal::on_pushButton_6_clicked()
{
    emit mySignal_ptn();
}

void cal::on_pushButton_5_clicked()
{
    ui->textBrowser->clear();
    QString tmp1=ui->lineEdit->text();
    QString tmp2=ui->lineEdit_2->text();
    QString tmp3=ui->lineEdit_3->text();
    QString tmp4=ui->lineEdit_4->text();
    bool ok;
    int dec1=tmp1.toInt(&ok,10);
    int dec2=tmp2.toInt(&ok,10);
    int dec3=tmp3.toInt(&ok,10);
    int dec4=tmp4.toInt(&ok,10);

    for(int i=0;i<people;i++)
    {
        double score1=m[i].a[0].toDouble(&ok);
        double score2=m[i].a[1].toDouble(&ok);
        double score3=m[i].a[2].toDouble(&ok)*10;
        double score4=m[i].a[3].toDouble(&ok)/5;
        m[i].score=score1*dec1*0.01+score2*dec2*0.01+score3*dec3*0.01+score4*dec4*0.01;
    }
    qSort(m,m+people,cmp1);
    QString tt="";
    tt.append("学号                             姓名                  个人课设   团队课设  平时成绩  上机测试     最终成绩\r\n");
    tt.append("=========================================================\r\n");
    for(int i=0;i<people;i++)
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

}

void cal::on_pushButton_clicked()//优秀
{
    ui->textBrowser->clear();
    QString tt="";
    tt.append("学号                             姓名                  个人课设   团队课设  平时成绩  上机测试     最终成绩\r\n");
    tt.append("=========================================================\r\n");
    for(int i=0;i<people;i++)
    {
        bool ok;
        double s=m[i].a[3].toDouble(&ok);
        if(m[i].score>=90&&s>=200)
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
    }
    tt.append("=========================================================\r\n");
    QFont font("Microsoft YaHei", 15, 75);
    ui->textBrowser->setFont(font);
    ui->textBrowser->setText(tt);
}

void cal::on_pushButton_2_clicked()//良
{
    ui->textBrowser->clear();
    QString tt="";
    tt.append("学号                             姓名                  个人课设   团队课设  平时成绩  上机测试     最终成绩\r\n");
    tt.append("=========================================================\r\n");
    for(int i=0;i<people;i++)
    {
        bool ok;
        double s=m[i].a[3].toDouble(&ok);
        if(m[i].score>=75&&m[i].score<90&&s>=100||(m[i].score>=90&&s<200&&s>=100))
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
    }
    tt.append("=========================================================\r\n");
    QFont font("Microsoft YaHei", 15, 75);
    ui->textBrowser->setFont(font);
    ui->textBrowser->setText(tt);
}

void cal::on_pushButton_3_clicked()//合格
{
    ui->textBrowser->clear();
    QString tt="";
    tt.append("学号                             姓名                  个人课设   团队课设  平时成绩  上机测试     最终成绩\r\n");
    tt.append("=========================================================\r\n");
    for(int i=0;i<people;i++)
    {
        bool ok;
        double s=m[i].a[3].toDouble(&ok);
        if(m[i].score>=60&&m[i].score<75&&s>=100)
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
    }
    tt.append("=========================================================\r\n");
    QFont font("Microsoft YaHei", 15, 75);
    ui->textBrowser->setFont(font);
    ui->textBrowser->setText(tt);
}

void cal::on_pushButton_4_clicked()//不合格
{
    ui->textBrowser->clear();
    QString tt="";
    tt.append("学号                             姓名                  个人课设   团队课设  平时成绩  上机测试     最终成绩\r\n");
    tt.append("=========================================================\r\n");
    for(int i=0;i<people;i++)
    {
        bool ok;
        double s=m[i].a[3].toDouble(&ok);
        if(m[i].score<60||s<100)
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
    }
    tt.append("=========================================================\r\n");
    QFont font("Microsoft YaHei", 15, 75);
    ui->textBrowser->setFont(font);
    ui->textBrowser->setText(tt);
}


void cal::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.drawPixmap(rect(), QPixmap(":/new/prefix1/image/add_back2.png"));
}

void cal::mouseMoveEvent(QMouseEvent *e) {
    if(e->buttons() & Qt::LeftButton) {
        move(e->globalPos() - p);
    }
}

void cal::mousePressEvent(QMouseEvent *e) {
    if(e->button() == Qt::LeftButton) {
        p = e->globalPos() - this->frameGeometry().topLeft();
    }
}
