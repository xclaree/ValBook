#ifndef ICONSTVISITOR_H
#define ICONSTVISITOR_H

namespace Item {
class Book;
class Article;
class Movie;

class IConstVisitor {
public:
    virtual ~IConstVisitor() {};
    virtual void visit(const Book& book) = 0;
    virtual void visit(const Article& article) = 0;
    virtual void visit(const Movie& movie) = 0;
};
}


#endif // ICONSTVISITOR_H
