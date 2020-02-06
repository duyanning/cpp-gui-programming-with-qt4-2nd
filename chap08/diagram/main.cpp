#include <QApplication>

#include "diagramwindow.h" // usingcpp

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    DiagramWindow view;
    view.show();
    return app.exec();
}
