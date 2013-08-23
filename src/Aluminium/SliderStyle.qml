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

SliderStyle {
    id: slideStyle

    handle: Item {
        implicitWidth: 18
        implicitHeight: 18

        Rectangle {
            id: knobItem
            anchors.fill: parent
            border.color: Qt.darker("#468bb7", 3.0)
            radius: height
            antialiasing: true
            visible: false
        }

        RadialGradient {
            anchors.fill: parent
            source: knobItem
            gradient: Gradient {
                GradientStop { position: 0.0; color: Qt.lighter("#468bb7", 1.2); }
                GradientStop { position: 1.0; color: Qt.darker("#468bb7", 2.2); }
            }
            horizontalOffset: -2
            verticalOffset: 2
        }
    }

    groove: Item {
        property color baseColor: "#f1f1f1"
        property color highlightColor: "#468bb7"

        implicitWidth: 100
        implicitHeight: 10

        Rectangle {
            anchors.verticalCenter: parent.verticalCenter
            width: parent.width
            height: 8
            border.color: Qt.darker(baseColor, 3.0)
            radius: height / 2
            gradient: Gradient {
                GradientStop { position: 0.0; color: Qt.darker(baseColor, 2.0); }
                GradientStop { position: 0.38; color: Qt.darker(baseColor, 1.5); }
                GradientStop { position: 0.99; color: Qt.darker(baseColor, 1.2); }
                GradientStop { position: 1.0; color: Qt.darker(baseColor, 1.1); }
            }
            antialiasing: true
            opacity: 0.8

            Rectangle {
                width: parent.width * control.value / control.maximumValue
                height: parent.height
                border.color: Qt.darker(highlightColor, 3.0)
                radius: height / 2
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#2a536e"; }
                    GradientStop { position: 0.38; color: "#3d7aa0"; }
                    GradientStop { position: 0.99; color: "#468bb7"; }
                    GradientStop { position: 1.0; color: "#4991bf"; }
                }
                antialiasing: true
            }
        }
    }
}
