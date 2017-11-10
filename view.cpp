
 //mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
 
#include <QMainWindow>
 
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
 
private slots:
    void open();
 
private:
    QAction *openAction;
};
 
#endif // MAINWINDOW_H
 
// ========== mainwindow.cpp
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>  
#include <QToolBar>
 
#include "mainwindow.h"
 
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setWindowTitle(tr("Main Window")); //在 MainWindow 的构造函数中，第一行我们调用了setWindowTitle()，
    //设置主窗口的标题。注意我们的文本使用tr()函数，这是一个用于 Qt 国际化的函数。在后续章节中我们可以看到，我们可以使用 Qt 提供的国际化工具，
   // 将tr()函数的字符串提取出来，进行国际化。由于所需进行国际化的文本应该被大多数人认识，所以，tr()函数里面一般会是英文文本。
    openAction = new QAction(QIcon(":/images/doc-open"), tr("&Open..."), this);
    //我们在堆上创建了openAction对象。在QAction构造函数，我们传入了一个图标、一个文本和 this 指针
    //图标我们使用了QIcon，传入值是一个字符串，这个字符串对应于 Qt 资源文件中的一段路径。Qt 资源文件的后缀名是 qrc。
    //如果我们使用 Qt Creator，我们可以在新建文件中看到 Qt 资源文件。
    //QIcon的参数，以 : 开始，意味着从资源文件中查找资源。:/images/doc-open就是找到了这里的 document-open.png 这个文件。
    //QAction第二个参数中，文本值前面有一个 &，意味着这将成为一个快捷键。注意看截图中 File 的 F 有一个下划线。
    //Qt 资源文件其实是一个 XML 描述的文件，表示 Qt 应用程序所需要的各个资源。我们可以使用普通文本编辑器打开这个文件：

// XHTML

// <RCC>
//     <qresource prefix="/images">
//         <file alias="doc-open">document-open.png</file>
//     </qresource>
// </RCC>
// 1
// 2
// 3
// 4
// 5
// <RCC>
//     <qresource prefix="/images">
//         <file alias="doc-open">document-open.png</file>
//     </qresource>
// </RCC>
// 
// 
    openAction->setShortcuts(QKeySequence::Open);
    //我们使用了setShortcut()函数，用于说明这个QAction的快捷键。QKeySequence为我们定义了很多内置的快捷键。
    //
    openAction->setStatusTip(tr("Open an existing file"));
    //setStatusTip()则实现了当用户鼠标滑过这个 action 时，会在主窗口下方的状态栏显示相应的提示。
    //
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));
    //connect(openAction, &QAction::triggered, this, &MainWindow::open);
    //后面的connect()函数，将这个QAction的triggered()信号与MainWindow类的open()函数连接起来。
    //当用户点击了这个QAction时，会自动触发MainWindow的open()函数。这是我们之前已经了解过的。
 
    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);
 
    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
 
    statusBar();
//    下面的menuBar()、toolBar()和statusBar()三个是QMainWindow的函数，用于创建并返回菜单栏、工具栏和状态栏。
}
 
MainWindow::~MainWindow()
{
}
 
void MainWindow::open()
{
    QMessageBox::information(this, tr("Information"), tr("Open"));
}