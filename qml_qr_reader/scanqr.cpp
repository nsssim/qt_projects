#include "scanqr.h"
#include "ZXingQtReader.h"
#include <QCameraImageCapture>
#include <QCamera>
#include <QBuffer>

scanQr::scanQr(QObject *parent)
    : QObject{parent}
{

}

void scanQr::createThread(QString filePath)
{
    qDebug() << filePath;
    QString imagePath = filePath;

    QImage fileImage = QImage(imagePath);
    scanThread scan;
    scan.run(fileImage);
}

/*
void scanQr::captureToBuffer(QString filePath)
{
    QCameraImageCapture::CaptureToBuffer;
}
*/


scanThread::scanThread()
{

}

void scanThread::run(QImage fileImage)
{
    //scanThread scan;

    auto hints = ZXingQt::DecodeHints()
                     //.setFormats(BarcodeFormat::Any)
                     .setTryRotate(false)
            .setMaxNumberOfSymbols(10);

    auto results = ZXingQt::ReadBarcodes(fileImage, hints);

    for (auto& result : results) {
        qDebug() << "Text:   " << result.text();
        qDebug() << "Format: " << result.format();
        qDebug() << "Content:" << result.contentType();
        qDebug() << "";
    }
}
