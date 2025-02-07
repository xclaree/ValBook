#ifndef FULL_H
#define FULL_H
#include <QWidget>
#include <QLabel>
#include "../../Item/IConstVisitor.h"

namespace View::MediaRenderer {

class Full : public Item::IConstVisitor {
private:
    QWidget* widget;
    QLabel* type;
    QLabel* id;
    QLabel* title;
    QLabel* year;
    QLabel* description;
    QLabel* image;
    static QString default_image; //"Assets/no_image.png"
public:
    Full() = default;
    virtual void visit(const Item::Book& book) override;
    virtual void visit(const Item::Movie& movie) override;
    virtual void visit(const Item::Article& article) override;
    virtual QWidget* getWidget() const;
    virtual QLabel* getType() const;
    virtual QLabel* getId() const;
    virtual QLabel* getTitle() const;
    virtual QLabel* getDesc() const;
};
}
#endif // FULL_H
