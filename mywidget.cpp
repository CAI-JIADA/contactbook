#include "mywidget.h"
#include "ui_mywidget.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>

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

void MyWidget::on_pushButton_3_clicked()
{
    // 開啟檔案對話框選擇要匯入的檔案
    QString fileName = QFileDialog::getOpenFileName(this,
        QStringLiteral("匯入聯絡人"),
        "",
        QStringLiteral("文字檔案 (*.txt);;CSV檔案 (*.csv);;所有檔案 (*.*)"));
    
    // 如果使用者取消選擇，直接返回
    if (fileName.isEmpty()) {
        return;
    }
    
    // 開啟檔案
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, QStringLiteral("錯誤"), 
            QStringLiteral("無法開啟檔案：") + fileName);
        return;
    }
    
    QTextStream in(&file);
    int importCount = 0;
    
    // 讀取檔案內容並加入到表格中
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        
        // 跳過空行
        if (line.isEmpty()) {
            continue;
        }
        
        // 使用逗號或Tab分隔資料
        QStringList fields;
        if (line.contains(',')) {
            fields = line.split(',');
        } else if (line.contains('\t')) {
            fields = line.split('\t');
        } else {
            fields = line.split(' ', Qt::SkipEmptyParts);
        }
        
        // 確保至少有4個欄位
        while (fields.size() < 4) {
            fields.append("");
        }
        
        // 在表格中插入新的一列
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        
        // 設定各欄位的值
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(fields[0].trimmed()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(fields[1].trimmed()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(fields[2].trimmed()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(fields[3].trimmed()));
        
        importCount++;
    }
    
    file.close();
    
    // 顯示匯入成功訊息
    QMessageBox::information(this, QStringLiteral("匯入成功"), 
        QStringLiteral("成功匯入 %1 筆聯絡人資料").arg(importCount));
}

