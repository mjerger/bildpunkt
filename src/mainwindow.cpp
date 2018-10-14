#include "mainwindow.h"

#include "view.h"
#include "base.h"
#include "app.h"

#include <QApplication>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("bildpunkt");
    setMinimumSize(1000, 600);
    resize(1000, 600);

    QWidget *view = new View();
    setCentralWidget(view);

    createMainMenu();
    createStatusBar();
}

MainWindow::~MainWindow()
{
}


void MainWindow::createMainMenu()
{
    // FILE MENU
    file_menu_ = menuBar()->addMenu("&File");
    new_= new QAction("&New");
    new_->setShortcut(QKeySequence::New);
    connect(new_, &QAction::triggered, this, &MainWindow::new_project);

    open_ = new QAction("&Open");
    open_->setShortcut(QKeySequence::Open);
    connect(open_, &QAction::triggered, this, &MainWindow::open_file);

    save_ = new QAction("&Save");
    save_->setShortcut(QKeySequence::Save);
    connect(save_, &QAction::triggered, this, &MainWindow::save_project);

    save_as_ = new QAction("&Save as");
    save_as_->setShortcut(QKeySequence::SaveAs);
    connect(save_as_, &QAction::triggered, this, &MainWindow::save_project_as);

    export_ = new QAction("&Export");
    export_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_E));
    connect(export_, &QAction::triggered, this, &MainWindow::export_file);

    settings_ = new QAction("&Settings");
    save_as_->setShortcut(QKeySequence(Qt::Key_F8));
    connect(export_, &QAction::triggered, this, &MainWindow::export_file);

    exit_ = new QAction("&Exit");
    exit_->setShortcut(QKeySequence::Close);
    connect(exit_, &QAction::triggered, this, &MainWindow::exit_app);

    file_menu_->addAction(new_);
    file_menu_->addAction(open_);
    file_menu_->addAction(save_);
    file_menu_->addAction(save_as_);
    file_menu_->addAction(export_);
    file_menu_->addSeparator();
    file_menu_->addAction(settings_);
    file_menu_->addSeparator();
    file_menu_->addAction(exit_);

    // ANALYZE MENU
    analyze_menu_ = menuBar()->addMenu("&Analyze");
    run_ = new QAction("&Run");
    run_->setShortcut(QKeySequence(Qt::Key_F5));
    analyze_menu_->addAction(run_);
    analyze_menu_->addSeparator();
    preset_menu_ = analyze_menu_->addMenu("&Presets");
    add_analyzer_menu_ = analyze_menu_->addMenu("A&dd");

    // VIEW MENU
    view_menu_ = menuBar()->addMenu("&View");
    overlay_average_ = new QAction("&Overlay average");
    overlay_average_->setCheckable(true);
    view_menu_->addAction(overlay_average_);

    // HELP MENU
    help_menu_ = menuBar()->addMenu("&Help");
    about_ = new QAction("&About");
    connect(about_, &QAction::triggered, this, &MainWindow::about_app);
    help_menu_->addAction(about_);
}

void MainWindow::createStatusBar()
{
}

void MainWindow::new_project()
{
}

void MainWindow::open_file()
{
    QString file = QFileDialog::getOpenFileName(this, "Open file", "", "Supported files (*.bp, *.mpeg, *.mp4, *.mkv);;"
                                                                       "Projects (*.bp);;"
                                                                       "Videos (*.mpeg, *.mp4 *.mkv);;"
                                                                       "All files (*.*)");

    if (file == nullptr) return;
}

void MainWindow::save_project()
{
}

void MainWindow::save_project_as()
{
}

void MainWindow::export_file()
{
}

void MainWindow::show_settings()
{
}

void MainWindow::exit_app()
{
    QApplication::quit();
}

void MainWindow::reevaluate()
{
}

void MainWindow::about_app()
{

}
