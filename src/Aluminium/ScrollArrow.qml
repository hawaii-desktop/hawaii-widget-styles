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

/*
 * Derived from breeze/qtquickcontrols/ScrollArrow.qml
 * which doesn't carry any copyright information.
 */

import QtQuick 2.0

Rectangle {
    id: arrowRoot
    implicitWidth: 20
    implicitHeight: 20
    color: "transparent"
    property color arrowColor

    Item {
        width: upStroke.width * 2
        height: 6
        anchors.centerIn: parent
        Rectangle {
            id: upStroke
            x: 0
            y: 0
            width: 6
            height: 2
            radius: 1
            smooth: true
            transform: Rotation {
                origin.x: upStroke.width
                origin.y: upStroke.height / 2
                angle: -45
            }
            color: arrowColor
        }
        Rectangle {
            anchors.left: upStroke.right
            anchors.top:  upStroke.top
            width: upStroke.width
            height: upStroke.height
            radius: upStroke.radius
            smooth: true
            transform: Rotation {
                origin.x: 0
                origin.y: upStroke.height / 2
                angle: 45
            }
            color: arrowColor
        }
    }
}
