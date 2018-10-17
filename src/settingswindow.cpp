#include "settingswindow.h"

#include "app.h"

#include <QBoxLayout>
#include <QPushButton>

SettingsWindow::SettingsWindow(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Settings");
    resize(config.get<s32>("settings.window.width"),
           config.get<s32>("settings.window.height"));

    QVBoxLayout* main = new QVBoxLayout();

    QHBoxLayout* top_layout = new QHBoxLayout();
    QHBoxLayout* bottom_layout = new QHBoxLayout();
    main->addLayout(top_layout);
    main->addLayout(bottom_layout);

    QPushButton* save_button = new QPushButton("&Save");
    QPushButton* cancel_button = new QPushButton("&Cancel");
    connect(save_button, SIGNAL(clicked()), this, SLOT(save_button_clicked()));
    connect(cancel_button, SIGNAL(clicked()), this, SLOT(cancel_button_clicked()));
    bottom_layout->addStretch();
    bottom_layout->addWidget(save_button);
    bottom_layout->addWidget(cancel_button);

    setLayout(main);
}

void SettingsWindow::save_button_clicked()
{
    // TODO save settings
    close();
}

void SettingsWindow::cancel_button_clicked()
{
    close();
}

