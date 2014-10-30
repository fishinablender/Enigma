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


    //QVariant encryptType =  ui->comboBox->itemData(ui->comboBox->currentIndex());

    ui->label->text() = "" +ui->comboBox->currentIndex();

    //ui->label->setText(encryptType.toString());


    //ui->label->setText(dirIn);




}

void encrypt(){

}


calc::~calc()
{
    delete ui;
}
