#include "shakewindowattr.h"

#include <QWidget>
#include <QTimer>

ShakeWindowAttr::ShakeWindowAttr(QWidget *widget, QObject *parent) :
    QObject(parent)
{
    widget_ = widget;
    position_ = MaxLimitTimes;
    timer_ = new QTimer(this);

    initSignalSlots();
}

ShakeWindowAttr::~ShakeWindowAttr()
{

}

void ShakeWindowAttr::startShake()
{
    if (position_ < MaxLimitTimes)
    {
        return;
    }
    position_ = 1;
    cur_pos_ = widget_->pos();
    timer_->start(ShakeSpeed);
}

void ShakeWindowAttr::timetoShakeSlot()
{
    if (position_ < MaxLimitTimes)
    {
        ++position_;
        switch (position_)
        {
        case 1:
        {
            QPoint tmp_pos(cur_pos_.x() - MaxLimitSpace, cur_pos_.y() - MaxLimitSpace);
            widget_->move(tmp_pos);
        }
            break;
        case 2:
        {
            QPoint tmp_pos(cur_pos_.x(), cur_pos_.y() - MaxLimitSpace);;
            widget_->move(tmp_pos);
        }
            break;
        case 3:
        {
            QPoint tmp_pos(cur_pos_.x() + MaxLimitSpace, cur_pos_.y() - MaxLimitSpace);;
            widget_->move(tmp_pos);
        }
            break;
        case 4:
        {
            QPoint tmp_pos(cur_pos_.x() + MaxLimitSpace, cur_pos_.y());;
            widget_->move(tmp_pos);
        }
            break;
        case 5:
        {
            QPoint tmp_pos(cur_pos_.x() + MaxLimitSpace, cur_pos_.y() + MaxLimitSpace);;
            widget_->move(tmp_pos);
        }
            break;
        case 6:
        {
            QPoint tmp_pos(cur_pos_.x(), cur_pos_.y() + MaxLimitSpace);;
            widget_->move(tmp_pos);
        }
            break;
        case 7:
        {
            QPoint tmp_pos(cur_pos_.x() - MaxLimitSpace, cur_pos_.y() + MaxLimitSpace);;
            widget_->move(tmp_pos);
        }
            break;
        case 8:
        {
            QPoint tmp_pos(cur_pos_.x() - MaxLimitSpace, cur_pos_.y());;
            widget_->move(tmp_pos);
        }
            break;
        case 0:
        default:
            widget_->move(cur_pos_);
            break;
        }
    }
    else
    {
        timer_->stop();
    }
}

void ShakeWindowAttr::initSignalSlots()
{
    connect(timer_, SIGNAL(timeout()), this, SLOT(timetoShakeSlot()));
}
