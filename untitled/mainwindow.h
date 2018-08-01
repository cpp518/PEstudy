#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QFile>
#include <QMessageBox>
#include <QLineEdit>
#include <define.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static QString atos(BYTE *buffer,int num);    //buffer要转化的内容，num表示转化的个数

private:
    Ui::MainWindow *ui;
    QAction* openFile;
    QAction* exit;
    QMenuBar* menuBar;
    QMenu* menu;
    QString* fileName;
    QLineEdit* fileNameEdit;
    QFile* file;
    BYTE* context;
    BYTE header; //标记signature位置


    static int itoch[16];
private slots:


    void on_action_1_triggered();
    void on_action_2_triggered();
    void on_actionFile_Header_triggered();
    void on_actionOptional_HEADERSFR_triggered();
    void on_actionOptional_HEADERS_2_triggered();
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
