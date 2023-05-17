#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include <QQmlEngine>

//aslttaki sonra eklendi. dosya da manuel oluşturuldu
#include "ZXingQtReader.h"
#include "scanqr.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    //alttaki sonra
    ZXingQt::registerQmlAndMetaTypes();

    QGuiApplication app(argc, argv);

    QScopedPointer<scanQr> mScanQr(new scanQr);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    engine.rootContext()->setContextProperty("mScanQr", mScanQr.data());


    /*scanQr* mScanQr = new scanQr;
    QQmlContext * rootContext = engine.rootContext();
    rootContext->setContextProperty("mScanQr", mScanQr);*/
    //scanThread *mScanThread;
    //mScanQr.createThread();


    return app.exec();
}
