#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

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

private slots:

    void CloseWindow();
    void OpenFileName();




};

#endif // MAINWINDOW_H
