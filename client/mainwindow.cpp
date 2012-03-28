#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createTrayIcon ();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createTrayIcon ()
{
    if(!QSystemTrayIcon::isSystemTrayAvailable()){
        QMessageBox::critical(0,QObject::tr("Learn4All"),QObject::tr("El SO no es compatible :( "));
    }
    QApplication::setQuitOnLastWindowClosed(false);
    trayicon = new QSystemTrayIcon(this);
    QIcon icon = QIcon(":/images/bad.svg");
    trayicon->setIcon(icon);
    trayicon->setToolTip("Learn4All | Computer Society Costa Rica");
    trayicon->show();
    setWindowIcon(icon);
    connect(trayicon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    this->show();
}

void CheckUser()
{
    //If the config.ini doesnt exists the show user dialog.

        //If config.ini exists check the user with the webservice
            //if correct continue
            //else show login dialog
}

void LoginWindow(){

}

void MainWindow::on_container_currentChanged(int arg1)
{
    qDebug() <<  "buffer Container current changed:" + arg1 ;
}
