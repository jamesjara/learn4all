#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createTrayIcon ();
    CheckUser();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    this->show();
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


void MainWindow::CheckUser()
{
    //Load Config
    QString IniFilename;
    IniFilename =   "config.ini";

    if( !QFile::exists(IniFilename) ){
        ShowLoginWindow();
    } else {
        //If config.ini exists check the user with the webservice
            //if correct continue
            //else show login dialog      
    }
}

void MainWindow::ShowLoginWindow(){
    this->show();
    ui->container->setCurrentIndex(0);
}


inline bool  MainWindow::CreateUser( )
{
    return false;
}

void MainWindow::validateCreateuserForm( )
{
    //Validar
    QString  usuario     =   ui->usuarioLineEdit->text();
    QString  password    =   ui->passwordLineEdit->text();
    QString  password_r  =   ui->repetirPasswordLineEdit->text();
    //validate data
    if( !usuario.isEmpty() || !password.isEmpty() || !password_r.isEmpty()  ){
        if( password != password_r ){
            qDebug() <<  " las contraseñas no conciden"  ;
        } else {
            //if all its fine, add user to webservice
            if(!CreateUser()){
                 qDebug() <<  " el usuario ya esta registrado "  ;
             } else {
                ShowLoginWindow();
             }
            qDebug() <<  "CreateUser Container current changed:"  ;
        }
    } else qDebug() <<  " Todos los campos son obligatorios "  ;
}


