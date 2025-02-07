#include "ListRenderer.h"
#include <QWidget>

void ListRenderer::render(QGridLayout* grid, Item::Library* library, QVector<View::WidgetLookup>* lookup) {
    std::vector<const Item::Media*> v = library->getLibrary();
    for(auto it = v.begin(); it != v.end(); ++it) {
        QWidget* widget;
        (*it)->accept(card);
        widget = card.getWidget();
        grid->addWidget(widget);
        lookup->push_back(View::WidgetLookup(*it, widget));
    }
}
