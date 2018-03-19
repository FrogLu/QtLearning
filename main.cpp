#include "mainwindow.h"
#include <QApplication>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>


void msgBoxInit();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
// test for new git 03.19;

//    QWidget window;
//    window.setWindowTitle("Enter your age");

//    QSpinBox *spinBox = new QSpinBox(&window);
//    QSlider *slider = new QSlider(Qt::Horizontal, &window);
//    spinBox->setRange(0, 130);
//    slider->setRange(0, 130);

//    QObject::connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
//    void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;        //QSpinBox::valueChanged 有两种函数int，string，需要强制制定为int。
//    QObject::connect(spinBox, spinBoxSignal, slider, &QSlider::setValue);
//    spinBox->setValue(35);

//    QHBoxLayout *layout = new QHBoxLayout;
//    layout->addWidget(spinBox);
//    layout->addWidget(slider);
//    window.setLayout(layout);
//    window.show();

    w.show();

    Newspaper newspaper("Newspaper A");
    Reader reader;
    QObject::connect(&newspaper, &Newspaper::newPaper,
                     &reader,    &Reader::receiveNewspaper);
    newspaper.send();

    EventLabel *label = new EventLabel;
    label->setWindowTitle("MouseEvent Demo");
    label->resize(300, 200);
    label->setMouseTracking(true);
    label->show();

    return a.exec();
}


