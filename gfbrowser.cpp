#include <QApplication>
#include <QWebView>
#include <QWebFrame>

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    // Hide the cursor (it still exists).
    QApplication::setOverrideCursor(Qt::BlankCursor);
    QWebView view;
    // Disable scrollbars.
    view.page()->mainFrame()->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
    view.page()->mainFrame()->setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);
    view.showFullScreen();
    // Open a url.
    view.setUrl(QUrl("http://helloracer.com/webgl"));
    return app.exec();
}
