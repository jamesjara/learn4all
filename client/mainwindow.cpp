#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{    
    IniFilename = QString("config.ini");
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


//==========BOF======GENERAL================//
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
    QSettings * settings = 0;
    settings = new QSettings( IniFilename , QSettings::IniFormat );
    settings->beginGroup("Login");
    //Read user
    QString strUser      = settings->value( "user" , "error" ).toString();
    //Read password
    QString strPassword  = settings->value( "password" , "error" ).toString();
    settings->endGroup();

    //if is default value then error
    if( strUser.contains("error") ){
        ShowLoginWindow();
    } else {
        //Validar, If config.ini exists check the user with the webservice
        //check user to webservice
        if(!CheckUser_Ws(strUser,strPassword)){
            ShowLoginWindow();
             ui->status->setText(" datos incorrectos ");
         } else {
            ShowWelcomeWindow();
         }
    }
}
//==========EOF======GENERAL================//


//==========BOF======WEBSERVICE================//
inline bool MainWindow::CheckUser_Ws(QString User , QString Password )
{
    //Conect to webservice
    this->Username  = User;
    this->Token     = "asdxvc33214";
    //Webservice return start(true,false) ,Token(for other requests)
    if(User.contains("admin")){
        return true;
    } else return false;
}
/*Qstring  MainWindow::CheckUser_Ws(QString User , QString Password )
{
    //Conect to webservice
    return "";
}*/

//==========EOF======WEBSERVICE================//



//==========BOF======Show windows================//
void MainWindow::ShowLoginWindow(){
    this->show();
    ui->container->setCurrentIndex(0);
}
void MainWindow::ShowWelcomeWindow(){
    this->show();
    ui->container->setCurrentIndex(1);
    //Fill Form Data
    ui->username_txt->setText(this->Username);
    ui->articulos_val_txt->setText("525");
    ui->score_val_txt->setText("797");
    //Get articule
}
//==========EOF======Show windows================//




//==========BOF======Validations================//
void MainWindow::validateUserForm( )
{
    //Validar
    QString  usuario     =   ui->usuarioLineEdit->text();
    QString  password    =   ui->passwordLineEdit->text();
    //validate data
    if( !usuario.isEmpty() && !password.isEmpty()   ){
            //if all its fine, check user to webservice
            if(!CheckUser_Ws(usuario,password)){
                 ui->status->setText(" datos incorrectos ");
             } else {
                //Save data to file
                QSettings * settings = 0;
                settings = new QSettings( IniFilename , QSettings::IniFormat );
                settings->beginGroup("Login");
                //Set user
                settings->setValue( "user" ,     usuario );
                //Set password
                settings->setValue( "password" , password);
                settings->endGroup();

                //Show Welcome window
                ShowWelcomeWindow();
             }
    } else  ui->status->setText("  Todos los campos son obligatorios ");
}
//==========EOF======Validations================//
