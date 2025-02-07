#include "Card.h"
#include "../../Item/Book.h"
#include "../../Item/Movie.h"
#include "../../Item/Article.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

namespace View::MediaRenderer {

Card::Card(Item::Media* media, MainWindow* mainwindow) :
    media(media), mainWindow(mainwindow), widget(new QWidget), type(new QLabel), id(new QLabel), title(new QLabel) {
    id->setText("ID: " + QString::number(media->getId()));
    title->setText("Title: " + media->getTitle());
    vbox = new QVBoxLayout();

    connect(this, &Card::cardClicked, mainWindow, &MainWindow::onCardClicked);

}

void Card::visit(const Item::Book& book){
    type = new QLabel("Book");
    QLabel* author = new QLabel("Author: " + book.getAuthor());
    vbox->addWidget(type);
    vbox->addWidget(id);
    vbox->addWidget(title);
    vbox->addWidget(author);

    widget->setLayout(vbox);
}

void Card::visit(const Item::Movie& movie) {
    type = new QLabel("Movie");
    QLabel* director = new QLabel("Director: " + movie.getDirector());
    vbox->addWidget(type);
    vbox->addWidget(id);
    vbox->addWidget(title);
    vbox->addWidget(director);

    widget->setLayout(vbox);
}

void Card::visit(const Item::Article& article) {
    type = new QLabel("Article");
    QLabel* journal = new QLabel("Journal: " + article.getJournal());
    vbox->addWidget(type);
    vbox->addWidget(id);
    vbox->addWidget(title);
    vbox->addWidget(journal);

    widget->setLayout(vbox);
}

QWidget* Card::getWidget() const {
    return widget;
}

QLabel* Card::getType() const {
    return type;
}

QLabel* Card::getId() const {
    return id;
}

QLabel* Card::getTitle() const {
    return title;
}

void Card::mousePressEvent(QMouseEvent*){
    emit cardClicked(this);
}

}
