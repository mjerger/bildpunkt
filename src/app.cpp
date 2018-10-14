#include "app.h"
#include "log.h"

#include <QFile>

App::App() :
  main_window_(nullptr)
{
    load_config(":/default.conf");
}

App::~App()
{
    delete main_window_;
}

bool App::load_config(string file)
{
    return config_.load(file);
}

void App::show()
{
    main_window_ = new MainWindow();

    QFile file(":/style.qss");
    file.open(QFile::ReadOnly);
    string styleSheet = QLatin1String(file.readAll());
    main_window_->setStyleSheet(styleSheet);

    main_window_->resize(config_.get<int>("window.width"),
                         config_.get<int>("window.height"));

    main_window_->show();
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
