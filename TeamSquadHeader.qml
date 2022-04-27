import QtQuick 2.0

Item {
    property string name: ""
    property string gorod: ""
    property string coach_name: ""
    property string logo_path: ""

    height: 100
    id: team_header
    Row {
        Image {
                 id: logo
                 width: parent.height
                 height: parent.height
                 horizontalAlignment: Image.AlignHCenter
                 verticalAlignment: Image.AlignVCenter
                 fillMode: Image.PreserveAspectFit
                 source: logo_path
        }
        Column {
            Text {
                id: team_name
                text: name
                font.pixelSize: team_header.height / 2
            }
            Text {
                id: coach
                text: "Тренер: " + coach_name
                font.pixelSize: team_header.height / 4
            }
        }

    }
}
