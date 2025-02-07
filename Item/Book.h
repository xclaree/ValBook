#ifndef BOOK_H
#define BOOK_H
#include "Media.h"
#include <QString>

namespace Item {
    class Book : public Media {
    private:
        QString author; //Autore/i del libro
    public:
        Book(
            const unsigned int i,
            const QString t,
            const QString y,
            const QString a,
            const QString d = "",
            const QString im = "");
        QString getAuthor() const;
        Book& setAuthor(const QString author);
        virtual void accept(IVisitor& visitor);
        virtual void accept(IConstVisitor& visitor) const;
    };
}

#endif
