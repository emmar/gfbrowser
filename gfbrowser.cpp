#include <QApplication>
#include <QGLWidget>
#include <QGraphicsView>
#include <QGraphicsWebView>
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
 
    // Disable scrollbars.
    view.setFrameShape(QFrame::NoFrame);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // Set full screen.
    view.showFullScreen();
    // reccommended - http://blog.qt.io/blog/2010/05/17/qtwebkit-now-accelerates-css-animations-3d-transforms/
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setViewport(new QGLWidget);

    QGraphicsWebView graphicsView;
    //graphicsView.resize(width, height);
//graphicsView.setSceneRect(view.itemsBoundingRect());
    graphicsView.load(QUrl(url));

    //scene.addItem(&graphicsView);
    scene.addItem(new QGraphicsWebView::load(QUrl(url)));
    //view.resize(width, height);
    view.show();

    return app.exec();
}
