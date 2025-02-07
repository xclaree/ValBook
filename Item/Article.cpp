#include "Article.h"

namespace Item {
    Article::Article(
            const unsigned int i,
            const QString t,
            const QString y,
            const QString a,
            const QString j,
            const QString d,
            const QString im) : Media(i,t,y,d,im), author(a), journal(j) {}

    QString Article::getJournal() const {
        return journal;
    }

    QString Article::getAuthor() const {
        return author;
    }

    Article& Article::setJournal(const QString journal) {
        this->journal = journal;
        return *this;
    }

    Article& Article::setAuthor(const QString author) {
        this->author = author;
        return *this;
    }
            
    void Article::accept(IVisitor& visitor) {
        visitor.visit(*this);
    }

    void Article::accept(IConstVisitor& visitor) const {
        visitor.visit(*this);
    }
}
