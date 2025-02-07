#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedWidget>
#include "SidebarW.h"
#include "SearchWidget.h"
#include "ResultsWidget.h"
#include "../Item/Library.h"

namespace View {
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    QWidget *sideWidget;
    View::SidebarW* sidebar;
    View::SearchWidget* searchWidget;
    QStackedWidget* stackedWidget;
    View::ResultWidget* resultWidget;
    Item::Library* library; //La biblioteca, dunque contiene tutti i media
    Item::Library* query; //Il risultato della ricerca

    void InitLibrary(); //aggiunge alla libreria tutti i media

public slots:
    void search(const QString s) const;
    void onCardClicked(View::MediaRenderer::Card* card);
};
}
#endif // MAINWINDOW_H
