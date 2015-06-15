#include <QApplication>
#include <QGraphicsWebView>
#include <QWebFrame>
#include <QString>

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    QString url;
    QGraphicsWebView view;
    // Read first application argument as url.
    if (1 < app.arguments().count()) {url = app.arguments().at(1);}
    else {url = "http://localhost";}
    // Hide the cursor (it still exists).
    QApplication::setOverrideCursor(Qt::BlankCursor);
    // Disable scrollbars.
    view.page()->mainFrame()->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
    view.page()->mainFrame()->setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);
    // Set full screen.
    view.showFullScreen();
    // Open a url.
    view.setUrl(QUrl(url));
    return app.exec();
}
