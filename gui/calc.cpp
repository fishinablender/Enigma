#include "calc.h"
#include "ui_calc.h"

void encrypt();

calc::calc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::calc)
{
    ui->setupUi(this);

    ui->comboBox->addItem("RSA");
    ui->comboBox->addItem("ECC");

    QString dirIn = ui->lineEdit->text();
    QString dirOut = ui->lineEdit->text();
    QString recipient;



    //QVariant encryptType =  ui->comboBox->itemData(ui->comboBox->currentIndex());

    //ui->label->setText(encryptType.toString());


    //ui->label->setText(dirIn);




}

//public void encrypt(){

//}


calc::~calc()
{
    delete ui;
}
