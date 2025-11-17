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
    
    // Improve table appearance
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->verticalHeader()->setVisible(false);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_clicked()
{
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);
    
    QTableWidgetItem *inputRow1 = new QTableWidgetItem(QString(ui->lineEdit->text()));
    QTableWidgetItem *inputRow2 = new QTableWidgetItem(QString(ui->lineEdit_2->text()));
    QTableWidgetItem *inputRow3 = new QTableWidgetItem(QString(ui->lineEdit_3->text()));
    QTableWidgetItem *inputRow4 = new QTableWidgetItem(QString(ui->lineEdit_4->text()));
    
    ui->tableWidget->setItem(rowCount, 0, inputRow1);
    ui->tableWidget->setItem(rowCount, 1, inputRow2);
    ui->tableWidget->setItem(rowCount, 2, inputRow3);
    ui->tableWidget->setItem(rowCount, 3, inputRow4);
    
    // Clear input fields
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
}

