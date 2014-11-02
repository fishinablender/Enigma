#include "calc.h"
#include "ui_calc.h"

void encrypt();

calc::calc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::calc)
{
    ui->setupUi(this);

    QString dirIn = ui->lineEdit->text();
    QString dirOut = ui->lineEdit_2->text();
    QString recipient = ui->lineEdit_3->text();

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(encrypt()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(decrypt()));




}

void calc::encrypt(){



}

void calc::decrypt(){


}

calc::~calc()
{
    delete ui;
}
