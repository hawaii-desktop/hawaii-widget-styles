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
 * Derived from breeze/qtquickcontrols/ScrollBar.qml
 * which doesn't carry any copyright information.
 */

import QtQuick 2.0
import "ColorUtils.js" as ColorUtils

Rectangle {
    SystemPalette { id: sysPalette; colorGroup: SystemPalette.Active }
    opacity: control.enabled ? 1.0 : 0.5
    anchors.centerIn: parent
    implicitWidth: styleData.horizontal ? 300 : 20
    implicitHeight: styleData.horizontal ? 20 : 300
    color: "transparent"
    property alias barColor: __barFill.color
    property alias barBorder: __barFill.border
    property real percentWidth: 0.5
    property alias showShadow: __shadow.visible
    property alias showHandle: __handle.visible
    property alias handleColor: __handle.color
    property alias handleBorder: __handle.border

    Rectangle {
        id: __barFill
        anchors.fill: parent
        anchors.leftMargin: styleData.horizontal ? 0 : 0.5 * (1 - percentWidth) * 20
        anchors.rightMargin: styleData.horizontal ? 0 : 0.5 * (1 - percentWidth) * 20
        anchors.topMargin: styleData.horizontal ? 0.5 * (1 - percentWidth) * 20 : 0
        anchors.bottomMargin: styleData.horizontal ? 0.5 * (1 - percentWidth) * 20 : 0
        color: "red"
        radius: width/2
    }

    Rectangle {
        id: __shadow
        visible: false
        anchors.centerIn: __barFill
        width: 20
        height: 20
        color: ColorUtils.adjustAlpha(sysPalette.windowText, 0.15)
        radius: width/2
        transform: Translate {
            x: 0
            y: 0
        }
    }

    Rectangle {
        id: __handle
        visible: false
        anchors.centerIn: __barFill
        width: 20
        height: 20
        color: "red"
        radius: width/2
        transform: Translate {
            x: __shadow.visible ? (styleData.pressed ? 0 : -1) : 0
            y: __shadow.visible ? (styleData.pressed ? 0 : -1) : 0
        }
    }

}
