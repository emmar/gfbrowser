#include <QApplication>
#include <QGLWidget>
#include <QGraphicsView>
#include <QGraphicsWebView>
#include <QDesktopWidget>
#include <QString>
#include <QWebFrame>

/*  Implementation that uses QGraphicsWebView to support hardware acceleration
 *  on mobile devices.
 */

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    // Hide the cursor (it still exists).
    QApplication::setOverrideCursor(Qt::BlankCursor);
    // Read first application argument as url.
    QString url;
    if (1 < app.arguments().count()) {url = app.arguments().at(1);}
    else {url = "http://localhost";}
    // Create the web content object. 
    QGraphicsScene scene;
    QGraphicsView view(&scene);
    QGraphicsWebView webView;
    scene.addItem(&webView);
    // Reccommended - http://blog.qt.io/blog/2010/05/17/qtwebkit-now-accelerates-css-animations-3d-transforms
    //view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    //view.setViewport(new QGLWidget);
    // Load url.
    webView.load(QUrl(url));
    view.showFullScreen();
    // Disable scrollbars of view.
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // Bugfix for QGraphicsWebView not same as QWebView.
    webView.resize(app.desktop()->screenGeometry().size());
    // Disable scrollbars of webView.
    QWebFrame* frame = webView.page()->mainFrame();
    frame->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
    frame->setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);
    return app.exec();
}
