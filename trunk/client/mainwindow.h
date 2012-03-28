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
    void Checkuser();
    void LoginWindow();

private:
    Ui::MainWindow *ui;
    void createTrayIcon();

    QSystemTrayIcon *trayicon;
    QMenu *trayIconMenu;


private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void on_container_currentChanged(int arg1);
};

#endif // MAINWINDOW_H
