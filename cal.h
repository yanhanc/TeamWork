#ifndef CAL_H
#define CAL_H

#include <QWidget>

namespace Ui {
class cal;
}

class cal : public QWidget
{
    Q_OBJECT

public:
    explicit cal(QWidget *parent = 0);
    ~cal();

signals:
    void mySignal_ptn();
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::cal *ui;
    QPoint p;
};

#endif // CAL_H
