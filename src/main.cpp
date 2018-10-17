#include "base.h"
#include "log.h"
#include "app.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication* qapp = new QApplication(argc, argv);

    // TODO parse commandline

    Log::get();

    App& a = App::get();
    a.load_config("bildpunkt.conf");
    a.show();

    return qapp->exec();
}
