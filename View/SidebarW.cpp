#include "SidebarW.h"
#include <QIcon>

namespace View {

SidebarW::SidebarW(QWidget *parent) : QWidget(parent){

    logo = new QLabel(this);
    QPixmap logoPixmap(":/Assets/logo.png");
    logo->setPixmap(logoPixmap.scaled(150,150,Qt::KeepAspectRatio, Qt::SmoothTransformation));

    home = new QPushButton("Home", this);
    home->setIcon(QIcon(":/Assets/home.png"));
    home->setStyleSheet(
        "QPushButton {"
        "   width: 100px; "
        "   font-weight: bold; "
        "   font-size: 14px; "
        "   text-align: center; "
        "   padding: 5px; "
        "   background-color: #5e17eb; "
        "   color: white; "
        "}"
        "QPushButton:hover {"
        "   color: black; "
        "}");
    addMedia = new QPushButton("Add Media", this);
    addMedia->setIcon(QIcon(":/Assets/add.png"));
    addMedia->setStyleSheet(
        "QPushButton {"
        "   width: 100px; "
        "   font-weight: bold; "
        "   font-size: 14px; "
        "   text-align: center; "
        "   padding: 5px; "
        "   background-color: #5e17eb; "
        "   color: white; "
        "}"
        "QPushButton:hover {"
        "   color: black; "
        "}");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft);
    layout->addWidget(logo, 0, Qt::AlignHCenter);
    layout->addSpacing(10);
    layout->addWidget(home);
    layout->addSpacing(10);
    layout->addWidget(addMedia);
    layout->addStretch();
    setLayout(layout);

    connect(home, &QPushButton::clicked, this, &SidebarW::HomeClicked);
    connect(addMedia, &QPushButton::clicked, this, &SidebarW::AddMediaClicked);
}

}
