#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MyWidget;//有人機介面的MyWidget
}
QT_END_NAMESPACE

class MyWidget : public QWidget//沒有人機介面的MyWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private:
    Ui::MyWidget *ui;//用指標連制有人機介面的MyWidget
};
#endif // MYWIDGET_H
