#include <QApplication>
#include <QtGui>
#include <QtWebKit>

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    QWebView view;
    view.show();
    view.setUrl(QUrl("http://google.com"));
    return app.exec();
}
