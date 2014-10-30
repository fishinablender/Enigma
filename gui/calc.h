#ifndef CALC_H
#define CALC_H

#include <QWidget>

namespace Ui {
class calc;
}

class calc : public QWidget
{
    Q_OBJECT

public:
    explicit calc(QWidget *parent = 0);
    ~calc();
    //void encrypt();

public slots:
    //void encrypt();

private:
    Ui::calc *ui;
};

#endif // CALC_H
