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
    this->ui->Optional_HEADERSFR2->setVisible(false);
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
        this->ui->MagicLE->setText(MainWindow::atos(&(this->context[this->header+MAGIC_MOVE]),MAGIC_SIZE));
        this->ui->MajorLinkerVersionLE->setText(MainWindow::atos(&(this->context[this->header+MAJORLINKERVERSION_MOVE]),MAJORLINKERVERSION_SIZE));
        this->ui->MinorLinkerVersionLE->setText(MainWindow::atos(&(this->context[this->header+MINORLINKERVERSION_MOVE]),MINORLINKERVERSION_SIZE));
        this->ui->SizeOfCodeLE->setText(MainWindow::atos(&(this->context[this->header+SIZEOFCODE_MOVE]),SIZEOFCODE_SIZE));
        this->ui->SizeOfInitializedDataLE->setText(MainWindow::atos(&(this->context[this->header+SIZEOFINITIALIZEDDATA_MOVE]),SIZEOFINITIALIZEDDATA_SIZE));
        this->ui->SizeOfUninitializedDataLE->setText(MainWindow::atos(&(this->context[this->header+SIZEOFUNINITIALIZEDDATA_MOVE]),SIZEOFUNINITIALIZEDDATA_SIZE));
        this->ui->AddressOfEntryPointLE->setText(MainWindow::atos(&(this->context[this->header+ADDRESSOFENTRYPOINT_MOVE]),ADDRESSOFENTRYPOINT_SIZE));
        this->ui->BaseOfCodeLE->setText(MainWindow::atos(&(this->context[this->header+BASEOFCODE_MOVE]),BASEOFCODE_SIZE));
        this->ui->BaseOfDataLE->setText(MainWindow::atos(&(this->context[this->header+BASEOFDATA_MOVE]),BASEOFDATA_SIZE));
        this->ui->ImageBaseLE->setText(MainWindow::atos(&(this->context[this->header+IMAGEBASE_MOVE]),IMAGEBASE_SIZE));
        this->ui->SectionAlignmentLE->setText(MainWindow::atos(&(this->context[this->header+SECTIONALIGNMENT_MOVE]),SECTIONALIGNMENT_SIZE));
        this->ui->FileAlignmentLE->setText(MainWindow::atos(&(this->context[this->header+FILEALIGNMENT_MOVE]),FILEALIGNMENT_SIZE));
        this->ui->MajorOperatingSystemVersionLE->setText(MainWindow::atos(&(this->context[this->header+MAJOROPERATINGSYSTEMVERSION_MOVE]),MAJOROPERATINGSYSTEMVERSION_SIZE));
        this->ui->MinorOperatingSystemVersionLE->setText(MainWindow::atos(&(this->context[this->header+MINOROPERATINGSYSTEMVERSION_MOVE]),MINOROPERATINGSYSTEMVERSION_SIZE));
        this->ui->MajorImageVersionLE->setText(MainWindow::atos(&(this->context[this->header+MAJORIMAGEVERSION_MOVE]),MAJORIMAGEVERSION_SIZE));
        this->ui->MinorImageVersionLE->setText(MainWindow::atos(&(this->context[this->header+MINORIMAGEVERSION_MOVE]),MINORIMAGEVERSION_SIZE));
        this->ui->MajorSubSystemVersionLE->setText(MainWindow::atos(&(this->context[this->header+MAJORSUBSYSTEMVERSION_MOVE]),MAJORSUBSYSTEMVERSION_SIZE));
        this->ui->MinorSubSystemVersionLE->setText(MainWindow::atos(&(this->context[this->header+MINORSUBSYSTEMVERSION_MOVE]),MINORSUBSYSTEMVERSION_SIZE));
        this->ui->Win32versionValueLE->setText(MainWindow::atos(&(this->context[this->header+WIN32VERSIONVALUE_MOVE]),WIN32VERSIONVALUE_SIZE));
        this->ui->SizeOfImageLE->setText(MainWindow::atos(&(this->context[this->header+SIZEOFIMAGE_MOVE]),SiZEOFIMAGE_SIZE));
        this->ui->SizeOfHeadersLE->setText(MainWindow::atos(&(this->context[this->header+SIZEOFHEADERS_MOVE]),SIZEOFHEADERS_SIZE));
        this->ui->CheckSumLE->setText(MainWindow::atos(&(this->context[this->header+CHECKSUM_MOVE]),CHECKSUM_SIZE));
        this->ui->SubSystemLE->setText(MainWindow::atos(&(this->context[this->header+SUBSYSTEM_MOVE]),SUBSYSTEM_SIZE));
        this->ui->DllCharacteristicsLE->setText(MainWindow::atos(&(this->context[this->header+DLLCHARACTERISTICS_MOVE]),DLLCHARACTERISTICS_SIZE));
        this->ui->SizeOfStackReserveLE->setText(MainWindow::atos(&(this->context[this->header+SIZEOFSTACKRESERVER_MOVE]),SIZEOFSTACKRESERVER_SIZE));
        this->ui->SizeOfStackCommitLE->setText(MainWindow::atos(&(this->context[this->header+SIZEOFSTACKCOMMIT_MOVE]),SIZEOFSTACKCOMMIT_SIZE));
        this->ui->SizeOfHeapReserveLE->setText(MainWindow::atos(&(this->context[this->header+SIZEOFHEAPRESERVE_MOVE]),SIZEOFHEAPRESERVE_SIZE));
        this->ui->SizeOfHeapCommitLE->setText(MainWindow::atos(&(this->context[this->header+SIZEOFHEAPCOMMIT_MOVE]),SIZEOFHEAPCOMMIT_SIZE));

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
    this->ui->Optional_HEADERSFR2->setVisible(false);
    this->ui->Optional_HEADERSFR1->setVisible(false);
}

void MainWindow::on_actionOptional_HEADERSFR_triggered()
{
    this->ui->Optional_HEADERSFR1->setVisible(true);
    this->ui->File_HEADERSFR->setVisible(false);
    this->ui->Optional_HEADERSFR2->setVisible(false);
}

void MainWindow::on_actionOptional_HEADERS_2_triggered()
{
    this->ui->Optional_HEADERSFR2->setVisible(true);
    this->ui->File_HEADERSFR->setVisible(false);
    this->ui->Optional_HEADERSFR1->setVisible(false);
}

void MainWindow::on_pushButton_3_clicked()
{
    this->ui->Optional_HEADERSFR1->setVisible(true);
    this->ui->Optional_HEADERSFR2->setVisible(false);
}

void MainWindow::on_pushButton_clicked()
{
    this->ui->Optional_HEADERSFR2->setVisible(true);
    this->ui->Optional_HEADERSFR1->setVisible(false);
}
