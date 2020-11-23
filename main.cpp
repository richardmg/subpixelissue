#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "myrectangle.h"

int main(int argc, char *argv[])
{
    qputenv("QT_SCALE_FACTOR", "1.25");

    QGuiApplication app(argc, argv);

    qmlRegisterType<MyRectangle>("MyRectangle", 1, 0, "MyRectangle");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
