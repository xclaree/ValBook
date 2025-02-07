#include "ResultsWidget.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>

namespace View {

ResultWidget::ResultWidget(QWidget *parent) : QWidget(parent), has_searched(false) {

    results_total = new QLabel("");
    results_total->setStyleSheet("color: black;");
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->addWidget(results_total);
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    grid = new QGridLayout();
    grid->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    QWidget* container = new QWidget();
    container->setLayout(grid);
    scroll_area = new QScrollArea();
    scroll_area->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    scroll_area->setStyleSheet("background-color: white; color: black; font-size: 14px; border: 1px solid black;");
    scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    scroll_area->setWidgetResizable(true);
    scroll_area->setWidget(container);
    vbox->addWidget(scroll_area,1);
    setLayout(vbox);
}

void ResultWidget::showResults(Item::Library* results, const QString& s){

    while(!lookup.isEmpty()) {
        WidgetLookup info = lookup.takeLast();
        delete info.getWidget();
    }


    has_searched = true;
    if(results->isEmpty()) {
        results_total->setText("No result for \"" + s + "\".");
    } else {
        results_total->setText(QString::number(results->getSize()) + " results for \"" + s + "\".");
    }
    renderer->render(grid, results, &lookup);

    //connetto i media
    for(auto it = lookup.begin(); it != lookup.end(); ++it) {
        //connect((*it).getWidget(), &View::WidgetLookup::clicked, std::bind(&ResultWidget::showMedia, this, it->getMedia()));
    }
}

}
