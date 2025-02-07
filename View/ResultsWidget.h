#ifndef RESULTSWIDGET_H
#define RESULTSWIDGET_H
#include "MediaRenderer/Card.h"
#include "../Item/Media.h"
#include "../Item/Library.h"
#include <QWidget>
#include <QVector>
#include <QScrollArea>

#include "WidgetLookup.h"
#include "ResultRenderer/IResultRendererStategy.h"

namespace View {
//L'elemento fondamentale di ResultWidget è cards, un vettore di carte dove ogni carta rappresenta un elemento.
//Cards rappresenta il risultato della ricerca eseguita
class ResultWidget : public QWidget{
private:
    QLabel* results_total; //Rappresenta il numero totale di matches trovati
    QVector<const MediaRenderer::Card*> cards; //Vettore con i matches. Se has_searched = false contiene tutti i media memorizzati
    bool has_searched; // se non ha ancora cercato, mostra tutti i media memorizzati
    QScrollArea* scroll_area;
    QVector<WidgetLookup> lookup;
    QGridLayout* grid;
    View::ResultRenderer::IResultRendererStategy* renderer;
public:
    explicit ResultWidget(QWidget *parent = nullptr);
signals:
    void showMedia(const Item::Media* media);
public slots:
    void showResults(Item::Library* results, const QString& s);
};

}

#endif // RESULTSWIDGET_H
