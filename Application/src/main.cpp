#include <QApplication>
#include <QDebug>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.addImportPath(app.applicationDirPath() + "/Plugins");
    engine.addImportPath(app.applicationDirPath() + "/Plugins/vsdt");
    engine.addImportPath(app.applicationDirPath() + "/Plugins/vsdt/lab");
    engine.addImportPath(app.applicationDirPath() + "/Plugins/vsdt/lab/work");
    QObject::connect(&engine,
                     &QQmlApplicationEngine::objectCreated,
                     &app,
                     [url](QObject *obj, const QUrl &objUrl) {
                         if (!obj && url == objUrl)
                             QCoreApplication::exit(-1);
                     },
                     Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
