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

ToolButtonStyle {
    property int radii: 5
    property color fgColor: "#333333"
    property color bgColor: "#eeeeee"
    property color buttonColor: Qt.darker(bgColor, 1.02)

    panel: Rectangle {
        implicitWidth: 36
        implicitHeight: 36
        border.color: "#44000000"
        radius: radii
        antialiasing: true

        readonly property bool hasIcon: icon.status === Image.Ready || icon.status === Image.Loading

        Rectangle {
            anchors {
                fill: parent
                margins: 1
            }
            radius: radii - 1
            gradient: Gradient {
                GradientStop { position: 0.0; color: Qt.lighter(buttonColor, 1.02); }
                GradientStop { position: 0.5; color: buttonColor; }
                GradientStop { position: 1.0; color: Qt.lighter(buttonColor, 0.95); }
            }
            opacity: control.pressed || (control.checkable && control.checked) ? 0.0 : 1.0

            Behavior on opacity {
                NumberAnimation { duration: 80 }
            }
        }

        Rectangle {
            anchors {
                fill: parent
                margins: 1
            }
            radius: radii
            gradient: Gradient {
                GradientStop { position: 0.0; color: Qt.lighter(buttonColor, 0.85); }
                GradientStop { position: 0.5; color: buttonColor; }
                GradientStop { position: 1.0; color: Qt.lighter(buttonColor, 0.98); }
            }
            opacity: control.pressed || (control.checkable && control.checked) ? 1.0 : 0.0

            Behavior on opacity {
                NumberAnimation { duration: 80 }
            }
        }

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

            Image {
                id: icon
                anchors.centerIn: parent
                source: {
                    if (control.__action) {
                        if (control.__action.iconName)
                            return "image://desktoptheme/" + control.__action.iconName;
                        return control.__action.iconSource;
                    }
                    return control.iconSource;
                }
                sourceSize.width: width
                sourceSize.height: height
                width: 24
                height: 24
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
