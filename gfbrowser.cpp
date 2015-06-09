#include <QApplication>
#include <QtGui>
#include <QtWebKit>

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    QApplication::setOverrideCursor(Qt::BlankCursor);
    QWebView view;
    view.page().setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
    view.page().setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);
    //view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.showFullScreen();
    view.setUrl(QUrl("http://google.com"));
    return app.exec();
}
