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
    inline bool  CreateUser();
    void CheckUser();

    QSystemTrayIcon *trayicon;
    QMenu *trayIconMenu;
    //bool logged = false;


private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void validateCreateuserForm();
};

#endif // MAINWINDOW_H
