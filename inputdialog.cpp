#include "inputdialog.h"

InputDialog::InputDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUi();
}

InputDialog::~InputDialog()
{
}

void InputDialog::setupUi()
{
    setWindowTitle(QStringLiteral("新增聯絡人"));
    setMinimumWidth(400);

    // 創建輸入欄位
    studentIdEdit = new QLineEdit(this);
    classNameEdit = new QLineEdit(this);
    nameEdit = new QLineEdit(this);
    phoneEdit = new QLineEdit(this);

    // 設置提示文字
    studentIdEdit->setPlaceholderText(QStringLiteral("請輸入學號"));
    classNameEdit->setPlaceholderText(QStringLiteral("請輸入班級"));
    nameEdit->setPlaceholderText(QStringLiteral("請輸入姓名"));
    phoneEdit->setPlaceholderText(QStringLiteral("請輸入電話號碼"));

    // 創建標籤
    QLabel *studentIdLabel = new QLabel(QStringLiteral("學號:"), this);
    QLabel *classNameLabel = new QLabel(QStringLiteral("班級:"), this);
    QLabel *nameLabel = new QLabel(QStringLiteral("姓名:"), this);
    QLabel *phoneLabel = new QLabel(QStringLiteral("電話:"), this);

    // 創建表單佈局
    QFormLayout *formLayout = new QFormLayout();
    formLayout->addRow(studentIdLabel, studentIdEdit);
    formLayout->addRow(classNameLabel, classNameEdit);
    formLayout->addRow(nameLabel, nameEdit);
    formLayout->addRow(phoneLabel, phoneEdit);
    formLayout->setSpacing(15);
    formLayout->setContentsMargins(20, 20, 20, 10);

    // 創建按鈕
    okButton = new QPushButton(QStringLiteral("確定"), this);
    cancelButton = new QPushButton(QStringLiteral("取消"), this);

    // 設置按鈕樣式
    okButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #4CAF50;"
        "    color: white;"
        "    border: none;"
        "    padding: 10px 30px;"
        "    font-size: 14px;"
        "    font-weight: bold;"
        "    border-radius: 6px;"
        "    min-width: 80px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #45a049;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #3d8b40;"
        "}"
    );

    cancelButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #f44336;"
        "    color: white;"
        "    border: none;"
        "    padding: 10px 30px;"
        "    font-size: 14px;"
        "    font-weight: bold;"
        "    border-radius: 6px;"
        "    min-width: 80px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #da190b;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #c41408;"
        "}"
    );

    // 設置輸入框樣式
    QString lineEditStyle =
        "QLineEdit {"
        "    padding: 8px;"
        "    border: 2px solid #ddd;"
        "    border-radius: 4px;"
        "    background-color: white;"
        "    font-size: 13px;"
        "}"
        "QLineEdit:focus {"
        "    border: 2px solid #4CAF50;"
        "}";

    studentIdEdit->setStyleSheet(lineEditStyle);
    classNameEdit->setStyleSheet(lineEditStyle);
    nameEdit->setStyleSheet(lineEditStyle);
    phoneEdit->setStyleSheet(lineEditStyle);

    // 設置標籤樣式
    QString labelStyle =
        "QLabel {"
        "    font-size: 14px;"
        "    font-weight: bold;"
        "    color: #333;"
        "}";

    studentIdLabel->setStyleSheet(labelStyle);
    classNameLabel->setStyleSheet(labelStyle);
    nameLabel->setStyleSheet(labelStyle);
    phoneLabel->setStyleSheet(labelStyle);

    // 創建按鈕佈局
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);
    buttonLayout->setSpacing(10);
    buttonLayout->setContentsMargins(20, 10, 20, 20);

    // 創建主佈局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    // 設置對話框樣式
    setStyleSheet(
        "QDialog {"
        "    background-color: #f5f5f5;"
        "    font-family: 'Microsoft JhengHei', '微軟正黑體', Arial, sans-serif;"
        "}"
    );

    // 連接信號和槽
    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

QString InputDialog::getStudentId() const
{
    return studentIdEdit->text();
}

QString InputDialog::getClassName() const
{
    return classNameEdit->text();
}

QString InputDialog::getName() const
{
    return nameEdit->text();
}

QString InputDialog::getPhone() const
{
    return phoneEdit->text();
}
