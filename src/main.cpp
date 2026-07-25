#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() {
            qCritical() << "QML object creation failed!";
            QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection
    );

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::warnings,
        [](const QList<QQmlError> &warnings) {
            for (const auto &warning : warnings) {
                qWarning().noquote() << warning.toString();
            }
        }
    );

    engine.load(
        QUrl(QStringLiteral(
            "qrc:/qt/qml/io/fleshka/tunes/qml/Main.qml"
        ))
    );

    if (engine.rootObjects().isEmpty()) {
        qCritical() << "No root QML objects were created!";
        return -1;
    }

    return app.exec();
}
