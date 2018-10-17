#pragma once

#include "base.h"
#include <QDialog>

class AboutWindow : public QDialog
{
    Q_OBJECT

public:
    AboutWindow(QWidget *parent = nullptr);
};
