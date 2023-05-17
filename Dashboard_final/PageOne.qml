import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.3
import QtMultimedia 5.0

/*Item {
    id: firstElement

    Rectangle {
        id: firstRect
        opacity: 0.3
        anchors.fill: parent
        anchors.margins: 30
        color: 'black'

        MouseArea {
            anchors.fill: parent
            onClicked: setWidth(firstElement.width + 10)
        }

        C1.SplitView {
            anchors.fill: parent

        }



        Component {
            id: contactDelegate
            Item {
                width: grid.cellWidth; height: grid.cellHeight
                Column {
                    anchors.fill: parent
                    Image { source: portrait; anchors.horizontalCenter: parent.horizontalCenter }
                    Text { text: name; anchors.horizontalCenter: parent.horizontalCenter }
                }
            }
        }

        GridView {
            id: grid
            width: parent.width*0.9
            height: parent.height*0.9
            anchors.fill: parent
            anchors.margins: 40
            cellWidth: 80
            cellHeight: 80
            //highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
            //highlight: Rectangle { color: "black"; radius: 5; opacity: 1}
            focus: true

            model: contactDelegate
            delegate:  Column {
                width: grid.cellWidth*0.8
                height: grid.cellHeight*0.8

                Image { source: portrait; anchors.horizontalCenter: parent.horizontalCenter; }
                Text { text: name; anchors.horizontalCenter: parent.horizontalCenter }
            }
        }
    }
}*/

Item {
    ListModel {
        id: contactDelegate

        ListElement {
            name: "9GAG"
            portrait: "/9gag.png"
            pageIndex: 1
        }
        ListElement {
            name: "ADDR BOOK"
            portrait: "/address_book.png"
        }
        ListElement {
            name: "ADMIN"
            portrait: "/admin.png"
        }
        ListElement {
            name: "CALC"
            portrait: "/calculator.png"
        }
        ListElement {
            name: "CALL"
            portrait: "/call.png"
        }
        ListElement {
            name: "CAMERA"
            portrait: "/camera.png"
        }
        ListElement {
            name: "CLOSE"
            portrait: "/close.png"
        }
        ListElement {
            name: "DELETE"
            portrait: "/delete.png"
        }
        ListElement {
            name: "DIC"
            portrait: "/dictionary.png"
        }
        ListElement {
            name: "DISCORD"
            portrait: "/discord.png"
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

    Loader {
        id: newAppWindowLoader
        active: false
        source: "/appWindow/OpenWindow.qml"
    }

    Grid {
        width: page1.width
        anchors.fill: page1
        anchors.topMargin: 30
        columns: 4
        //rowSpacing: 20
        rowSpacing: 30

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
                    /*MouseArea {
                        anchors.fill: cellButton*/
                    onClicked: {
                        console.log(name);
                        //newAppWindowLoader.active = true

                    }
                    onPressed: {
                        //console.log(name);
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
                        //appWindow.visibility = Window.FullScreen
                        appWindow.show();

                    }
                    //}
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
