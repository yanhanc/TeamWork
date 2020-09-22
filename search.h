#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>

namespace Ui {
class Search;
}

class Search : public QWidget
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = 0);
    ~Search();
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

signals:
    void mySignal_ptn();
private:
    Ui::Search *ui;
    QPoint p;
};

#endif // SEARCH_H
