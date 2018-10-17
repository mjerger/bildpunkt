#pragma once

#include "base.h"
#include "config.h"
#include "engine.h"
#include "mainwindow.h"

#define app App::get()
#define config App::get().get_config()

static const u8     app_version_major = 0;
static const u8     app_version_minor = 1;
static const char*  app_name          = "bildpunkt";
static const char*  app_author_name   = "Manuel Jerger";
static const char*  app_author_email  = "bildpunkt@jerger.io";

class App
{
public:
    App();
    ~App();

    App(App const&)            = delete;
    void operator=(App const&) = delete;

    static App& get()
    {
        static App app_;
        return app_;
    }

    void show();

    bool load_config(string file);
    Config& get_config();

    void open(const string& file);
    void close();
    bool loaded();
    const string& get_file();

private:
    void update();

    Config config_;
    Engine engine_;
    string file_;
    MainWindow* main_window_;
};
