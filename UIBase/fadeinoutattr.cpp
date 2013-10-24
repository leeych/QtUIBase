#include "fadeinoutattr.h"

#include <QDialog>
#include <QTimer>
#include <QGraphicsOpacityEffect>

//int FadeInOutAttr::timerRate = 30;
//double FadeInOutAttr::changeValue = 0.05;

FadeInOutAttr::FadeInOutAttr(QDialog *dialog, QObject *parent) :
    QObject(parent)
{
    dialog_ = dialog;
    opacity_effect_ = new QGraphicsOpacityEffect(this);
    dialog_->setGraphicsEffect(opacity_effect_);
    opacity_effect_->setOpacity(0.0);
    opacity_timer_ = new QTimer(this);
    is_working_ = false;
    effect_type_ = -1;

    initSignalSlots();
}

FadeInOutAttr::~FadeInOutAttr()
{

}

void FadeInOutAttr::setFadeInOut(int effectType)
{
    if (is_working_ && effectType == effect_type_)
    {
        return;
    }
    effect_type_ = effectType;
    opalevel_ = 1.0;
    if (effectType == FadeIn)
    {
        opalevel_ = 0.0;
    }
    opacity_timer_->start(timerRate);
    is_working_ = true;
}

void FadeInOutAttr::raiseDialog()
{
    opacity_effect_->setOpacity(1.0);
    dialog_->showNormal();
    dialog_->raise();
}

void FadeInOutAttr::changeOpacitySlot()
{
    if (effect_type_ == FadeIn)
    {
        if (opalevel_ >= 1.0)
        {
            opacity_timer_->stop();
            is_working_ = false;
            return;
        }
        opacity_effect_->setOpacity(opalevel_ += changeValue);
    }
    else
    {
        if (opalevel_ <= 0.0)
        {
            opacity_timer_->stop();
            is_working_ = false;
            if (effect_type_ == FadeOut)
            {
                dialog_->close();
            }
            else if (effect_type_ == FadeOutHide)
            {
                dialog_->hide();
            }
            else if (effect_type_ == FadeOutExit)
            {
                exit(1);
            }
            return;
        }
        opacity_effect_->setOpacity(opalevel_ -= changeValue);
    }
}

void FadeInOutAttr::initSignalSlots()
{
    connect(opacity_timer_, SIGNAL(timeout()), this, SLOT(changeOpacitySlot()));
}
