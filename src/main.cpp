#include "app.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication* qapp = new QApplication(argc, argv);

    App a;
    a.load_config("default.cfg");
    a.show();
    // TODO parse commandline

    return qapp->exec();
}
