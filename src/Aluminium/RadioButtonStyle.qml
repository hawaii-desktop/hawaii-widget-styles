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

RadioButtonStyle {
    id: radioButton

    label: Text {
        renderType: Text.NativeRendering
        verticalAlignment: Text.AlignVCenter
        text: control.text
        color: __syspal.text
        style: Text.Raised
        styleColor: "white"
    }

    indicator: Item {
        implicitWidth: 40
        implicitHeight: 40

        Rectangle {
            anchors.fill: parent
            color: "transparent"
            border {
                width: 2
                color: control.activeFocus ? "#401094ff" : "transparent"
            }
            radius: width
            antialiasing: true

            Rectangle {
                id: mainItem
                anchors {
                    fill: parent
                    margins: 2
                }
                border.color: "#40000000"
                color: Qt.darker("white", 1.0)
                radius: width
                antialiasing: true
                opacity: control.enabled ? 1.0 : 0.5
                visible: false

                Rectangle {
                    anchors {
                        fill: parent
                        margins: mainItem.width / 4
                    }
                    radius: anchors.margins
                    antialiasing: true
                    color: "#468bb7"
                    opacity: control.checked ? 1.0 : 0.0

                    Behavior on opacity { PropertyAnimation { duration: 100 } }
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
}
