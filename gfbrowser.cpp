#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsWebView>
#include <QString>

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    QString url;
    QGraphicsScene scene;
    QGraphicsView view(&scene);
    QGraphicsWebView* webView  = new QGraphicsWebView();
    // Read first application argument as url.
    if (1 < app.arguments().count()) {url = app.arguments().at(1);}
    else {url = "http://localhost";}
    // Hide the cursor (it still exists).
    QApplication::setOverrideCursor(Qt::BlankCursor);
    // Disable scrollbars.
    webView.page()->mainFrame()->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
    webView.page()->mainFrame()->setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);
    // Set full screen.
    view.showFullScreen();
    // Open a url.
    webView.setUrl(QUrl(url));
    return app.exec();
}
