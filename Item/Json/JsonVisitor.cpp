#include "JsonVisitor.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonValueRef>
#include <QString>

namespace Item {
namespace Json {

JsonVisitor::JsonVisitor(QString path) : path(path) {
    QFile jsonFile(path);
    if(!jsonFile.open(QIODevice::ReadWrite))qTerminate();
    QByteArray content=jsonFile.readAll();
    if(!content.isEmpty()){
        document=new QJsonDocument(QJsonDocument::fromJson(content));
    } else {
        QJsonArray jsonArray;
        QJsonObject jsonObject;
        jsonObject["medias"]=jsonArray;
        document=new QJsonDocument(jsonObject);
        jsonFile.write(document->toJson());
    }
    jsonFile.close();

}

std::vector<Item::Media*> JsonVisitor::getMedias() const {
    std::vector<Item::Media*> medias;
    QJsonObject obj = document->object();
    QJsonValue value = obj["medias"];
    if(!value.isNull() && value.isArray()) {
        QJsonArray mediaArray(value.toArray());

        for(auto it = mediaArray.begin(); it != mediaArray.end(); ++it) {
            QJsonObject media((*it).toObject());
            QString type = media["type"].toString();
            if(type == "book") {
                medias.push_back(new Book(media["id"].toInt(), media["title"].toString(), media["year"].toString(), media["author"].toString(), media["description"].toString(), media["image"].toString()));
            } else if (type == "movie") {
                medias.push_back(new Movie(media["id"].toInt(), media["title"].toString(), media["year"].toString(), media["director"].toString(), media["description"].toString(), media["image"].toString()));
            } else if (type == "article") {
                medias.push_back(new Article(media["id"].toInt(), media["title"].toString(), media["year"].toString(), media["author"].toString(), media["journal"].toString(), media["description"].toString(), media["image"].toString()));
            } else {
                qTerminate();
            }
        }
    }
    return medias;
}


void JsonVisitor::updateJson(std::vector<Item::Media*>& medias) {
    QJsonObject obj;
    QJsonArray arr;
    obj["medias"]=arr;
    document->setObject(obj);
    for(auto it = medias.begin(); it != medias.end(); ++it){
        (*it)->accept(*this);
    }
    QFile jsonFile(path);
    if(!jsonFile.open(QIODevice::WriteOnly))qTerminate();
    jsonFile.write(document->toJson());

}


void JsonVisitor::visit(const Book& book) {
    QJsonObject book_obj;
    book_obj.insert("type", QJsonValue::fromVariant("book"));
    book_obj.insert("id", QJsonValue::fromVariant(book.getId()));
    book_obj.insert("title", QJsonValue::fromVariant(book.getTitle()));
    book_obj.insert("year", QJsonValue::fromVariant(book.getYear()));
    book_obj.insert("author", QJsonValue::fromVariant(book.getAuthor()));
    book_obj.insert("description", QJsonValue::fromVariant(book.getDesc()));
    book_obj.insert("image", QJsonValue::fromVariant(book.getImg()));

    QJsonObject obj(document->object());
    QJsonArray arr(obj["medias"].toArray());
    arr.append(book_obj);
    obj["medias"]=arr;
    document->setObject(obj);
}

void JsonVisitor::visit(const Movie& movie) {
    QJsonObject movie_obj;
    movie_obj.insert("type", QJsonValue::fromVariant("movie"));
    movie_obj.insert("id", QJsonValue::fromVariant(movie.getId()));
    movie_obj.insert("title", QJsonValue::fromVariant(movie.getTitle()));
    movie_obj.insert("year", QJsonValue::fromVariant(movie.getYear()));
    movie_obj.insert("director", QJsonValue::fromVariant(movie.getDirector()));
    movie_obj.insert("description", QJsonValue::fromVariant(movie.getDesc()));
    movie_obj.insert("image", QJsonValue::fromVariant(movie.getImg()));

    QJsonObject obj(document->object());
    QJsonArray arr(obj["medias"].toArray());
    arr.append(movie_obj);
    obj["medias"]=arr;
    document->setObject(obj);
}

void JsonVisitor::visit(const Article& article) {
    QJsonObject article_obj;
    article_obj.insert("type", QJsonValue::fromVariant("article"));
    article_obj.insert("id", QJsonValue::fromVariant(article.getId()));
    article_obj.insert("title", QJsonValue::fromVariant(article.getTitle()));
    article_obj.insert("year", QJsonValue::fromVariant(article.getYear()));
    article_obj.insert("author", QJsonValue::fromVariant(article.getAuthor()));
    article_obj.insert("journal", QJsonValue::fromVariant(article.getJournal()));
    article_obj.insert("description", QJsonValue::fromVariant(article.getDesc()));
    article_obj.insert("image", QJsonValue::fromVariant(article.getImg()));

    QJsonObject obj(document->object());
    QJsonArray arr(obj["medias"].toArray());
    arr.append(article_obj);
    obj["medias"]=arr;
    document->setObject(obj);
}

}
}
