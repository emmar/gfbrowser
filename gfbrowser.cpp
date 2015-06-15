#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsWebView>
#include <QString>

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    QString url;
    QGraphicsScene scene;
    //QGraphicsView view(&scene);
    QGraphicsWebView* webView  = new QGraphicsWebView();
    // Read first application argument as url.
    if (1 < app.arguments().count()) {url = app.arguments().at(1);}
    else {url = "http://localhost";}
    // Open a url.
    webView->load(QUrl(url));
    // Hide the cursor (it still exists).
    QApplication::setOverrideCursor(Qt::BlankCursor);
    // Disable scrollbars.
    //webView.page()->mainFrame()->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
    //webView.page()->mainFrame()->setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);
    // Set full screen.
      QTransform transform;
      transform.rotate(60,Qt::YAxis);
      
      webView->setTransform(transform);
      webView->setPreferredSize(500,500);
      //view.showFullScreen();  
    return app.exec();
}
