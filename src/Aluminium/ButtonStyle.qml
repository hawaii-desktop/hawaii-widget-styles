/****************************************************************************
 * This file is part of Hawaii Widget Styles.
 *
 * Copyright (C) 2013-2014 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
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

ButtonStyle {
    id: buttonStyle

    property int radii: 5
    property int margin: 10
    property color fgColor: "#333333"
    property color bgColor: "#ededed"

    padding {
        top: margin
        left: margin
        right: margin
        bottom: margin
    }

    label: Text {
        renderType: Text.NativeRendering
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        text: control.text
        color: fgColor
        style: Text.Raised
        styleColor: Qt.lighter(bgColor, 1.25)
    }

    background: Item {
        implicitWidth: 100
        implicitHeight: 30

        Rectangle {
            anchors.fill: parent
            color: "transparent"
            border {
                width: 4
                color: control.activeFocus ? "#401094ff" : "transparent"
            }
            radius: radii
            antialiasing: true

            Rectangle {
                property bool pressed: control.pressed

                id: mainItem
                anchors {
                    fill: parent
                    margins: 2
                }
                border.color: "#a7aba7"
                gradient: Gradient {
                    GradientStop { position: 0.0; color: pressed ? "#7d7d7d" : Qt.lighter(bgColor, 1.05); }
                    GradientStop { position: 0.4; color: pressed ? "#9e9e9e" : bgColor; }
                    GradientStop { position: 1.0; color: pressed ? "#999999" : Qt.darker(bgColor, 1.08); }
                }
                radius: radii
                antialiasing: true
                visible: false
            }

            DropShadow {
                anchors.fill: mainItem
                horizontalOffset: 1
                verticalOffset: 1
                radius: 8
                samples: 16
                spread: 0
                fast: true
                transparentBorder: true
                color: "#40000000"
                source: mainItem
            }
        }
    }
}
