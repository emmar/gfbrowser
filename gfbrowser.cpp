#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsWebView>
#include <QDesktopWidget>
#include <QString>
#include <QWebFrame>
#ifdef DEV_INTERFACE_REQUIRES_MULTI_WINDOW
    #include <QWebInspector>
#endif
#ifdef QT_OPEN_GLWIDGETS
    #include <QOpenGLWidget>
#endif
#ifdef QT_BLOG_RECOMMENDS
    #include <QGLWidget>
#endif

/*  Implementation that uses QGraphicsWebView to support hardware acceleration
 *  on mobile devices.
 */

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    /*  Specifies whether images are automatically loaded in web pages. This is
     *  enabled by default.
     */
    QWebSettings::globalSettings()->setAttribute(QWebSettings::AutoLoadImages, true);
    /*  Enables or disables the running of JavaScript programs. This is enabled by
     *  default.
     */
    QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    /*  Private browsing prevents WebKit from recording visited pages in the
     *  history and storing web page icons. This is disabled by default.
     */
    QWebSettings::globalSettings()->setAttribute(QWebSettings::PrivateBrowsingEnabled, true);
    /*  This feature, when used in conjunction with QGraphicsWebView, accelerates
     *  animations of web content. CSS animations of the transform and opacity
     *  properties will be rendered by composing the cached content of the animated
     *  elements. This is enabled by default.
     */
    QWebSettings::globalSettings()->setAttribute(QWebSettings::AcceleratedCompositingEnabled, true);
    /*  This setting enables the tiled backing store feature for a
     *  QGraphicsWebView. With the tiled backing store enabled, the web page
     *  contents in and around the current visible area is speculatively cached
     *  to bitmap tiles. The tiles are automatically kept in sync with the web page
     *  as it changes. Enabling tiling can significantly speed up painting heavy
     *  operations like scrolling. Enabling the feature increases memory
     *  consumption. It does not work well with contents using CSS fixed
     *  positioning (see also resizesToContents property).
     *  tiledBackingStoreFrozen property allows application to temporarily freeze
     *  the contents of the backing store. This is disabled by default.
     */
    QWebSettings::globalSettings()->setAttribute(QWebSettings::TiledBackingStoreEnabled, true);
    
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
    // Set accelerated composting for gpu acceleration. (QtWebKitWebGL - default true)
    webView.page()->settings()->setAttribute(QWebSettings::AcceleratedCompositingEnabled, true);
    #ifdef DEV_INTERFACE_REQUIRES_MULTI_WINDOW
        // Show the developer interface.
        webView.page()->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
        QWebInspector inspector;
        inspector.setPage(webView.page());
        inspector.setVisible(true);
        // Restore the mouse cursor.
        QApplication::restoreOverrideCursor();
    #endif
    // Add the webView to scene.
    scene.addItem(&webView);
    // Configure view properties.
    #ifdef QT_OPEN_GLWIDGETS
        view.setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
        view.setViewport(new QOpenGLWidget());
    #endif
    view.setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    view.setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    view.setWindowFlags(Qt::FramelessWindowHint);
    view.showFullScreen();
    #ifdef QT_BLOG_RECOMMENDS
        // Reccommended - http://blog.qt.io/blog/2010/05/17/qtwebkit-now-accelerates-css-animations-3d-transforms
        view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
        view.setViewport(new QGLWidget);
    #endif
    // Load url.
    webView.load(QUrl(url));
    view.setStyleSheet( "QGraphicsView { border-style: none; }" );
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
