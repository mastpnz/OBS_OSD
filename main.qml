import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: squad_windows
    width: 1600
    height: 800
    visible: true
    color: "#00000000"
    title: qsTr("OSD Squad")

    Column {
        id: base_column
        width: 1600
        height: 800
        spacing: 10
        Row {
            id: header_row
            anchors.horizontalCenter: parent.horizontalCenter
            Rectangle {
                id: header_rect
                width: header_text.width + 100
                height: header_text.height + 20
                color: "#30303030"
                Text {
                        id: header_text
                        anchors.centerIn: parent
                        font.pixelSize: 30
                        color: "black"
                        text: qsTr("Составы")
                }
            }
        }
        Row {
            id: teams_row
            anchors.left: parent.left
            anchors.right: parent.right
            Column {
                id: left_team_column
                width: parent.width / 2
                height: 500
                Rectangle {
                    anchors.fill: parent
                    color: "red"
                }
            }
            Column {
                id: right_team_column
                width: parent.width / 2
                height: 500
                Rectangle {
                    anchors.fill: parent
                    color: "blue"
                }
            }
        }
    }
}
