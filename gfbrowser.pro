TEMPLATE = app
message ('Qt version: ' $$[QT_VERSION])
  contains(QT_MAJOR_VERSION, 5) {QT += webkitwidgets}
  contains(QT_MAJOR_VERSION, 4) {QT += webkit}
message ('Build paths: ' $${QT})
TARGET      = gfbrowser
SOURCES = gfbrowser.cpp
