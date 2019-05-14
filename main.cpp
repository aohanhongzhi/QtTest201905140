#include <QApplication>
#include <QFormLayout>
#include <QtGlobal>
#include <QObject>
#include <QSlider>
#include <QSpinBox>
#include <QWidget>
#include <QPlainTextEdit>
#include <QDesktopWidget> //居中显示的部件
#include <QAction>
#include <QToolBar>
#include <QMenuBar>
#include <QMainWindow>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    auto window = new QMainWindow;
    auto spinBox = new QSpinBox;
    spinBox->setRange(0, 100);
    auto slider = new QSlider;
    slider->setRange(0, 100);
    QObject::connect(spinBox,
            // 对于重载函数需要给出确定的版本，QOverload需要编译器支持c++11
                     QOverload<int>::of(&QSpinBox::valueChanged),
                     slider,
                     &QSlider::setValue);
    QObject::connect(slider,
                     &QSlider::valueChanged,
                     spinBox,
                     &QSpinBox::setValue);

    auto layout = new QFormLayout;

    auto text = new QPlainTextEdit;

    layout->addRow("spin box:", spinBox);
    layout->addRow("slider:", slider);
    layout->addRow("text:", text);
//    window->setLayout(layout);
//    window->setGeometry(500,500,200,200);

//菜单

    QMenuBar *qMenuBar = new QMenuBar(window);
    qMenuBar->setWindowIconText("文件");

    QMenu *qMenu = new QMenu("文件");


    window->setMenuBar(qMenuBar);

//    fileQAction->setText("新建");

    qMenuBar->addAction(qMenu->menuAction());

    QAction *newFileQAction = new QAction("新建");
    QAction *editFileQAction = new QAction("编辑");
    QAction *deleteFileACtion = new QAction("删除");


    qMenu->addAction(newFileQAction);
    qMenu->addAction(editFileQAction);
    qMenu->addAction(deleteFileACtion);


    QAction *startQAction = new QAction;
    startQAction->setText("开始");
    QAction *settingsQAction = new QAction;
    settingsQAction->setText("设置");

    QAction *financeQAction=new QAction;
    financeQAction->setText("财务");

    QAction *dataQAction = new QAction;
    dataQAction->setText("报表");


    QToolBar *qToolBar = new QToolBar(window);
    qToolBar->addAction(startQAction);
    qToolBar->addAction(financeQAction);
//    qToolBar->addAction(fileQAction);
    qToolBar->addAction(settingsQAction);
    qToolBar->addAction(dataQAction);
    window->addToolBar(Qt::TopToolBarArea,qToolBar);

//    addToolBar(Qt::TopToolBarArea,qToolBar);


    window->resize(800,500);
    //先显示再移动
    window->show();

    //居中设置
    QDesktopWidget* desktop = QApplication::desktop(); // =app->desktop();也可以
    window->move((desktop->width() - window->width())/2, (desktop->height() - window->height())/2);


    return app.exec();


}