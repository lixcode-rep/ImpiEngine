#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QmlApplication.h>
#include <OpenGLWidget.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<OpenGLWidget>("OpenGLUnderQML", 1, 0, "OpenGLWidget");

    QmlApplication qmlApp;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("qmlApp", &qmlApp);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
