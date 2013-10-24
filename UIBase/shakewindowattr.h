#ifndef SHAKEWINDOWATTR_H
#define SHAKEWINDOWATTR_H

#include <QObject>
#include <QPoint>

class QWidget;
class QTimer;

enum { MaxLimitTimes = 20 };
enum { MaxLimitSpace = 16 };
enum { ShakeSpeed = 30 };

class ShakeWindowAttr : public QObject
{
    Q_OBJECT
public:
    explicit ShakeWindowAttr(QWidget *widget, QObject *parent = 0);
    ~ShakeWindowAttr();
    void startShake();

signals:

public slots:
    void timetoShakeSlot();

private:
    void initSignalSlots();

private:
    QWidget *widget_;
    QTimer *timer_;
    int position_;
    QPoint cur_pos_;
};

#endif // SHAKEWINDOWATTR_H
