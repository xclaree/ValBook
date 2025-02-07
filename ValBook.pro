QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += Item/Article.h \
           Item/Book.h \
           Item/IConstVisitor.h \
           Item/IVisitor.h \
           Item/Json/JsonVisitor.h \
           Item/Library.h \
           Item/Media.h \
           Item/Movie.h \
           View/MainWindow.h \
           View/MediaRenderer/Card.h \
           View/MediaRenderer/Full.h \
           View/ResultRenderer/IResultRendererStategy.h \
           View/ResultRenderer/ListRenderer.h \
           View/ResultsWidget.h \
           View/SearchWidget.h \
           View/SidebarW.h
SOURCES += main.cpp \
           Item/Article.cpp \
           Item/Book.cpp \
           Item/Json/JsonVisitor.cpp \
           Item/Library.cpp \
           Item/Media.cpp \
           Item/Movie.cpp \
           View/MainWindow.cpp \
           View/MediaRenderer/Card.cpp \
           View/MediaRenderer/Full.cpp \
           View/ResultRenderer/ListRenderer.cpp \
           View/ResultsWidget.cpp \
           View/SearchWidget.cpp \
           View/SidebarW.cpp
     
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
