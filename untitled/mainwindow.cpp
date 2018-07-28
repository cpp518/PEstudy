#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include "define.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    //设置窗口大小，并且无法调整,设置标题栏
    this->setWindowTitle(tr("PEStudy"));
    this->setFixedSize(WindowsW,WindowsH);
    QMenuBar* menuBar = new QMenuBar(this);
    menuBar->setGeometry(MenuBarX,MenuBarY,MenuBarW,MenuBarH);
    QMenu* menu = menuBar->addMenu("文件");
    QAction* openFile = new QAction(tr("打开文件"),this);
    QAction* exit = new QAction(tr("退出"),this);
    menu->addAction(openFile);
    menu->addAction(exit);

    connect(exit,SIGNAL(triggered(bool)),this,SLOT(CloseWindow()));
    connect(openFile,SIGNAL(triggered(bool)),this,SLOT(OpenFileName()));

}

MainWindow::~MainWindow()
{
   // delete ui;
   // delete openFile;
}

void MainWindow::CloseWindow(){
    this->close();
}

void MainWindow::OpenFileName(){
    this->fileName = QFileDialog::getOpenFileName(
                this,tr("打开exe文件"),"./","*.exe");

}
