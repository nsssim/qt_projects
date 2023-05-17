/*import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
}
*/

/*
 * Copyright 2020 Axel Waggershauser
 */
// SPDX-License-Identifier: Apache-2.0

import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import QtQuick.Shapes 1.12
import QtMultimedia 5.12

import ZXing 1.0

Window {
    id: qrApplication
    visible: true
    width: 640
    height: 480
    title: Qt.application.name

    property var nullPoints: [Qt.point(0,0), Qt.point(0,0), Qt.point(0,0), Qt.point(0,0)]
    property var points: nullPoints

    Camera {
        id: camera

        captureMode: Camera.CaptureStillImage
        deviceId: QtMultimedia.availableCameras[camerasComboBox.currentIndex] ? QtMultimedia.availableCameras[camerasComboBox.currentIndex].deviceId : ""

        /*onDeviceIdChanged: {
            focus.focusMode = CameraFocus.FocusContinuous
            focus.focusPointMode = CameraFocus.FocusPointAuto
        }*/

        onError: console.log("camera error:" + errorString)

        imageCapture {
            onImageCaptured: {
                //setMetadata(preview);
                //mScanQr.createThread("as");
                //photoPreview.source = preview

                //photoPreview.source = preview
                //console.log("------------")
                //console.log(requestId)
                //console.log(preview)
            }
            onImageSaved: {
                //console.log("------------")
                //console.log(requestId)
                mScanQr.createThread(path);
            }
        }
    }

    Timer {
        id : captureLoop
        interval: 150
        //interval: 1000
        running: true
        repeat: true
        onTriggered: {
            camera.imageCapture.captureToLocation(photoPreview);
            //camera.imageCapture.capture();
        }
    }


    ColumnLayout {
        anchors.fill: parent

        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: false
            visible: QtMultimedia.availableCameras.length > 1
            Label {
                text: qsTr("Camera: ")
                Layout.fillWidth: false
            }
            ComboBox {
                id: camerasComboBox
                Layout.fillWidth: true
                model: QtMultimedia.availableCameras
                textRole: "displayName"
                currentIndex: 0
            }
        }

        VideoOutput {
            id: videoOutput
            Layout.fillHeight: true
            Layout.fillWidth: true
            //filters: [barcodeReader]
            source: camera
            autoOrientation: true



            Shape {
                id: polygon
                anchors.fill: parent
                visible: points.length == 4

                Rectangle {
                    id: scanArea
                    //color: "white"
                    color: "black"
                    opacity: 0.2
                    //border.color: "red"
                    //border.width: 3

                    x: polygon.width/3
                    y: (polygon.height-polygon.width/3)/2
                    width: polygon.width/3
                    height: polygon.width/3
                }

                /*
                ShapePath {
                    strokeWidth: 3
                    strokeColor: "red"
                    strokeStyle: ShapePath.SolidLine
                    fillColor: "transparent"
                    //TODO: really? I don't know qml...
                    startX: videoOutput.mapPointToItem(points[3]).x
                    startY: videoOutput.mapPointToItem(points[3]).y
                    PathLine {
                        x: videoOutput.mapPointToItem(points[0]).x
                        y: videoOutput.mapPointToItem(points[0]).y
                    }
                    PathLine {
                        x: videoOutput.mapPointToItem(points[1]).x
                        y: videoOutput.mapPointToItem(points[1]).y
                    }
                    PathLine {
                        x: videoOutput.mapPointToItem(points[2]).x
                        y: videoOutput.mapPointToItem(points[2]).y
                    }
                    PathLine {
                        x: videoOutput.mapPointToItem(points[3]).x
                        y: videoOutput.mapPointToItem(points[3]).y
                    }
                }
                */
            }
        }

        Image {
            id : photoPreview
            visible : false
        }
    }

    /*Component.onCompleted: {
        cameras = QtMultimedia.availableCameras;
        cameraIndex = findCameraIndex( camera.deviceId );
        if ( cameraIndex === -1 ) return;
        cameraInfo = cameras[ cameraIndex ];
        cameraDisplayName = cameraInfo.displayName;
    }*/
}
