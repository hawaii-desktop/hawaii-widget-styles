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

ToolButtonStyle {
    panel: Item {
        implicitWidth: 36
        implicitHeight: 36

        Rectangle {
            id: mainItem
            anchors.fill: parent
            border.color: "#999"
            radius: 6
            antialiasing: true
            visible: false

            Rectangle {
                anchors.fill: parent
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#f7f7f7" }
                    GradientStop { position: 1.0; color: "#aaa" }
                }
                radius: 6
                antialiasing: true
                visible: !control.pressed
            }

            Rectangle {
                anchors.fill: parent
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#dedede"; }
                    GradientStop { position: 0.38; color: "#ededed"; }
                    GradientStop { position: 1.0; color: "#ededed"; }
                }
                radius: 6
                antialiasing: true
                visible: control.pressed
            }

            Image {
                id: icon
                anchors.centerIn: parent
                source: control.iconSource
                sourceSize: Qt.size(24, 24)
            }

            Text {
                id: label
                anchors.centerIn: parent
                text: control.text
                visible: icon.status != Image.Ready
            }
        }

        DropShadow {
            anchors.fill: mainItem
            horizontalOffset: 0
            verticalOffset: 1
            radius: 4
            samples: 16
            spread: 0
            color: "#40000000"
            source: mainItem
            transparentBorder: true
        }
    }
}
