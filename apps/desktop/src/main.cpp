#include <QApplication>
#include "MainWindow.h"
#include "GeometryEngine.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    GeometryEngine engine;
    engine.createBox();

    return app.exec();
}