#ifndef PATTERN_H
#define PATTERN_H

#include <QWidget>
#include <QPoint>
#include "cal.h"

namespace Ui {
class Pattern;
}

class Pattern : public QWidget
{
    Q_OBJECT

public:
    explicit Pattern(QWidget *parent = 0);
    QString readStr();

    void getdata();
    ~Pattern();

    QString str;
    QString str1;

protected:
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
private slots:
    void on_pushButton_9_clicked();
    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_released();

    void on_pushButton_8_clicked();

signals:
    void mySignal_back();
    void mySignal_add();
    void mySignal_sch();
    void mySignal_del();
    void mySignal_alt();
    void mySignal_dpy();
    void mySignal_cl();
private:
    Ui::Pattern *ui;
    QPoint p;
    cal cl;
};

#endif // PATTERN_H
