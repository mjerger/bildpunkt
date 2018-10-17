#include "aboutwindow.h"

#include "app.h"

#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>

AboutWindow::AboutWindow(QWidget* parent) : QDialog(parent)
{
    setWindowTitle(format("About %", app_name));
    resize(400, 300);

    QHBoxLayout* main = new QHBoxLayout();

    QVBoxLayout* text = new QVBoxLayout();
    text->addStretch();

    QLabel* label = new QLabel( format("% v%.%", app_name, app_version_major, app_version_minor));
    QFont font = label->font();
    font.setPointSize(20);
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);
    text->addWidget(label);

    text->addSpacing(20);

    QDate buildTime = QDateTime::fromMSecsSinceEpoch(QDateTime::currentMSecsSinceEpoch()).date();

    label = new QLabel( format("©% %", buildTime.year(), app_author_name));
    label->setAlignment(Qt::AlignCenter);
    text->addWidget(label);

    label = new QLabel(app_author_email);
    label->setAlignment(Qt::AlignCenter);
    text->addWidget(label);

    text->addSpacing(20);

    label = new QLabel( format("Build on %-%-%", buildTime.year(), buildTime.month(), buildTime.day()));
    label->setAlignment(Qt::AlignCenter);
    text->addWidget(label);

    text->addStretch();

    QPushButton* button = new QPushButton("Close");
    connect(button, SIGNAL(clicked()), this, SLOT(close()));
    text->addWidget(button);

    main->addStretch();
    main->addLayout(text);
    main->addStretch();

    setLayout(main);
}
