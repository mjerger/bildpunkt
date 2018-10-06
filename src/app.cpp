#include "app.h"

#include <QFile>

App::App() :
  mainwindow_(nullptr),
  loaded_(false),
  running_(false)
{
    instance = this;
}

App::~App()
{
    delete mainwindow_;
}

App& App::get()
{
    return *instance;
}

bool App::load_config(string file)
{
    return config_.load(file);
}

void App::show()
{
    mainwindow_ = new MainWindow();

    QFile file(":/style.qss");
    file.open(QFile::ReadOnly);
    string styleSheet = QLatin1String(file.readAll());
    mainwindow_->setStyleSheet(styleSheet);

    mainwindow_->show();
}

Config& App::get_config()
{
    return config_;
}

void App::open(const string& file)
{
    engine_.load(file);
}

void App::close()
{

}
