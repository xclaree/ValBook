#include "Book.h"

namespace Item {
    Book::Book(
            const unsigned int i,
            const QString t,
            const QString y,
            const QString a,
            const QString d,
            const QString im) : Media(i,t,y,d,im), author(a) {}

    QString Book::getAuthor() const { return author; }

    Book& Book::setAuthor(const QString author) {
        this->author = author;
        return *this;
    }

    void Book::accept(IVisitor& visitor){
        visitor.visit(*this);
    }

    void Book::accept(IConstVisitor& visitor) const {
        visitor.visit(*this);
    }
}
