import QtQuick 2.15
import QtQuick.Controls 2.15
import "../components"

Page {
    title: qsTr("Library")

    Grid {
        verticalItemAlignment: Grid.AlignVCenter
        horizontalItemAlignment: Grid.AlignHCenter
        spacing: 30
        padding: 30

        GameCase {
            gameId: 1
            imgSource: "https://upload.wikimedia.org/wikipedia/en/0/0c/Witcher_3_cover_art.jpg"
        }

        GameCase {
            gameId: 2
            imgSource: "https://upload.wikimedia.org/wikipedia/en/b/b0/Mass_Effect_3_Game_Cover.jpg"
        }

        GameCase {
            gameId: 3
            btnWidth: 240
            btnHeight: 280
            imgSource: "https://www.mobygames.com/images/covers/l/178926-final-fantasy-xiii-playstation-3-front-cover.jpg"
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
