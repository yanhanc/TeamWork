#ifndef DELETE_H
#define DELETE_H

#include <QWidget>

namespace Ui {
class Delete;
}

class Delete : public QWidget
{
    Q_OBJECT

public:
    explicit Delete(QWidget *parent = 0);
    ~Delete();

signals:
    void mySignal_ptn();

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Delete *ui;
    QPoint p;
};

#endif // DELETE_H
