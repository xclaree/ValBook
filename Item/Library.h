#ifndef LIBRARY_H
#define LIBRARY_H
#include "Media.h"
#include <QString>
#include <vector>

namespace Item {
    class Library {
    private:
        std::vector<const Media*> lib;
    public:
        Library();
        ~Library() = default;
        Library& addMedia(const Media* media);
        Library& removeMedia(const Media* media);

        //La modifica sorrisponde ad una rimozione di media1 e l'aggiunta di media2
        Library& modifyMedia(const Media* media1, const Media* media2);

        // Dato s stringa che puo rappresentare un titolo o un id, aggiorna result in modo tale da contenere i match per s
        void searchMedia(Library* result, const QString& s);

        bool isEmpty() const; //Mi dice se lib è vuoto o meno

        std::vector<const Media*> getLibrary() const;

        unsigned int getSize() const;

    };
}

#endif 
