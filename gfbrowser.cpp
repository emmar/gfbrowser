#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsWebView>
#include <QString>
#include <QGLWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    const int width = 1900;
    const int height = 1000;

    QGraphicsScene scene;

    QGraphicsView view(&scene);
    view.setFrameShape(QFrame::NoFrame);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QGraphicsWebView graphicsView;
graphicsView->setViewportUpdateMode(view::BoundingRectViewportUpdate);
graphicsView->setViewport(new QGLWidget);
    graphicsView.resize(width, height);
    graphicsView.load(QUrl("http://codepen.io/paulirish/pen/LsxyF"));

    scene.addItem(&graphicsView);
    view.resize(width, height);
    view.show();

    return app.exec();
}
