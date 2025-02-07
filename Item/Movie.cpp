#include "Movie.h"

namespace Item {
    Movie::Movie(
            const unsigned int i,
            const QString t,
            const QString y,
            const QString dir,
            const QString d,
            const QString im) : Media(i,t,y,d,im), director(dir) {}

    QString Movie::getDirector() const { return director;}

    Movie& Movie::setDirector(const QString dir) {
        this->director = dir;
        return *this;
    }
    
    void Movie::accept(IVisitor& visitor) {
        visitor.visit(*this);
    }

    void Movie::accept(IConstVisitor& visitor) const {
        visitor.visit(*this);
    }
}
