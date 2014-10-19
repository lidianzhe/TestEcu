#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "emaglobal.h"
#include "emalib.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_Open_clicked();

    void on_btnRelay_clicked();

private:
    Ui::MainWindow *ui;
    EMA_HANDLE m_emaHandle;
    EMA_EVENT m_emaEvent;

    void log(const QString &msg);
};

#endif // MAINWINDOW_H
