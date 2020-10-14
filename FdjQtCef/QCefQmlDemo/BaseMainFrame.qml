import QtQuick 2.0
import QtQuick.Controls 2.5

Item {
    id: _baseMainFrame
    anchors.fill: parent;

    property alias m_btnUpdate : m_btnTest;

    Button
    {
        id: m_btnTest
        visible: false;
        width: 40
        height: 20
        text: "text"
        onClicked: {
            console.log("clicked..")
        }
    }
    function updateInfo(){}
}
//放置一个按钮，默认初始隐藏不显示
