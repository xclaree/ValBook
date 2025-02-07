#ifndef JSONVISITOR_H
#define JSONVISITOR_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QString>
#include <vector>
#include "../IConstVisitor.h"
#include "../Media.h"
#include "../Book.h"
#include "../Movie.h"
#include "../Article.h"

namespace Item::Json {

class JsonVisitor : public IConstVisitor {
private:
    QJsonDocument* document;
    QString path;
public:
    JsonVisitor(QString path);
    virtual ~JsonVisitor() = default;
    std::vector<Item::Media*> getMedias() const;
    void updateJson(std::vector<Item::Media*>& medias);

    void visit(const Book& book) override;
    void visit(const Movie& movie) override;
    void visit(const Article& article) override;

};
}

#endif // JSONVISITOR_H
