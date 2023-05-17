import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.3
import QtMultimedia 5.0

Item {
    ListModel {
        id: contactDelegate

        ListElement {
            name: "INSTAGRAM"
            portrait: "/instagram.png"
        }
        ListElement {
            name: "LINKEDLN"
            portrait: "/linkedln.png"
        }
        ListElement {
            name: "LOCK"
            portrait: "/lock.png"
        }
        ListElement {
            name: "MENU"
            portrait: "/menu.png"
        }
        ListElement {
            name: "MESSAGES"
            portrait: "/messages.png"
        }
        ListElement {
            name: "MICROPHONE"
            portrait: "/microphone.png"
        }
        ListElement {
            name: "NEW DOC"
            portrait: "/new-document.png"
        }
        ListElement {
            name: "NOTEPAD"
            portrait: "/notepad.png"
        }
        ListElement {
            name: "PICTURES"
            portrait: "/pictures.png"
        }
        ListElement {
            name: "PINTEREST"
            portrait: "/pinterest.png"
        }
        ListElement {
            name: "PLAY"
            portrait: "/play.png"
        }
        ListElement {
            name: "RADIO"
            portrait: "/radio.png"
        }
        ListElement {
            name: "EDUCATION"
            portrait: "/school.png"
        }
        ListElement {
            name: "SETTINGS"
            portrait: "/settings.png"
        }
        ListElement {
            name: "SHARE"
            portrait: "/share.png"
        }
    }
    /*MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        //onClicked: {
        //    Qt.quit()
        //}

        //onPositionChanged: {
        //    myMouseX = mouseX
        //    myMouseY = mouseY
        //}
    }*/


    Audio {
        id: clickAppIcon
        source: "/sounds/classic_click.wav"
    }

    Grid {
        width: page1.width
        anchors.fill: page1
        anchors.topMargin: 30
        columns: 4
        //rowSpacing: 20
        rowSpacing: 40

        Repeater { model: contactDelegate
            Column {
            id: cell
            //width: page1.width / 5
            width: page1.width / 4
                Button {
                    id: cellButton
                    //if you can click, you must be declarated size 2D
                    //width: 80;
                    //height: 80;
                    width: 160;
                    height: 160;
                    background: Rectangle {
                        opacity: 0
                    }
                    anchors.horizontalCenter: cell.horizontalCenter
                    Column {
                        id: cellContent
                        anchors.horizontalCenter: cellButton.horizontalCenter
                        //anchors.verticalCenter: cellButton.verticalCenter
                        Image {
                            id: iconImage
                            source: portrait;
                            anchors.horizontalCenter: parent.horizontalCenter;
                            //anchors.verticalCenter: parent.verticalCenter;
                            //width: 64
                            //height: 64
                            width: 120
                            height: 120
                        }
                        Text {
                            id: iconName
                            text: name;
                            anchors.horizontalCenter: parent.horizontalCenter;
                            //anchors.verticalCenter: parent
                            //font.pixelSize: 12
                            font.pixelSize: 30
                        }
                    }
                    /*onClicked: {
                        console.log(name);
                    }*/
                    onPressed: {
                        //iconImage.width = 80
                        //iconImage.height = 80
                        iconImage.width = 160
                        iconImage.height = 160
                        //iconName.font.pixelSize = 16
                        iconName.font.pixelSize = 40
                    }
                    onReleased: {
                        clickAppIcon.play()
                        //iconImage.width = 64
                        //iconImage.height = 64
                        iconImage.width = 120
                        iconImage.height = 120
                        //iconName.font.pixelSize = 12
                        iconName.font.pixelSize = 30
                        /*let qml = ""
                        qml += 'import QtQuick 2.11\n'
                        qml += 'import QtQuick.Window 2.11\n'
                        qml += 'import QtQuick.Controls 2.3\n'
                        qml += 'Window {\n'
                        qml += 'width: 300\n'
                        qml += 'height: 300\n'
                        qml += '}'

                        let appWindow = Qt.createQmlObject(qml, firstElement)*/
                        let component = Qt.createComponent("/appWindow/OpenWindow.qml");
                        let appWindow = component.createObject();
                        appWindow.show();
                    }
                }
            }
        }
    }

    Rectangle {
        id: page1
        opacity: 0.2
        anchors.fill: parent
        anchors.margins: 30
        color: 'black'
    }
}
