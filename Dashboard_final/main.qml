import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.3
import QtMultimedia 5.0
//import QtQuick.Controls 1.4 as C1
//import QtQml.Models 2.0
//import QtQuick.Layouts 1.1


ApplicationWindow {
    id: dashboard
    height: maximumHeight
    width: maximumWidth

    /*
    width: 1200
    height: 800
    */

    visible: false

    Loader {
        id: splashLoader
        source: "/appWindow/Splash.qml"
    }

    Audio {
        id: slidePage
        source: "/sounds/slide_effect.wav"
    }
    Connections {
        id: splashConnection
        target: splashLoader.item
        //onTimeout: {
            //connection.target = null;
            //loader.sourceComponent = root;
            //dashboard.visible = true
        //}
    }

    background: Image {
        id: layoutBackground
        source: "/bg/bg_5.jpg"
        fillMode: Image.Tile
        //horizontalAlignment: Image.AlignLeft
        //verticalAlignment: Image.AlignTop
    }




    /*Connections {
        id: splashConnection
        target: splashLoader.item
        //onTimeout: {
        //    //connection.target = null;
        //    //loader.sourceComponent = root;
        //    dashboard.visible = true
        //}
    }*/

    /*background: AnimatedImage {
        id: layoutBackground
        //height: maximumHeight
        //width: maximumWidth

        height: dashboard.height
        width: dashboard.width


        //width: 1200
        //height: 800

        source: "/bg/sakura_bg.gif"
    }*/

    /*property int myMouseX: -1
    property int myMouseY: -1
    Text {
        id: coordinate
        text: qsTr("X: " + myMouseX + " - Y: " + myMouseY)
    }*/

    SwipeView {
        id: view
        anchors.fill: parent
        currentIndex: 0
        onCurrentIndexChanged: {
            slidePage.play()
        }

        Loader {
            source: "/swipePages/PageOne.qml"
        }
        Loader {
            source: "/swipePages/PageTwo.qml"
        }
        Loader {
            source: "/swipePages/PageThree.qml"
        }
        Loader {
            source: "/swipePages/PageFour.qml"
        }
        Loader {
            source: "/swipePages/PageFive.qml"
        }
        // connection kısmı var ona da bak
    }

    PageIndicator {
        id: indicat1or
        interactive: true
        visible: false
        count: view.count
        currentIndex: view.currentIndex
        opacity: 1
        anchors.margins: 5
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
