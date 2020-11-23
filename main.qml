import QtQuick 2.15
import QtQuick.Window 2.15

import MyRectangle 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Flickable {
        anchors.fill: parent
        contentWidth: 800
        contentHeight: 800

        MyRectangle {
            x: 200
            y: 200
            width: 100
            height: 100
        }
    }
}
