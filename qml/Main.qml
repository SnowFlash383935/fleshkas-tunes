import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 960
    height: 640
    visible: true
    title: "Fleshka's Tunes"

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 32
        spacing: 16

        Label {
            text: "Fleshka's Tunes"
            font.pixelSize: 36
            font.bold: true
        }

        Label {
            text: "Hello, Qt 6 + QML!"
            font.pixelSize: 20
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            radius: 18
            border.width: 1

            Text {
                anchors.centerIn: parent
                text: "QML is alive ✨"
                font.pixelSize: 28
            }
        }

        Button {
            text: "Play"
        }
    }
}
