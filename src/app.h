#pragma once

#include "base.h"
#include "config.h"
#include "engine.h"
#include "mainwindow.h"

class App
{
public:
    App();
    ~App();

    App(App const&)            = delete;
    void operator=(App const&) = delete;

    void show();
    bool load_config(string file);

    Config& get_config();

    void open(const string& file);
    void close();

private:
    void update();

    Config config_;
    Engine engine_;
    MainWindow* main_window_;
};
