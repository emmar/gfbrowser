#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsWebView>
#include <QString>
#include <QGLWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString url;
    // Read first application argument as url.
    if (1 < app.arguments().count()) {url = app.arguments().at(1);}
    else {url = "http://localhost";}
    // Hide the cursor (it still exists).
    //QApplication::setOverrideCursor(Qt::BlankCursor);

    const int width = 1900;
    const int height = 1000;

    QGraphicsScene scene;

    QGraphicsView view(&scene);
    // Set full screen.
    view.showFullScreen();
    // Disable scrollbars.
    view.setFrameShape(QFrame::NoFrame);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setViewport(new QGLWidget);

    QGraphicsWebView graphicsView;

    //graphicsView.resize(width, height);
    graphicsView.load(QUrl(url));

    scene.addItem(&graphicsView);

    //view.resize(width, height);
    view.show();

    return app.exec();
}
