#ifndef DISPLAY_H
#define DISPLAY_H

#include <QWidget>

namespace Ui {
class Display;
}

class Display : public QWidget
{
    Q_OBJECT

public:
    explicit Display(QWidget *parent = 0);
    ~Display();
    void setStr(QString);


signals:
    void mySignal_ptn();


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
protected:
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);

private:
    Ui::Display *ui;
    QString str_in;
    QString tt;
    QPoint p;
};

#endif // DISPLAY_H
