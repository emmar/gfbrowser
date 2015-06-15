#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsWebView>
#include <QString>

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

    QGraphicsWebView webview;
    webview.resize(width, height);
    webview.load(QUrl("http://codepen.io/paulirish/pen/LsxyF"));

    scene.addItem(&webview);
    view.resize(width, height);
    view.show();

    return app.exec();
}
