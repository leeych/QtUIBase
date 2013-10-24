#include "testdialog.h"
//#include "fadeinoutattr.h"

TestDialog::TestDialog(QWidget *parent) :
    QDialog(parent),
    fadeinout_attr_(this),
    shakewindow_attr_(this)
{
//    fadeinout_attr_ = new FadeInOutAttr(this);
//    fadeinout_attr_->setFadeInOut(FadeInOutAttr::FadeIn);
    fadeinout_attr_.setFadeInOut(FadeInOutAttr::FadeIn);
    timer_id_ = startTimer(800);
}

void TestDialog::startShake()
{
    shakewindow_attr_.startShake();
}

void TestDialog::closeEvent(QCloseEvent *)
{
//    fadeinout_attr_->setFadeInOut(FadeInOutAttr::FadeOut);
    fadeinout_attr_.setFadeInOut(FadeInOutAttr::FadeOut);
}

void TestDialog::timerEvent(QTimerEvent *)
{
    startShake();
}
