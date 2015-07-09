TEMPLATE = app
message ('Qt version: ' $$[QT_VERSION])
  contains(QT_MAJOR_VERSION, 5) {QT += webkitwidgets}
  contains(QT_MAJOR_VERSION, 4) {QT += webkit}
message ('Build paths: ' $${QT})
# If using a window manager, a developer interface is available.
#DEFINES += DEV_INTERFACE_REQUIRES_MULTI_WINDOW
# QGLWidget requires opengl
QT += opengl
TARGET      = gfbrowser
SOURCES = gfbrowser.cpp
