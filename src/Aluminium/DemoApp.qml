/*
 * Derived from breeze/qtquickcontrols/BreezeApp.qml
 * which doesn't carry any copyright information.
 */

import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import Hawaii.Themes 1.0 as Themes

ApplicationWindow {
    width: Themes.Units.dp(640)
    height: Themes.Units.dp(480)
    title: "Aluminium Style Demo"
    style: ApplicationWindowStyle{} //Commented out to see if works when QT_QUICK_CONTROLS_STYLE=Aluminium is set

    TabView {
        id: tabView
        anchors.fill: parent
        anchors.leftMargin: 8
        anchors.topMargin: 12
        anchors.rightMargin: 8
        anchors.bottomMargin: 52
        style: TabViewStyle{} //Commented out to see if works when QT_QUICK_CONTROLS_STYLE=Aluminium is set
        frameVisible: true
        Component.onCompleted: {
            addTab("Tab 1", page1)
            addTab("Tab 2", page2)
            addTab("Tab 3", page3)
            addTab("Tab 4", page4)
            addTab("Tab 5", page5)
        }
        Component {
            id: page1
            DemoPage1 {}
        }
        Component {
            id: page2
            DemoPage2 {}
        }
        Component {
            id: page3
            DemoPage3 {}
        }
        Component {
            id: page4
            DemoPage4 {}
        }
        Component {
            id: page5
            DemoPage5 {}
        }
    }
    Item {
        anchors.top: tabView.bottom
        anchors.left:parent.left
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.margins: 8
        Button {
            focus: true
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            style: ButtonStyle{} //Commented out to see if works when QT_QUICK_CONTROLS_STYLE=Aluminium is set
            text: "Close"
            onClicked: Qt.quit()
        }
    }
}
