#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>

class InputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialog(QWidget *parent = nullptr);
    ~InputDialog();

    // 取得輸入的資料
    QString getStudentId() const;
    QString getClassName() const;
    QString getName() const;
    QString getPhone() const;

private:
    QLineEdit *studentIdEdit;
    QLineEdit *classNameEdit;
    QLineEdit *nameEdit;
    QLineEdit *phoneEdit;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi();
};

#endif // INPUTDIALOG_H
