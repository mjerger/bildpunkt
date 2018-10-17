#pragma once

#include "base.h"
#include <QDialog>

class SettingsWindow : public QDialog
{
    Q_OBJECT

public:
    SettingsWindow(QWidget *parent = nullptr);

private slots:
    void save_button_clicked();
    void cancel_button_clicked();
};
