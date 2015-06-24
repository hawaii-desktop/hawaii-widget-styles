/****************************************************************************
 * This file is part of Hawaii Widget Styles.
 *
 * Copyright (C) 2015 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * Author(s):
 *    Pier Luigi Fiorini
 *
 * $BEGIN_LICENSE:LGPL2.1+$
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $END_LICENSE$
 ***************************************************************************/

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
