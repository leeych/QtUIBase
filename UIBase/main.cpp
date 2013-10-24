#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QFont>
#include <QPixmap>
#include <QLabel>
#include <QPixmap>

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QStateMachine>
#include <QSignalTransition>
#include <QPropertyAnimation>

#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>

#include "testdialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    /*
#if 0
    QWidget *w = new QWidget;
    w->resize(640, 520);
    QPushButton *button = new QPushButton("click me!", w);
    QStateMachine *machine = new QStateMachine;
    QState *state1 = new QState(machine);
    QState *state2 = new QState(machine);

    state1->assignProperty(button, "geometry", QRect(0,0,80,30));
    state1->assignProperty(button, "text", "click me!");
    QFont font1("Airl", 10);
    state1->assignProperty(button, "font", font1);

    state2->assignProperty(button, "geometry", QRect(590, 440, 50, 80));
    QFont font2("Airl", 20);
    state2->assignProperty(button, "font", font2);
    state2->assignProperty(button, "text", "back");

    QPropertyAnimation *animation = new QPropertyAnimation(button, "geometry");
    animation->setDuration(3000);
    animation->setEasingCurve(QEasingCurve::InOutElastic);
    QSignalTransition *transition1 = state1->addTransition(button, SIGNAL(clicked()), state2);
    transition1->addAnimation(animation);
    QSignalTransition *transition2 = state2->addTransition(button, SIGNAL(clicked()), state1);
    transition2->addAnimation(animation);
    machine->setInitialState(state1);
    machine->start();
    w->show();
#endif

#if 0
    TestDialog dialog;
    dialog.exec();
#endif
*/

    /*
    QWidget *w = new QWidget;
    w->resize(900, 600);
    QLabel *bird = new QLabel(w);
    bird->setText("bird");

    QLabel *pig = new QLabel(w);
    pig->setText("pig");

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(bird);
    vlayout->addWidget(pig);
    w->setLayout(vlayout);

    QPropertyAnimation *birdfly = new QPropertyAnimation(bird, "pos");
    birdfly->setDuration(3000);
    birdfly->setStartValue(QPoint(0, 560));
    birdfly->setEndValue(QPoint(860, 0));
    birdfly->setEasingCurve(QEasingCurve::OutBounce);

    QPropertyAnimation *pigfly = new QPropertyAnimation(pig, "pos");
    pigfly->setDuration(3000);
    pigfly->setStartValue(QPoint(0, 0));
    pigfly->setEndValue(QPoint(860, 560));
    pigfly->setEasingCurve(QEasingCurve::OutBounce);

    QSequentialAnimationGroup group;
//    QParallelAnimationGroup group;
    group.addAnimation(birdfly);
    group.addAnimation(pigfly);
    group.start();
    w->show();
    */

    TestDialog dialog;
    dialog.startShake();
    dialog.exec();

    return app.exec();
}
