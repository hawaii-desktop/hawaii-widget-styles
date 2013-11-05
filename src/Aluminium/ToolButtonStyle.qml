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
import QtQuick.Controls.Private 1.0
import FluidUi 0.2 as FluidUi

ToolButtonStyle {
    id: toolButtonStyle

    property int radii: 5
    property color fgColor: "#333333"
    property color bgColor: "#ededed"

    padding {
        left: 4
        top: 4
        right: 4
        bottom: 4
    }

    panel: Rectangle {
        implicitWidth: 36
        implicitHeight: 36
        border.color: "#a7aba7"
        radius: radii
        gradient: Gradient {
            GradientStop { position: 0.0; color: pressed ? "#7d7d7d" : Qt.lighter(bgColor, 1.05); }
            GradientStop { position: 0.4; color: pressed ? "#9e9e9e" : bgColor; }
            GradientStop { position: 1.0; color: pressed ? "#999999" : Qt.darker(bgColor, 1.08); }
        }
        antialiasing: true

        readonly property bool hasIcon: icon.status === Image.Ready || icon.status === Image.Loading
        readonly property bool pressed: control.pressed || (control.checkable && control.checked)

        Item {
            anchors {
                left: parent.left
                top: parent.top
                right: arrow.left
                bottom: parent.bottom
            }
            clip: true

            Text {
                id: label
                anchors.centerIn: parent
                text: control.text
                visible: !hasIcon
            }

            FluidUi.Icon {
                id: icon
                anchors.centerIn: parent
                iconName: control.__action.iconName ? control.__action.iconName : ""
                iconSource: {
                    if (control.__action && !control.__action.iconName)
                        return control.__action.iconSource;
                    if (control.iconSource)
                        return control.iconSource;
                    return "";
                }

                width: 24
                height: 24
                color: toolButtonStyle.fgColor
            }
        }

        Image {
            id: arrow
            anchors {
                verticalCenter: parent.verticalCenter
                right: parent.right
                rightMargin: visible ? 3 : 0
            }
            source: visible ? "images/arrow-down.png" : ""
            opacity: control.enabled ? 0.7 : 0.5
            visible: control.menu !== null
        }
    }
}
