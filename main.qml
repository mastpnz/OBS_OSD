import QtQuick 2.12
import QtQuick.Window 2.12
import "./"
import QtQuick.Dialogs 1.3

Window {
    id: squad_window
    width: 1600
    height: 800
    visible: true
    color: "#00000000"
    title: qsTr("OSD Squad")
    property var rightTeamSquad: ""

    MessageDialog {
        id: messageDialog
        title: "May I have your attention please"
        text: "It's so cool that you are using Qt Quick."
        onAccepted: {
            console.log("And of course you could only agree.")
            close()
        }
        Component.onCompleted: visible = false
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            var path = fileDialog.fileUrl.toString();
            path = path.replace(/^(file:\/{2})/,"");
            m_data.callMe(decodeURIComponent(path))
            fileDialog.close()
        }
        onRejected: {
            fileDialog.close()
        }
        Component.onCompleted: visible = false
    }

    Connections {
        target: m_data
        onRightTeamSetted: {
            rightTeamSquad = rightSquad
        }
    }

    Column {
        id: base_column
        anchors.fill: parent
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
                        color: "white"
                        text: qsTr("Составы")
                }
            }
        }
        Row {
            id: teams_row
            anchors.top: header_row.bottom
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            Column {
                id: left_team_column
                width: parent.width / 2
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                Rectangle {
                    anchors.fill: parent
                    color: "red"
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                             messageDialog.open();
                        }
                    }
                }
            }
            Column {
                id: right_team_column
                width: parent.width / 2
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.right: parent.right
                Rectangle {
                    anchors.fill: parent
                    color: "blue"
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                             fileDialog.open();
                        }
                    }
//
                }
            }
        }
    }
}
