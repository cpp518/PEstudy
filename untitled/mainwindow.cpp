#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include "define.h"
#include <QMessageBox>

int MainWindow::itoch[16] = {48,49,50,51,52,53,54,55,56,57,65,66,67,68,69,70};
QString MainWindow::atos(BYTE *buffer,int num){
    QString str;
    for(int i=0;i<num;i++){
        int t = buffer[num-i-1];
        if(t!=0){
            if(t>=16){
                str.append(char(itoch[t/16]));
                str.append(char(itoch[t%16]));
            }
            else{
                str.append("0");
                str.append(char(itoch[t]));
            }
        }
        else{
            str.append("00");
        }
    }
    return str;
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置窗口大小，并且无法调整,设置标题栏
    this->setWindowTitle(tr("PEStudy"));
    //this->setFixedSize(WindowsW,WindowsH);

    this->ui->Optional_HEADERSFR1->setVisible(false);
    this->ui->File_HEADERSFR->setVisible(true);


}

MainWindow::~MainWindow()
{
   // delete ui;
   // delete openFile;
}


void MainWindow::on_action_1_triggered()
{
    QString openFileTest = QFileDialog::getOpenFileName(
                this,tr("打开exe文件"),"./","*.exe;;*.dll");
    if(openFileTest==""){
        return;
    }
    this->fileName = new QString(openFileTest);

    this->ui->fileNameEdit->setText(*this->fileName);
    this->file = new QFile(*this->fileName);
    this->file->open(QIODevice::ReadOnly);
    if(this->file->isOpen()){
        qint64 size = this->file->size();
        this->context = new BYTE[size];
        qint64 length = this->file->read((char*)this->context,size);

        if(length != -1){
        this->header = this->context[0x3C];   //获取PE标志的位置
       // qDebug()<<this->header+MACHINE_MOVE;
        //展示内容
        this->ui->CharacteristicsLE->setText(MainWindow::atos(&(this->context[this->header+CHARACTERISTICS_MOVE]),CHARACTERISTICS_SIZE));
        this->ui->MachineLE->setText(MainWindow::atos(&(this->context[this->header+MACHINE_MOVE]),MACHINE_SIZE));
        this->ui->NumberOfSectionsLE->setText(MainWindow::atos(&(this->context[this->header+NUMBEROFSESSIONS_MOVE]),NUMBEROFSESSIONS_SIZE));
        this->ui->TimeDateStampLE->setText(MainWindow::atos(&(this->context[this->header+TIMEDATESTAMP_MOVE]),TIMEDATESTAMP_SIZE));
        this->ui->PointerOfSymbolTableLE->setText(MainWindow::atos(&(this->context[this->header+POINTEROFSYMBOLTABLE_MOVE]),POINTEROFSYMBOLTABLE_SIZE));
        this->ui->NumberOfSymbolsLE->setText(MainWindow::atos(&(this->context[this->header+NUMBEROFSYMBOLS_MOVE]),NUMBEROFSYMBOLS_SIZE));
        this->ui->SizeOfOptionalHeaderLE->setText(MainWindow::atos(&(this->context[this->header+SIZEOFOPTIONALHEADER_MOVE]),SIZEOFOPTIONALHEADER_SIZE));
        }
        else{
             QMessageBox::information(this,tr("Error"),tr("读取文件失败"),QMessageBox::Yes);
        }
        this->file->close();

    }
    else{
        QMessageBox::information(this,tr("Error"),tr("打开文件失败"),QMessageBox::Yes);
    }
}

void MainWindow::on_action_2_triggered()
{
    this->close();
}


void MainWindow::on_actionFile_Header_triggered()
{
    this->ui->File_HEADERSFR->setVisible(true);
    this->ui->Optional_HEADERSFR1->setVisible(false);
}

void MainWindow::on_actionOptional_HEADERSFR_triggered()
{
    this->ui->Optional_HEADERSFR1->setVisible(true);
    this->ui->File_HEADERSFR->setVisible(false);
}
