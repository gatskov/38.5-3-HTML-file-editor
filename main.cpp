#include <QApplication>
#include <QMainWindow>
#include <QWebEngineView>
#include <QHBoxLayout>
#include <QPlainTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    const int MIN_WIDTH = 800;
    const int MIN_HEIHGT = 600;

    auto* mainWindow = new QWidget;
    mainWindow->setMinimumSize(QSize(MIN_WIDTH,MIN_HEIHGT));
    auto* htmlWindow = new QPlainTextEdit;
    auto* webView = new QWebEngineView;
    auto* hbox = new QHBoxLayout(mainWindow);

    hbox->addWidget(htmlWindow);
    hbox->addWidget(webView);

    QSizePolicy stretchPolicy;
    stretchPolicy.setHorizontalPolicy(QSizePolicy::Expanding);
    stretchPolicy.setVerticalPolicy(QSizePolicy::Expanding);
    htmlWindow->setSizePolicy(stretchPolicy);
    webView->setSizePolicy(stretchPolicy);

    QObject::connect(htmlWindow, &QPlainTextEdit::textChanged, [webView, htmlWindow]()
    {
        auto htmlSource = htmlWindow->toPlainText();
        webView->setHtml(htmlSource);
    });

    mainWindow->show();
    return a.exec();
}

// Text for test:
//<h1>HTML file editing application</h1>
//<p>Really it's time to fall asleep</p>
//<a href="#">link</a>
