import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Shapes 1.12

Item {
    property string name: ""
    property string number: ""
    property string position: ""
    property string role: ""

    height: number_txt.height + 10
    id: player_info
    Rectangle {
        anchors.fill: parent
        color: "#30303030"
        Row {
            spacing: 10
            anchors.verticalCenter: parent.verticalCenter
            Text {
                id: number_txt
                font.pixelSize: 20
                text: number
            }
            Text {
                id: position_txt
                font.pixelSize: 20
                text: position
            }
            Text {
                id: fio_txt
                font.pixelSize: 20
                text: name
            }
            Text {
                id: role_txt
                font.pixelSize: 20
                text: role
            }
        }
    }
}
