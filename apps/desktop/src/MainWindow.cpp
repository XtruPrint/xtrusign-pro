#include "MainWindow.h"
#include "OcctViewer.h"

MainWindow::MainWindow() {
    setWindowTitle("XtruSign Pro");
    resize(800, 600);

    OcctViewer* viewer = new OcctViewer(this);
    setCentralWidget(viewer);
}