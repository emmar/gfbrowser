TEMPLATE = app
message ('Qt version: ' $$[QT_VERSION])
  contains(QT_MAJOR_VERSION, 5) {
    QT += webkitwidgets
    # Testing the QTOpenGLWidget: trying to fix EGLFS: OpenGL windows cannot...
        DEFINES += QT_OPEN_GLWIDGETS
        QT += widgets opengl
  }
  contains(QT_MAJOR_VERSION, 4) {QT += webkit}
message ('Build paths: ' $${QT})
# If using a window manager, a developer interface is available.
#DEFINES += DEV_REMOTE_INSPECTOR
TARGET      = gfbrowser
SOURCES = gfbrowser.cpp
