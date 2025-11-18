#include "particleeffect.h"
#include <QPaintEvent>

ParticleEffect::ParticleEffect(QWidget *parent)
    : QWidget(parent)
{
    // 設置視窗屬性：透明背景、無邊框、總是在最上層
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_TransparentForMouseEvents);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);

    // 創建計時器用於更新粒子
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ParticleEffect::updateParticles);
}

ParticleEffect::~ParticleEffect()
{
    delete timer;
}

void ParticleEffect::triggerEffect(const QPoint &origin, const QColor &color)
{
    // 創建新的粒子群
    for (int i = 0; i < PARTICLE_COUNT; ++i) {
        Particle p;
        
        // 隨機角度和速度
        qreal angle = QRandomGenerator::global()->bounded(360) * M_PI / 180.0;
        qreal speed = PARTICLE_SPEED * (0.5 + QRandomGenerator::global()->generateDouble() * 0.5);
        
        p.position = origin;
        p.velocity = QPointF(cos(angle) * speed, sin(angle) * speed);
        p.color = color;
        p.life = 1.0;
        p.size = 4.0 + QRandomGenerator::global()->bounded(4);
        p.decay = 0.015 + QRandomGenerator::global()->generateDouble() * 0.01;
        
        particles.append(p);
    }

    // 顯示視窗並啟動計時器
    if (!isVisible()) {
        // 設置為全螢幕大小以捕獲所有粒子
        if (parentWidget()) {
            setGeometry(parentWidget()->geometry());
        }
        show();
        raise();
    }
    
    if (!timer->isActive()) {
        timer->start(16); // 約 60 FPS
    }
}

void ParticleEffect::updateParticles()
{
    // 更新所有粒子
    for (int i = particles.size() - 1; i >= 0; --i) {
        Particle &p = particles[i];
        
        // 更新位置
        p.position += p.velocity;
        
        // 應用重力
        p.velocity.setY(p.velocity.ry() + GRAVITY);
        
        // 減少生命值
        p.life -= p.decay;
        
        // 移除死亡的粒子
        if (p.life <= 0.0) {
            particles.removeAt(i);
        }
    }

    // 如果沒有粒子了，停止計時器並隱藏視窗
    if (particles.isEmpty()) {
        timer->stop();
        hide();
    }

    // 觸發重繪
    update();
}

void ParticleEffect::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // 繪製所有粒子
    for (const Particle &p : particles) {
        QColor color = p.color;
        color.setAlphaF(p.life); // 設置透明度根據生命值
        
        painter.setBrush(color);
        painter.setPen(Qt::NoPen);
        
        // 繪製圓形粒子
        qreal size = p.size * p.life; // 大小隨生命值縮小
        painter.drawEllipse(p.position, size, size);
    }
}
