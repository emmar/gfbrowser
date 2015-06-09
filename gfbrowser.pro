TEMPLATE = app
contains(QT_MAJOR_VERSION, 5) {
    QT += webkit
    QT += webkitwidgets
}
contains(QT_MAJOR_VERSION, 4) {
    QT += webkit
}
QT += opengl
TARGET      = gfbrowser
SOURCES = gfbrowser.cpp
