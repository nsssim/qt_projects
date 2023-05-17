import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.3

Window {
    id: newAppWindow
    //visible: true
    modality: Qt.ApplicationModal
    visibility: Window.FullScreen
    //x: 0
    //y: 0

    width: dashboard.width
    height: dashboard.height
    /*Text {
        id: text
        text: qsTr("Mr. Nassim")
    }*/
    /*width: 300
    height: 300*/
    //height: maximumHeight
    //width: maximumWidth

    /*
    width: 1200
    height: 800
    */

    Component.onCompleted: {
        newAppWindow.showFullScreen();
    }


    //Grid {
      //  id: firstRow
        //width: 300


        /*
        width: 1200
        height: 800
        */

        Button {
            id: exit
            width: 80
            height: 80
            //width: 40
            //height: 40
            anchors.right: parent.right
            anchors.margins: 10
            Image {
                id: exitIcon
                source: "/close.png";
                anchors.horizontalCenter: parent.horizontalCenter;
                anchors.verticalCenter: parent.verticalCenter;
                //width: 32
                //height: 32
                width: 80
                height: 80
            }

            background: Rectangle {
                //implicitWidth: 80
                //implicitHeight: 80
                opacity: enabled ? 1 : 0.3
                //border.color: control.down ? "#17a81a" : "#21be2b"
                border.width: 1
                radius: 2
            }
            onPressed: {
                newAppWindow.close()
            }
            /*onPressed: {
                newAppWindowLoader.active = false
            }*/
        }
    //}
}
