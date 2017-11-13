#include "mainwindow.h"
#include <QApplication>
#include <QApplication>
#include <QWidget>
#include <QSpinBox>
#include <QSlider>
#include <QObject>
#include<QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QStackedLayout>
int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QWidget window;

    window.setWindowTitle("Enter your age");

    QSpinBox *spinBox = new QSpinBox(&window);
    //QSpinBox就是只能输入数字的输入框，并且带有上下箭头的步进按钮。
    QSlider *slider = new QSlider(Qt::Horizontal, &window);
    //QSlider则是带有滑块的滑竿。我们可以从上面的截图中清楚地辨别出这两个组件。
    spinBox->setRange(0, 130);
    slider->setRange(0, 130);

    QObject::connect(slider,  SIGNAL(valueChanged(int)),
                     spinBox, SLOT(setValue(int)));
    QObject::connect(spinBox, SIGNAL(valueChanged(int)),
                     slider,  SLOT(setValue(int)));
    spinBox->setValue(35);

//    QVBoxLayout *layout = new QVBoxLayout; //上下
//    layout->addWidget(spinBox);
//    layout->addWidget(slider);
//    window.setLayout(layout);

//    QGridLayout *layout = new QGridLayout; //
//    layout->addWidget(spinBox);
//    layout->addWidget(slider);
//    window.setLayout(layout);

    QStackedLayout *layout = new QStackedLayout; //层叠
    layout->addWidget(slider);
    layout->addWidget(spinBox);
    //layout->addWidget(slider);
    window.setLayout(layout);
    //创建了一个QHBoxLayout对象。显然，这就是一个布局管理器。
    //然后将这两个组件都添加到这个布局管理器，并且把该布局管理器设置为窗口的布局管理器。


//    layout->addWidget(slider);
//    layout->addWidget(slider);
//    layout->addWidget(spinBox);
//    layout->addWidget(spinBox);
//    window.setLayout(layout);  //测试布局

    window.show();

    return app.exec();

}
