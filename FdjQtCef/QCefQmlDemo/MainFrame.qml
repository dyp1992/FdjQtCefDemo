import QtQuick 2.0

BaseMainFrame
//Rectangle
{
    id: mainframe

    width: parent.width
    height: parent.height

    Component.onCompleted: {
        //m_btnTest.visible = true;
        //解释性语言  ReferenceError: m_btnTest is not defined
        //不是C++的继承
        m_btnUpdate.visible = true
    }
}
