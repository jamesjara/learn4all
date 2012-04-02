#include "mainwindow.h"
#include <QtGui>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(learncs);

    QApplication app(argc, argv);

    MainWindow MainWindow;
    return app.exec();
}




