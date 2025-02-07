#include "SearchWidget.h"

namespace View {

SearchWidget::SearchWidget(QWidget *parent) : QWidget(parent) {
    welcome_message = new QLabel("Welcome to ValBook!", this);
    welcome_message->setStyleSheet("color: #5e17eb; font-weight: bold; font-size: 30px;");
    searchBar = new QLineEdit(this);
    searchButton = new QPushButton("Search", this);
    searchBar->setFixedWidth(500);
    searchButton->setStyleSheet(
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
    layout->addWidget(welcome_message, 0, Qt::AlignTop);
    QHBoxLayout *search = new QHBoxLayout(this);
    search->addWidget(searchBar);
    search->addWidget(searchButton);
    search->addStretch();
    layout->addLayout(search);
    layout->addSpacing(20);
    layout->addStretch();
    setLayout(layout);

    connect(searchButton, &QPushButton::clicked, this, &SearchWidget::emitSearchSignal);
}

void SearchWidget::emitSearchSignal() {
    emit search_event(searchBar->text());
}

}
