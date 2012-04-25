#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>

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
    void createTrayIcon();
    void ShowLoginWindow();
    void ShowWelcomeWindow();
    inline bool  CheckUser_Ws(QString User, QString Password);
    void CheckUser();

    QSystemTrayIcon *trayicon;
    QMenu *trayIconMenu;
    //bool logged = false;
    QString Username;
    QString Token;
    QString IniFilename;

private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void validateUserForm();
};

#endif // MAINWINDOW_H
