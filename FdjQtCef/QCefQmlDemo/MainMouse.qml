import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    visible: true
    width: 640
    height: 480

    MouseArea{
        anchors.fill: parent
//        onClicked: console.log("~root clicked")
//        onDoubleClicked: console.log("~root double")
//        onPressAndHold: console.log("~root hold")

        onPressed: console.log("~root pressed")
        onReleased: console.log("~root released")
    }

    //item的层级在root之上（因为他写在mousearea的后面，又是同级的）
    Rectangle{
        width: 200
        height: 200
        //color: "green"
        //灰色0.9透明度
        color:Qt.rgba(0.5,0.5,0.5,1.0)

        MainFrame{

            anchors.fill: parent;
        }

        MouseArea{
            anchors.fill: parent
            //是否传递到被覆盖的MouseArea
            propagateComposedEvents: true
            //开启组合事件的传递
//            onClicked: {
//                console.log("item clicked")
//                //组合事件可以不写处理程序，或者accepted为false
//                mouse.accepted = false
//            }
//            onDoubleClicked: console.log("item double")
//            //onPressAndHold: console.log("item hold")

            onPressed: {
                console.log("item pressed")
                mouse.accepted=false
            }
            onReleased: {
                console.log("item released")
                mouse.accepted=true
            }
        }
        //没有写处理程序的hold和写了mouse.accepted = false的click传递到了被遮挡的MouseArea，
        //而doubleClick则没有传递
        //事件传递
    }
}


//参考 https://blog.csdn.net/gongjianbo1992/article/details/103121853?utm_medium=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.edu_weight&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.edu_weight
