#ifndef ADDSCORE_H
#define ADDSCORE_H

#include <QWidget>

namespace Ui {
class AddScore;
}

class AddScore : public QWidget
{
    Q_OBJECT

public:
    explicit AddScore(QWidget *parent = 0);
    ~AddScore();

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
    Ui::AddScore *ui;
    QPoint p;
};

#endif // ADDSCORE_H
