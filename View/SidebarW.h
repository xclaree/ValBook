#ifndef SIDEBARW_H
#define SIDEBARW_H
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>

namespace View {
class SidebarW : public QWidget {
    Q_OBJECT
private:
    QLabel *logo;
    QPushButton *home;
    QPushButton *addMedia;
public:
    explicit SidebarW(QWidget *parent = nullptr);
signals:
    void HomeClicked();
    void AddMediaClicked();
};
}

#endif // SIDEBARW_H
