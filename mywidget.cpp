#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);//透過有人機介面的MyWidget(*Ui)來安裝自己(this)的人機介面
    QStringList ColTotle;
    ui->tableWidget->setColumnCount(4);
    ColTotle<<QStringLiteral("學號")<<QStringLiteral("班級")<<QStringLiteral("姓名")<<QStringLiteral("電話");
    ui->tableWidget->setHorizontalHeaderLabels(ColTotle);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_clicked()
{
    QTableWidgetItem *inputRow1,*inputRow2,*inputRow3,*inputRow4;
    inputRow1 = new QTableWidgetItem(QString(ui->lineEdit->text()));
    inputRow1 = new QTableWidgetItem(QString(ui->lineEdit->text()));
    inputRow1 = new QTableWidgetItem(QString(ui->lineEdit->text()));
    inputRow1 = new QTableWidgetItem(QString(ui->lineEdit->text()));
}

