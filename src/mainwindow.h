#pragma once

#include "mainwindow.h"
#include "engine.h"
#include <QMainWindow>
#include <QAction>
#include <QMenuBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void update();

public slots:
    void new_project();
    void open_file();
    void save_project();
    void save_project_as();
    void export_file();
    void show_settings();
    void exit_app();
    void reevaluate();
    void about_app();

private:
    void createMainMenu();
    void createStatusBar();

    QMenu*   file_menu_;
    QAction* new_;
    QAction* open_;
    QAction* save_;
    QAction* save_as_;
    QAction* export_;
    QMenu*   export_menu_;
    QAction* export_timeline_;
    QAction* export_current_screen_;
    QAction* export_cut_video_;
    QAction* export_annotated_video_;
    QAction* export_video_segments_;
    QAction* settings_;
    QAction* exit_;

    QMenu*   analyze_menu_;
    QAction* preset_;
    QMenu*   preset_menu_;
    QAction* run_;
    QAction* add_analyzer_;
    QMenu*   add_analyzer_menu_;

    QMenu*   view_menu_;
    QAction* overlay_average_;

    QMenu*   help_menu_;
    QAction* about_;

};
