#include "Media.h"

namespace Item
{
    Media::Media(
            const unsigned int i,
            const QString t,
            const QString y,
            const QString d,
            const QString im) : id(i), title(t), year(y), desc(d), img(im) {}

    unsigned int Media::getId() const{
        return id;
    }

    QString Media::getTitle() const{
        return title;
    }

    QString Media::getYear() const{
        return year;
    }

    QString Media::getDesc() const {
        return desc;
    }

    Media& Media::setTitle(const QString t) {
        this->title = t;
        return *this;
    }

    Media& Media::setYear(const QString y) {
        this->year = y;
        return *this;
    }

    Media& Media::setDesc(const QString d) {
        this->desc = d;
        return *this;
    }

    QString Media::getImg() const { return img; }

    Media& Media::setImg(const QString im) {
        this->img = im;
        return *this;
    }

    Media& Media::setInfo(const Media& media) {
        this->setTitle(media.getTitle());
        this->setYear(media.getYear());
        this->setDesc(media.getDesc());
        this->setImg(media.getImg());
        return *this;
    }
}
