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
    this->menuBar = new QMenuBar(this);
    menuBar->setGeometry(MenuBarX,MenuBarY,MenuBarW,MenuBarH);
    this->menu = menuBar->addMenu("文件");
    this->openFile = new QAction(tr("打开文件"),this);
    this->exit = new QAction(tr("退出"),this);
    this->fileNameEdit = new QLineEdit(this);
    this->fileNameEdit->setReadOnly(true);
    this->fileNameEdit->setGeometry(OpenFileEditX,OpenFileEditY,OpenFileEditW,OpenFileEditH);
    this->fileNameEdit->show();

    this->NT_HEADERS = new QFrame(this);
    this->NT_HEADERS->setGeometry(FRAMEX,FRAMEY,FRAMEW,FRAMEH);
    this->peMachineLB = new QLabel(tr("Machine"),this->NT_HEADERS);
    this->peMachineLB->setGeometry(PEMACHINELBX,PEMACHINELBY,PEMACHINELBW,PEMACHINELBH);
    this->peMachineLB->show();
    this->peMachineLE = new QLineEdit(this->NT_HEADERS);
    this->peMachineLE->setReadOnly(true);
    this->peMachineLE->setGeometry(PEMACHINELEX,PEMACHINELEY,PEMACHINELEW,PEMACHINELEH);
    this->peMachineLE->show();
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
    this->fileName = new QString(QFileDialog::getOpenFileName(
                this,tr("打开exe文件"),"./","*.exe;;*.dll"));
    this->fileNameEdit->setText(*this->fileName);
    this->file = new QFile(*this->fileName);
    this->file->open(QIODevice::ReadOnly);
    this->context = new QByteArray(this->file->readAll());
//  qDebug()<<this->context->size();
    this->header = (Byte)this->context->at(0x3c);

//    qDebug()<<(Byte)this->context->at(128);
//    qDebug()<<(Byte)this->context->at(129);
//    qDebug()<<(Byte)this->context->at(130);
//    qDebug()<<(Byte)this->context->at(131);
}
