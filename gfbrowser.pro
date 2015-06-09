TEMPLATE = app
DEFINES += QT_QPA_EGLFS_HIDECURSOR QT_BUILD_WITH_OPENGL
contains(QT_MAJOR_VERSION, 5) {
    QT += webkitwidgets
}
contains(QT_MAJOR_VERSION, 4) {
    QT += webkit
}
QT += opengl
TARGET      = gfbrowser
SOURCES = gfbrowser.cpp
