#ifndef FADEINOUTATTR_H
#define FADEINOUTATTR_H

#include <QObject>

class QTimer;
class QDialog;
class QGraphicsOpacityEffect;

class FadeInOutAttr : public QObject
{
    Q_OBJECT
public:
    explicit FadeInOutAttr(QDialog *dialog, QObject *parent = 0);
    ~FadeInOutAttr();

    enum InOutAttr
    {
        FadeIn = 0,
        FadeOut,
        FadeOutHide,
        FadeOutExit
    };

    void setFadeInOut(int effectType);
    void raiseDialog();

    const static int timerRate = 30;
    const static double changeValue = 0.05;

signals:

public slots:
    void changeOpacitySlot();

private:
    void initSignalSlots();

private:
    QTimer *opacity_timer_;
    double opalevel_;
    int effect_type_;
    bool is_working_;

    QGraphicsOpacityEffect *opacity_effect_;
    QDialog *dialog_;
};

#endif // FADEINOUTATTR_H
