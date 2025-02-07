#ifndef IRESULTRENDERERSTATEGY_H
#define IRESULTRENDERERSTATEGY_H
#include "../../Item/Library.h"
#include "../WidgetLookup.h"
#include <QGridLayout>

namespace View::ResultRenderer {

class IResultRendererStategy {
public:
    virtual ~IResultRendererStategy() = default;
    virtual void render(QGridLayout* grid, Item::Library* library, QVector<View::WidgetLookup>* lookup) = 0;
};

}

#endif // IRESULTRENDERERSTATEGY_H
