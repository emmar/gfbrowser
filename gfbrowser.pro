message ('Qt version: ' $$[QT_VERSION])
    QT += webkit
    QT += opengl
message ('Build paths: ' $${QT})
TARGET      = gfbrowser
SOURCES = gfbrowser.cpp
