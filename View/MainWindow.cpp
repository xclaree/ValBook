#include "MainWindow.h"
#include <QSplitter>
#include <QFileDialog>
#include <QStackedWidget>
#include <QScrollArea>
#include "../Item/Media.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
    sidebar = new View::SidebarW(this);
    searchWidget = new View::SearchWidget(this);
    resultWidget = new View::ResultWidget(this);

    library = new Item::Library();
    //InitLibrary(json);

    QSplitter* splitter = new QSplitter(this);
    setCentralWidget(splitter);
    splitter->addWidget(sidebar);

    QWidget* searchContainer = new QWidget(this);
    QVBoxLayout* searchLayout = new QVBoxLayout(searchContainer);
    searchLayout->addWidget(searchWidget,0);
    searchLayout->addWidget(resultWidget,1);
    //searchLayout->setContentsMargins(0, 0, 0, 0);

    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(searchContainer);
    splitter->addWidget(stackedWidget);
    //sidebar->setFixedWidth(200);
    splitter->setSizes(QList<int>() << 200 << 824);
    splitter->setCollapsible(0, false);
    splitter->setCollapsible(1, false);

    //SIGNALS CONNECTION
    //connect(sidebar, &View::SidebarW::HomeClicked, this, &MainWindow::MainWindow);
    //connect(sidebar, &View::SidebarW::AddMediaClicked, this, &MainWindow::showAddMediaWindow);
    //connect(searchWidget, &View::SearchWidget::search_event, this, &MainWindow::search);
}

/*void MainWindow::search(const QString s) {
    library->searchMedia(query, s);
    //if(query->isEmpty())
}*/
