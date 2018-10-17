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
}

bool App::load_config(string file)
{
    return config_.load(file);
}

void App::show()
{
    main_window_ = new MainWindow();

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
    engine_.close();
}
