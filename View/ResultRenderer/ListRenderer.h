#ifndef LISTRENDERER_H
#define LISTRENDERER_H
#include "IResultRendererStategy.h"
#include "../MediaRenderer/Card.h"
#include "../../Item/Library.h"
#include "../WidgetLookup.h"

class ListRenderer : public View::ResultRenderer::IResultRendererStategy {
private:
    Item::Library library;
    View::MediaRenderer::Card card;
public:
    ListRenderer() = default;
    virtual void render(QGridLayout* grid, Item::Library* library, QVector<View::WidgetLookup>* lookup);
};

#endif // LISTRENDERER_H
