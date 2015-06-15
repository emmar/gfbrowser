#include <QApplication>
#include <QGLWidget>
#include <QGraphicsView>
#include <QGraphicsWebView>
#include <QDesktopWidget>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString url;
    // Read first application argument as url.
    if (1 < app.arguments().count()) {url = app.arguments().at(1);}
    else {url = "http://localhost";}
    // Hide the cursor (it still exists).
    //QApplication::setOverrideCursor(Qt::BlankCursor);
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
    // Disable scrollbars.
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // bugfix for QGraphicsWebView
    webView.resize(app.desktop()->screenGeometry().size());

    //QGraphicsScene scene;
    //QGraphicsView view(&scene);
/* QGraphicsView view;

    // Disable scrollbars.
    view.setFrameShape(QFrame::NoFrame);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // Set full screen.
    view.showFullScreen();
    // reccommended - http://blog.qt.io/blog/2010/05/17/qtwebkit-now-accelerates-css-animations-3d-transforms/
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setViewport(new QGLWidget);
*/
    //QGraphicsWebView webContent;

    //webContent.load(QUrl(url));
 //QGraphicsView::fitInView(view.itemsBoundingRect(), Qt::KeepAspectRatio;
 //graphicsView.setResizesToContents(true);
// graphicsView.fitInView();
//scene.setSceneRect();

  //  scene.addItem(&graphicsView);
    //view.resize(width, height);

    //view.show();
    //webContent.showFullScreen();

    return app.exec();
}
