#include "mainwindow.h"
#include "ui_mainwindow.h"

//一定要包括头文件
#include<QMenuBar>//菜单栏头文件
#include<QToolBar>//工具栏头文件
#include<QStatusBar>//状态栏头文件
#include<QTextEdit>//中心部件头文件
#include<QDockWidget>//铆接部件头文件
#include<QPushButton>//按钮头文件
#include<QLabel>//标签头文件

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //重置窗口大小
    resize(600,400);//随便写两个整数

//一、菜单栏
    //创建菜单栏,只能有一个
    QMenuBar* mbar=menuBar();//此处创建方式不是new,而是调用了一个函数

    //将菜单栏放入窗口中
    setMenuBar(mbar);

    //创建菜单
    QMenu*filemenu=mbar->addMenu("文件");
    QMenu*editmenu=mbar->addMenu("编辑");
    QMenu*visionmenu=mbar->addMenu("视图");

    //创建菜单项
    filemenu->addAction("New Project");

    //如果需要可以添加分隔符
    filemenu->addSeparator();

    filemenu->addAction("New File");

//二、工具栏
    //创建工具栏,可以有多个
    QToolBar*tbar=new QToolBar;

    //将工具栏放在窗口中，并设置默认停靠位置（也可以省略这一参数，默认为上方）
    addToolBar(Qt::LeftToolBarArea, tbar);//设置为左侧
    //不同位置名称：Left Right Bottom Top

    //设置是否可以拖动
    //tbar->setMovable(false);

    //设置拖动后允许停靠的位置
    tbar->setAllowedAreas(Qt::LeftToolBarArea | Qt::BottomToolBarArea);//左侧or上侧

    //设置是否可以浮动
    tbar->setFloatable(false);

    //创建工具
    tbar->addAction("欢迎");
    //如果需要可以添加分隔符
    tbar->addSeparator();
    tbar->addAction("编辑");

    //如果需要可以增加控件（如按钮）
    QPushButton* button=new QPushButton;
    tbar->addWidget(button);//因为QPushButton继承自QWidget,所以使用addWidget

//三、状态栏，只能有一个

    QStatusBar* sbar=new QStatusBar;
    //将状态栏添加到窗口中
    setStatusBar(sbar);

    //左侧添加常用控件如标签控件
    QLabel* label=new QLabel("提示信息",this);
    sbar->addWidget(label);

    //右侧添加常用控件如按钮控件
    QPushButton* statusButton=new QPushButton("close",this);
    sbar->addPermanentWidget(statusButton);
    //简单的信号与槽，实现点击close关闭界面的功能
    connect(statusButton,&QPushButton::clicked,this,&QWidget::close);

    //也可以使用addAction,与菜单栏、工具栏同理

//四、中心部件，只能有一个
    QTextEdit *central=new QTextEdit(this);
    //将中心部件添加到窗口中
    setCentralWidget(central);

//五、铆接部件,可以有多个
    QDockWidget* dock=new QDockWidget(this);
    //将铆接部件添加到窗口中
    addDockWidget(Qt::BottomDockWidgetArea,dock);//设置在中心部件下侧
    //与工具栏类似，它也可以设置是否能浮动，允许停靠位置等，具体可以查看帮助->索引
}

MainWindow::~MainWindow()
{
    delete ui;
}

