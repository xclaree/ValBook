#include "Full.h"
#include "../../Item/Book.h"
#include "../../Item/Movie.h"
#include "../../Item/Article.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>

namespace View::MediaRenderer {

QString Full::default_image = "Assets/no_image.png";

void Full::visit(const Item::Book& book){
    widget = new QWidget();
    type = new QLabel("Book");
    id = new QLabel("ID: " + QString::number(book.getId()));
    title = new QLabel("Title: " + book.getTitle());
    QLabel* author = new QLabel("Author: " + book.getAuthor());
    year = new QLabel("Release year: " + book.getYear());
    description = new QLabel("Description: " + book.getDesc());
    QString img_path = book.getImg();
    QPixmap pixmap;
    if(img_path.isEmpty() || !pixmap.load(img_path)) { //se non riesce a caricare l'immagine
        pixmap.load(default_image);
    }
    image = new QLabel();
    image->setPixmap(pixmap.scaled(300,300, Qt::AspectRatioMode::KeepAspectRatio));

    QHBoxLayout* columns = new QHBoxLayout();
    QWidget* imgP = new QWidget();
    QVBoxLayout* imgPanel = new QVBoxLayout();
    imgPanel->addWidget(image);
    imgP->setLayout(imgPanel);
    QWidget* details = new QWidget();
    QVBoxLayout* detailsPanel = new QVBoxLayout();
    detailsPanel->addWidget(type);
    detailsPanel->addWidget(id);
    detailsPanel->addWidget(title);
    detailsPanel->addWidget(author);
    detailsPanel->addWidget(year);
    detailsPanel->addWidget(description);
    details->setLayout(detailsPanel);

    columns->addWidget(imgP);
    columns->addWidget(details);
    widget->setLayout(columns);
}

void Full::visit(const Item::Movie& movie) {
    widget = new QWidget();
    type = new QLabel("Movie");
    id = new QLabel("ID: " + QString::number(movie.getId()));
    title = new QLabel("Title: " + movie.getTitle());
    QLabel* director = new QLabel("Director: " + movie.getDirector());
    year = new QLabel("Release year: " + movie.getYear());
    description = new QLabel("Description: " + movie.getDesc());
    QString img_path = movie.getImg();
    QPixmap pixmap;
    if(img_path.isEmpty() || !pixmap.load(img_path)) { //se non riesce a caricare l'immagine
        pixmap.load(default_image);
    }
    image = new QLabel();
    image->setPixmap(pixmap.scaled(300,300, Qt::AspectRatioMode::KeepAspectRatio));

    QHBoxLayout* columns = new QHBoxLayout();
    QWidget* imgP = new QWidget();
    QVBoxLayout* imgPanel = new QVBoxLayout();
    imgPanel->addWidget(image);
    imgP->setLayout(imgPanel);
    QWidget* details = new QWidget();
    QVBoxLayout* detailsPanel = new QVBoxLayout();
    detailsPanel->addWidget(type);
    detailsPanel->addWidget(id);
    detailsPanel->addWidget(title);
    detailsPanel->addWidget(director);
    detailsPanel->addWidget(year);
    detailsPanel->addWidget(description);
    details->setLayout(detailsPanel);

    columns->addWidget(imgP);
    columns->addWidget(details);
    widget->setLayout(columns);
}

void Full::visit(const Item::Article& article) {
    widget = new QWidget();
    type = new QLabel("Article");
    id = new QLabel("ID: " + QString::number(article.getId()));
    title = new QLabel("Title: " + article.getTitle());
    QLabel* author = new QLabel("Author/Journalist: " + article.getAuthor());
    QLabel* journal = new QLabel("Source journal: " + article.getJournal());
    year = new QLabel("Release year: " + article.getYear());
    description = new QLabel("Description: " + article.getDesc());
    QString img_path = article.getImg();
    QPixmap pixmap;
    if(img_path.isEmpty() || !pixmap.load(img_path)) { //se non riesce a caricare l'immagine
        pixmap.load(default_image);
    }
    image = new QLabel();
    image->setPixmap(pixmap.scaled(300,300, Qt::AspectRatioMode::KeepAspectRatio));

    QHBoxLayout* columns = new QHBoxLayout();
    QWidget* imgP = new QWidget();
    QVBoxLayout* imgPanel = new QVBoxLayout();
    imgPanel->addWidget(image);
    imgP->setLayout(imgPanel);
    QWidget* details = new QWidget();
    QVBoxLayout* detailsPanel = new QVBoxLayout();
    detailsPanel->addWidget(type);
    detailsPanel->addWidget(id);
    detailsPanel->addWidget(title);
    detailsPanel->addWidget(journal);
    detailsPanel->addWidget(author);
    detailsPanel->addWidget(year);
    detailsPanel->addWidget(description);
    details->setLayout(detailsPanel);

    columns->addWidget(imgP);
    columns->addWidget(details);
    widget->setLayout(columns);
}


QWidget* Full::getWidget() const {
    return widget;
}


QLabel* Full::getType() const {
    return type;
}


QLabel* Full::getId() const {
    return id;
}


QLabel* Full::getTitle() const {
    return title;
}


QLabel* Full::getDesc() const {
    return description;
}


}
