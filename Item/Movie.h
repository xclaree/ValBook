#ifndef MOVIE_H
#define MOVIE_H

#include "Media.h"
#include <QString>

namespace Item {
    class Movie : public Media {
    private:
        QString director; //Regista
    public:
        Movie(
            const unsigned int i,
            const QString t,
            const QString y,
            const QString dir,
            const QString d = "",
            const QString im = "");
        QString getDirector() const;
        Movie& setDirector(const QString dir);
        virtual void accept(IVisitor& visitor);
        virtual void accept(IConstVisitor& visitor) const;
    };
}

#endif
