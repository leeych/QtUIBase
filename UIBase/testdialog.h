#ifndef TESTDIALOG_H
#define TESTDIALOG_H

#include <QDialog>
#include "fadeinoutattr.h"
#include "shakewindowattr.h"

//class FadeInOutAttr;

class TestDialog : public QDialog
{
    Q_OBJECT
public:
    explicit TestDialog(QWidget *parent = 0);
    void startShake();

signals:

public slots:

protected:
    void closeEvent(QCloseEvent *);
    void timerEvent(QTimerEvent *);

private:
    int timer_id_;
    FadeInOutAttr fadeinout_attr_;
    ShakeWindowAttr shakewindow_attr_;
};

#endif // TESTDIALOG_H
