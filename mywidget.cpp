#include "mywidget.h"
#include "ui_mywidget.h"
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
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

void MyWidget::on_pushButton_2_clicked()
{
    // 開啟檔案對話框讓使用者選擇儲存位置
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    QStringLiteral("匯出聯絡人"),
                                                    "",
                                                    "CSV Files (*.csv);;Text Files (*.txt);;All Files (*)");
    
    // 如果使用者取消選擇，直接返回
    if (fileName.isEmpty())
        return;
    
    // 開啟檔案準備寫入
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, QStringLiteral("錯誤"), 
                           QStringLiteral("無法開啟檔案進行寫入！"));
        return;
    }
    
    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);
    
    // 寫入標題列
    int columnCount = ui->tableWidget->columnCount();
    for (int col = 0; col < columnCount; ++col) {
        QTableWidgetItem *headerItem = ui->tableWidget->horizontalHeaderItem(col);
        if (headerItem) {
            out << headerItem->text();
        }
        if (col < columnCount - 1) {
            out << ",";
        }
    }
    out << "\n";
    
    // 寫入資料列
    int rowCount = ui->tableWidget->rowCount();
    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            if (item) {
                QString text = item->text();
                // 如果內容包含逗號或換行，需要用雙引號包起來
                if (text.contains(',') || text.contains('\n') || text.contains('"')) {
                    text.replace("\"", "\"\""); // 雙引號需要轉義
                    out << "\"" << text << "\"";
                } else {
                    out << text;
                }
            }
            if (col < columnCount - 1) {
                out << ",";
            }
        }
        out << "\n";
    }
    
    file.close();
    
    // 顯示成功訊息
    QMessageBox::information(this, QStringLiteral("成功"), 
                           QStringLiteral("聯絡人已成功匯出！"));
}

