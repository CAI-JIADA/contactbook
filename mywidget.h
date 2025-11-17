#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "particleeffect.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MyWidget;//有人機介面的MyWidget
}
QT_END_NAMESPACE

class QPushButton;
class InputDialog;  // 前向聲明

class MyWidget : public QWidget//沒有人機介面的MyWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MyWidget *ui;//用指標連制有人機介面的MyWidget
    ParticleEffect *particleEffect; // 粒子特效
    
    void triggerButtonEffect(QPushButton *button, const QColor &color);
};
#endif // MYWIDGET_H
