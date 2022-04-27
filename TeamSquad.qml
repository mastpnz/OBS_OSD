import QtQuick 2.0
import "./"

Item {
    property model mModel: ""

    Column {
        anchors.fill: parent
        spacing: 10
        TeamSquadHeader {
            id: right_team_header
            name: "Команда 1 // Город 1"
            coach_name: "Ivanov Ivan Ivanovich"
            logo_path: "file://home/mast/osb_board/lt_logo.png"
        }
        Grid {
            anchors.top: right_team_header.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            columns: 2
            spacing: 5
            leftPadding: 20
            rightPadding: 5
            topPadding: 5
            Repeater {
                model: rightTeamSquad.length
                PersonSquad {
                    width: (parent.width - 20 - 5 - 5 ) / 2
                    name: rightTeamSquad[index]["name"]
                    number: rightTeamSquad[index]["number"]
                    position: rightTeamSquad[index]["position"]
                    role: rightTeamSquad[index]["role"]
                }
            }
        }
    }
}
