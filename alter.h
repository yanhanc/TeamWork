#ifndef ALTER_H
#define ALTER_H

#include <QWidget>

namespace Ui {
class Alter;
}

class Alter : public QWidget
{
    Q_OBJECT

public:
    explicit Alter(QWidget *parent = 0);
    ~Alter();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
signals:
    void mySignal_ptn();

private:
    Ui::Alter *ui;
    QPoint p;
};

#endif // ALTER_H
