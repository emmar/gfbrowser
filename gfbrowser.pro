TEMPLATE = app
DEFINES += QT_QPA_EGLFS_HIDECURSOR QT_BUILD_WITH_OPENGL
contains(QT_MAJOR_VERSION, 5) {
    QT += webkit

    qtHaveModule(quick):qtHaveModule(qml) {
        QT += qml quick
    }
}
contains(QT_MAJOR_VERSION, 4) {
    QT += webkit
}
contains(QT_CONFIG, opengl){
    QT += opengl
}
TARGET      = gfbrowser
SOURCES = gfbrowser.cpp
