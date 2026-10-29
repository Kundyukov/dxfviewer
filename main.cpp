#include "mainwindow.h"
#include "libdxfrw.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    dxfRW reader("test.dxf");
    return app.exec();
}