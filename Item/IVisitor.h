#ifndef IVISITOR_H
#define IVISITOR_H

namespace Item {
class Book;
class Article;
class Movie;

class IVisitor {
public:
    virtual ~IVisitor() {};
    virtual void visit(Book& book) = 0;
    virtual void visit(Article& article) = 0;
    virtual void visit(Movie& movie) = 0;
};
}
#endif // IVISITOR_H
