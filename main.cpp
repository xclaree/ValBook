#include "View/MainWindow.h"
#include "Item/Media.h"

#include <QApplication>
#include <QPalette>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/Assets/logo1.png"));
    QPalette pal = a.palette();
    pal.setColor(QPalette::Window, Qt::white);
    a.setPalette(pal);
    MainWindow w;
    w.setFixedSize(1024,500);
    w.show();
    return a.exec();
}
