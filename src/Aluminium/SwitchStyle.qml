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
import QtQuick.Controls.Styles 1.1

SwitchStyle {
    property int radii: 5
    property int margin: 2
    property color bgColor: "#eeeeee"
    property color buttonColor: Qt.lighter(bgColor, 1.02)

    padding {
        left: margin
        top: margin
        right: margin
        bottom: margin
    }

    handle: Rectangle {
        implicitWidth: 30
        implicitHeight: 24
        border.color: "#44000000"
        radius: radii - 1
        antialiasing: true

        Rectangle {
            anchors {
                fill: parent
                margins: 1
            }
            radius: radii - 1
            gradient: Gradient {
                GradientStop { position: 0.0; color: Qt.lighter(buttonColor, 1.08); }
                GradientStop { position: 0.5; color: buttonColor; }
                GradientStop { position: 1.0; color: Qt.lighter(buttonColor, 0.95); }
            }
        }
    }
    groove: Rectangle {
        property color highlightColor: "#468bb7"
        property color shadow: control.checked ? Qt.darker(highlightColor, 1.2) : "#999"
        property color bg: control.checked ? highlightColor : "#bbb"
        property alias l: label

        Behavior on shadow {
            ColorAnimation { duration: 80 }
        }

        Behavior on bg {
            ColorAnimation { duration: 80 }
        }

        implicitWidth: 64
        implicitHeight: 24
        radius: radii
        antialiasing: true
        gradient: Gradient {
            GradientStop { position: 0.0; color: shadow }
            GradientStop { position: 0.2; color: bg }
            GradientStop { position: 1.0; color: bg }
        }

        Rectangle {
            anchors {
                bottom: parent.bottom
                bottomMargin: -1
            }
            width: parent.width - 2
            x: 1
            height: 1
            color: "#44ffffff"
        }

        Text {
            property color fgColor: "#333333"
            property color highlightedFgColor: "#ffffff"
            property color fg: control.checked ? highlightedFgColor : fgColor

            Behavior on fg {
                ColorAnimation { duration: 80 }
            }

            id: label
            anchors.verticalCenter: parent.verticalCenter
            renderType: Text.NativeRendering
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            text: control.checked ? "ON" : "OFF"
            color: fg
            style: Text.Raised
            styleColor: control.checked ? Qt.darker(buttonColor, 1.25) : Qt.lighter(buttonColor, 1.25)
            states: [
                State {
                    name: "on"
                    when: control.checked

                    AnchorChanges {
                        target: label
                        anchors.left: parent.left
                    }
                    PropertyChanges {
                        target: label
                        anchors.leftMargin: (34 - label.paintedWidth) / 2
                    }
                },
                State {
                    name: "off"
                    when: !control.checked

                    AnchorChanges {
                        target: label
                        anchors.right: parent.right
                    }
                    PropertyChanges {
                        target: label
                        anchors.rightMargin: (34 - label.paintedWidth) / 2
                    }
                }
            ]
        }
    }
}
