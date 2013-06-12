/****************************************************************************
 * This file is part of Hawaii Widget Styles.
 *
 * Copyright (C) 2013 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
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

import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtGraphicalEffects 1.0

TabViewStyle {
    id: tabViewStyle
    frameOverlap: 11
    tabsAlignment: Qt.AlignHCenter

    /*! \internal */
    property var __syspal: SystemPalette {
        colorGroup: control.enabled ?
                        SystemPalette.Active : SystemPalette.Disabled
    }

    tab: Rectangle {
        property int padding: 2

        implicitWidth: Math.max(text.paintedWidth + 4, 80) + padding * 2
        implicitHeight: Math.max(text.paintedHeight, 20) + padding * 2
        border.color: Qt.darker(__syspal.button, 1.5)
        radius: 6
        gradient: Gradient {
            GradientStop { position: 0.0; color: Qt.lighter(__syspal.button, 1.2) }
            GradientStop { position: 0.38; color: Qt.darker(__syspal.button, 1.1) }
            GradientStop { position: 1.0; color: Qt.darker(__syspal.button, 1.1) }
        }
        antialiasing: true

        Text {
            id: text
            anchors {
                fill: parent
                margins: padding
            }
            text: styleData.title
            renderType: Text.NativeRendering
            color: __syspal.text
            horizontalAlignment: Qt.AlignHCenter
        }
    }
    frame: Item {
        Rectangle {
            id: mainItem
            anchors.fill: parent
            color: Qt.darker(__syspal.window, 1.1)
/*
            gradient: Gradient {
                GradientStop { position: 0; color: Qt.darker(__syspal.window, 1.2) }
                GradientStop { position: 0.1; color: Qt.darker(__syspal.window, 1.3) }
                GradientStop { position: 0.11; color: Qt.darker(__syspal.window, 1.1) }
            }
*/
            radius: 6
            border.color: Qt.darker(__syspal.window, 1.5)
            antialiasing: true
            visible: false

            Rectangle {
                anchors {
                   fill: parent
                    leftMargin: 1
                    topMargin: 1
                    rightMargin: 1
                    bottomMargin: -1
                }
                z: -1
                color: "transparent"
                radius: 6
                border.color: Qt.lighter(__syspal.window, 1.2)
                antialiasing: true
            }
        }

        DropShadow {
            anchors.fill: mainItem
            horizontalOffset: 0
            verticalOffset: 1
            radius: 8
            samples: 16
            spread: 0
            color: "#40000000"
            source: mainItem
        }
    }
}
