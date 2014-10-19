#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "emaglobal.h"
#include "emalib.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_emaHandle=NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Open_clicked()
{
    if(m_emaHandle==NULL)
    {
        int result = ema_createEMA(&m_emaHandle);
        if(result==EMA_SUCCESS)
            ui->plainTextEdit_Log->appendHtml("<p style=\"color=green\">create ema success!</p>");
    }
    int ret=ema_open(m_emaHandle);
    if(ret==EMA_SUCCESS)
        ui->plainTextEdit_Log->appendPlainText("open success!");
    else if(ret==EMA_ERROR_ALREADY_OPENED)
        ui->plainTextEdit_Log->appendPlainText("EMA_ERROR_DEVICE_OPENED");
    else
        ui->plainTextEdit_Log->appendPlainText("open fail");
}

void MainWindow::on_btnRelay_clicked()
{
    m_emaEvent.cbSize = sizeof(EMA_EVENT);
    m_emaEvent.eventType = EMA_EVENT_TYPE_RELAY_WRITE;
    m_emaEvent.relayInterval=10;
    m_emaEvent.relayValue = EMA_EVENT_VALUE_RELAY_ABNORMAL;
    int ret =ema_writeEvent(m_emaHandle,&m_emaEvent);
    if(ret==EMA_SUCCESS)
        log("write relay ok!");
}

void MainWindow::log(const QString &msg)
{
    ui->plainTextEdit_Log->appendPlainText(msg);
}
