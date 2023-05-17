import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.3
import QtMultimedia 5.0

Window {
    id: splashScreen
    visible: true
    //    x: 0
    //    y: 0
    //width: dashboard.width
    //height: dashboard.height

    Component.onCompleted: {
        splashScreen.showFullScreen();
    }

    Rectangle {
        id: splashScreenEffect
        anchors.centerIn: parent
        width: 300
        height: 300
        //height: maximumHeight
        //width: maximumWidth
        //width: dashboard.width
        //height: dashboard.height


        /*
        width: 1200
        height: 800
        */
        AnimatedImage {
            id: splashScreenBackground
            //width: dashboard.width
            //height: dashboard.height
            //anchors.horizontalCenter: parent.Center
            //anchors.verticalCenter: parent.Center
            anchors.horizontalCenter: splashScreenEffect.Center
            anchors.verticalCenter: splashScreenEffect.Center
            //width: 300
            //height: 300
            source: "/bg/splashscreen2.gif"
        }
    }

    Timer {
        interval: 4250;
        running: true;
        repeat: false
        onTriggered: {
            visible = false
            //splashScreen.timeout()
            dashboard.visible = true
            dashboard.showFullScreen();
            splashScreen.close()
        }
    }

    Audio {
        id: splashSound
        source: "/sounds/splash_effect.wav"
        autoPlay: true
    }

    /*
    SoundEffect {
        id: splashSound
        source: "/sounds/splash_effect.wav"
    }
    MouseArea {
        Component.onCompleted: splashSound.play()
    }
    */
}
