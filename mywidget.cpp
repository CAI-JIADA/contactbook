#include "mywidget.h"
#include "ui_mywidget.h"
#include<QTableWidgetItem>
#include<QFile>
#include<QDebug>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPushButton>
//#include "QDebug"
QString mFilename ="C:/Users/user/Desktop/EX/contackbook.txt";
void Write(QString Filename,QString str)
{
    QFile mFile(Filename);
    if(!mFile.open(QFile::WriteOnly|QFile::Text))
    {
        qDebug()<<"could not open file for write";
        return;
    }
    QTextStream out(&mFile);
    out<<str;
    mFile.flush();
    mFile.close();
}

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);//透過有人機介面的MyWidget(*Ui)來安裝自己(this)的人機介面
    QStringList ColTotle;
    ui->tableWidget->setColumnCount(4);
    ColTotle<<QStringLiteral("學號")<<QStringLiteral("班級")<<QStringLiteral("姓名")<<QStringLiteral("電話");
    ui->tableWidget->setHorizontalHeaderLabels(ColTotle);
    
    // 初始化粒子特效
    particleEffect = new ParticleEffect(this);
}

MyWidget::~MyWidget()
{
    delete particleEffect;
    delete ui;
}


void MyWidget::on_pushButton_clicked()
{
    // 觸發綠色粒子特效 (新增按鈕)
    triggerButtonEffect(ui->pushButton, QColor(76, 175, 80));
    
    QTableWidgetItem *inputRow1,*inputRow2,*inputRow3,*inputRow4;
    inputRow1 = new QTableWidgetItem(QString(ui->lineEdit->text()));
    inputRow2 = new QTableWidgetItem(QString(ui->lineEdit_2->text()));
    inputRow3 = new QTableWidgetItem(QString(ui->lineEdit_3->text()));
    inputRow4 = new QTableWidgetItem(QString(ui->lineEdit_4->text()));
    int rc=ui->tableWidget->rowCount();
    qDebug()<<rc<<"\n";
    //ui->tableWidget->insertRow(rc);
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,inputRow1);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,inputRow2);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,inputRow3);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,inputRow4);

}


void MyWidget::on_pushButton_3_clicked()
{
    // 觸發藍色粒子特效 (匯入按鈕)
    triggerButtonEffect(ui->pushButton_3, QColor(33, 150, 243));
    
    QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("匯入聯絡人"),"",QStringLiteral("文字檔案 (*.txt);;CSV檔案 (*.csv);;所有檔案 (*.*)"));
    if (fileName.isEmpty()) {
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, QStringLiteral("錯誤"),QStringLiteral("無法開啟檔案：") + fileName);
        return;
    }
    QTextStream in(&file);
    int importCount = 0;
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) {
            continue;
        }
        QStringList fields;
        if (line.contains(',')) {
            fields = line.split(',');
        } else if (line.contains('\t')) {
            fields = line.split('\t');
        } else {
            fields = line.split(' ', Qt::SkipEmptyParts);
        }
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(fields[0].trimmed()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(fields[1].trimmed()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(fields[2].trimmed()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(fields[3].trimmed()));
        importCount++;
    }
    file.close();
}

void MyWidget::on_pushButton_4_clicked()
{
    // 觸發紅色粒子特效 (結束按鈕)
    triggerButtonEffect(ui->pushButton_4, QColor(244, 67, 54));
    
    on_pushButton_2_clicked();
    close();
}
void MyWidget::on_pushButton_2_clicked()
{
    // 觸發橙色粒子特效 (匯出按鈕)
    triggerButtonEffect(ui->pushButton_2, QColor(255, 152, 0));
    
    QString saveFile="";
    mFilename=QFileDialog::getSaveFileName(this,"匯出檔案",".");
    for(int i=0;i<ui->tableWidget->rowCount();i++)
    {
        for(int j=0;j<ui->tableWidget->columnCount();j++)
        {
            saveFile+=ui->tableWidget->item(i,j)->text()+",";
        }
        saveFile+="\n";
    }
    Write(mFilename,saveFile);
}

// 觸發按鈕粒子特效的輔助函數
void MyWidget::triggerButtonEffect(QPushButton *button, const QColor &color)
{
    if (!button || !particleEffect) return;
    
    // 獲取按鈕的中心位置（相對於主視窗）
    QPoint buttonCenter = button->mapTo(this, button->rect().center());
    
    // 觸發粒子特效
    particleEffect->triggerEffect(buttonCenter, color);
}

