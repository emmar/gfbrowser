message ('Qt version: ' $$[QT_VERSION])

TEMPLATE = app

contains(QT_MAJOR_VERSION, 5) {QT += webkitwidgets}
contains(QT_MAJOR_VERSION, 4) {QT += webkit}
contains(QT_CONFIG, opengl){QT += opengl}
message ('Build paths: ' $${QT})

TARGET      = gfbrowser
SOURCES = gfbrowser.cpp
