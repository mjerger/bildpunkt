#pragma once

#include "base.h"
#include "log.h"
#include "config.h"
#include "engine.h"
#include "mainwindow.h"

class App
{

public:
    App();
    ~App();

    App& get();

    void show();
    bool load_config(string file);

    Config& get_config();

    void open(const string& file);
    void close();

private:
    void update();

    App* instance;

    Config config_;
    Engine engine_;
    MainWindow* mainwindow_;

    bool loaded_;
    bool running_;
};

namespace version
{
    const u8 major = 0;
    const u8 minor = 1;
}
