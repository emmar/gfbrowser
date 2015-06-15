#include <QApplication>
#include <QWebView>
#include <QString>

/*  An earlier implementation that uses QWebView.  Works good but
 *  on the rpi it currently does not support hardware acceleration.
 *
 *  See https://trac.webkit.org/wiki/QtWebKitTiling:
 *      "QWebView is based on the QWidget system, thus it cannot
 *       easily support rotation, overlays, hardware accelerated
 *       compositing and tiling."
 *
 *  This browser might be reincarnated if hardware acceleration is not needed
 *  or gets implemented later.
 */

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    QString url;
    QWebView view;
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
