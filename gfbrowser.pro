message ('Qt version: ' $$[QT_VERSION])
    QT += webkit
    QT += opengl
    QT += widgets webkitwidgets
message ('Build paths: ' $${QT})
TARGET      = gfbrowser
SOURCES = gfbrowser.cpp
