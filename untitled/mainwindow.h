#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QFile>
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

private:
    Ui::MainWindow *ui;
    QAction* openFile;
    QAction* exit;
    QMenuBar* menuBar;
    QMenu* menu;
    QString* fileName;
    QLineEdit* fileNameEdit;
    QFile* file;
    QByteArray* context;
    Byte header; //标记signature位置

    QFrame* NT_HEADERS;
    QLabel* peSignatureLB;
    QLineEdit* peSignatureLE;
    QLabel* peMachineLB;
    QLineEdit* peMachineLE;

private slots:

    void CloseWindow();
    void OpenFileName();




};

#endif // MAINWINDOW_H
