#ifndef PARTICLEEFFECT_H
#define PARTICLEEFFECT_H

#include <QWidget>
#include <QTimer>
#include <QVector>
#include <QPointF>
#include <QColor>
#include <QPainter>
#include <QRandomGenerator>
#include <cmath>

// 粒子結構
struct Particle {
    QPointF position;      // 位置
    QPointF velocity;      // 速度
    QColor color;          // 顏色
    qreal life;            // 生命值 (0.0 到 1.0)
    qreal size;            // 大小
    qreal decay;           // 衰減速度
};

// 粒子特效類別
class ParticleEffect : public QWidget
{
    Q_OBJECT

public:
    explicit ParticleEffect(QWidget *parent = nullptr);
    ~ParticleEffect();

    // 觸發粒子特效
    void triggerEffect(const QPoint &origin, const QColor &color);

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void updateParticles();

private:
    QVector<Particle> particles;
    QTimer *timer;
    const int PARTICLE_COUNT = 30;        // 每次產生的粒子數量
    const qreal GRAVITY = 0.3;            // 重力
    const qreal PARTICLE_SPEED = 8.0;     // 初始速度
};

#endif // PARTICLEEFFECT_H
