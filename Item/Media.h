#ifndef MEDIA_H
#define MEDIA_H

#include <QString>
#include <vector>
#include "IVisitor.h"
#include "IConstVisitor.h"

namespace Item
{

    class Media
    {
    protected:
        const unsigned int id;        // Codice univoco
        QString title;               // Titolo
        QString year;                // Anno di pubblicazione
        QString desc;            // Descrizione del media
        QString img;                // Percorso file immagine

    public:
        Media(
            const unsigned int i,
            const QString t,
            const QString y,
            const QString d = "",
            const QString im = "");
        virtual ~Media() = default;
        unsigned int getId() const;
        QString getTitle() const;
        QString getYear() const;
        QString getDesc() const;
        QString getImg() const;
        Media& setTitle(const QString t);
        Media& setYear(const QString y);
        Media& setDesc(const QString d);
        Media& setImg(const QString im);
        Media& setInfo(const Media& media);
        virtual void accept(IConstVisitor& visitor) const = 0;
        virtual void accept(IVisitor& visitor) = 0;
    };
}

#endif
