#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>

namespace View {
class SearchWidget : public QWidget
{
    Q_OBJECT
private:
    QLabel *welcome_message;
    QLineEdit *searchBar; //Rappresenta la stringa cercata
    QPushButton *searchButton; //Bottone per la ricerca

public:
    SearchWidget(QWidget *parent = nullptr);

signals:
    void search_event(const QString& s);

private slots:
    void emitSearchSignal();
};
}
#endif // SEARCHWIDGET_H
