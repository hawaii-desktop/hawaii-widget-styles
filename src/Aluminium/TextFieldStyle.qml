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

TextFieldStyle {
    id: textFieldStyle

    property int radii: 5
    property color bgColor: "#eeeeee"

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
                id: mainItem
                anchors {
                    fill: parent
                    margins: 2
                }
                border.color: "#40000000"
                radius: radii
                antialiasing: true
                visible: false

                Rectangle {
                    anchors {
                        fill: parent
                        margins: 2
                    }
                    gradient: Gradient {
                        GradientStop { position: 0.0; color: Qt.lighter(bgColor, 0.94); }
                        GradientStop { position: 0.25; color: bgColor; }
                        GradientStop { position: 1.0; color: Qt.lighter(bgColor, 1.25); }
                    }
                }
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
                color: "#809f9f9f"
                source: mainItem
            }
        }
    }
}
