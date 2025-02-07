#ifndef ARTICLE_H
#define ARTICLE_H
#include "Media.h"
#include <QString>

namespace Item {
    
    class Article : public Media {
    private:
        QString author; //Redattore/autore dell'articolo
        QString journal; //Giornale di provenienza dell'articolo
    public: 
        Article(
            const unsigned int i,
            const QString t,
            const QString y,
            const QString a,
            const QString j,
            const QString d = "",
            const QString im = "");

        QString getJournal() const;
        QString getAuthor() const;
        Article& setJournal(const QString journal);
        Article& setAuthor(const QString author);
            
        virtual void accept(IVisitor& visitor);
        virtual void accept(IConstVisitor& visitor) const;
    };
}

#endif
