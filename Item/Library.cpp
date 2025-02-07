#include "Library.h"
#include <QString>

namespace Item {

Library::Library() : lib() {}

Library& Library::addMedia(const Media* media) {
    lib.push_back(media);
    return *this;
}

Library& Library::removeMedia(const Media* media) {
    for(auto it = lib.begin(); it!=lib.end(); ++it) {
        if((*it)->getId() == media->getId()) {
            auto q = *it;
            lib.erase(it);
            delete q;
            return *this;
        }
    }
    return *this;
}

Library& Library::modifyMedia(const Media* media1, const Media* media2) {
    Library::removeMedia(media1);
    Library::addMedia(media2);
    return *this;
}


void Library::searchMedia(Library* result, const QString& s) {
    for(auto it = lib.begin(); it!=lib.end(); ++it) {
        if( (QString::number((*it)->getId())).contains(s, Qt::CaseInsensitive) ||
            ((*it)->getTitle()).contains(s, Qt::CaseInsensitive)) {
            result->addMedia(*it);
        }
    }
}

bool Library::isEmpty() const {
    return lib.empty();
}

std::vector<const Media*> Library::getLibrary() const {
    return lib;
}

unsigned int Library::getSize() const {
    return lib.size();
}

}
