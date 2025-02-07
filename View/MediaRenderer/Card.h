#ifndef CARD_H
#define CARD_H
#include <QWidget>
#include <QLabel>
#include <QFrame>
#include "../../Item/IConstVisitor.h"
#include "../../Item/Media.h"
#include "../MainWindow.h"


namespace View::MediaRenderer {

class Card : public QFrame, public Item::IConstVisitor {
    Q_OBJECT
private:
    Item::Media* media;
    View::MainWindow* mainWindow;
    QWidget* widget;
    QLabel* type;
    QLabel* id;
    QLabel* title;
    QVBoxLayout* vbox;
public:
    Card(Item::Media* media, MainWindow* mainwindow);
    virtual void visit(const Item::Book& book) override;
    virtual void visit(const Item::Movie& movie) override;
    virtual void visit(const Item::Article& article) override;
    QWidget* getWidget() const;
    QLabel* getType() const;
    QLabel* getId() const;
    QLabel* getTitle() const;
    void mousePressEvent(QMouseEvent*) override;

signals:
    void cardClicked(Card* card);

public slots:
    void showItem();
};
}

#endif // CARD_H
