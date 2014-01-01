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
import QtQuick.Controls.Private 1.0

ToolBarStyle {
    id: toolBarStyle

    property color baseColor: "#ededed"

    panel: Rectangle {
        gradient: Gradient {
            GradientStop { position: 0.0; color: Qt.lighter(baseColor, 1.25); }
            GradientStop { position: 0.2; color: Qt.lighter(baseColor, 1.25); }
            GradientStop { position: 1.0; color: Qt.darker(baseColor, 1.15); }
        }

        Image {
            anchors.fill: parent
            source: "images/noise-texture.png"
            sourceSize: Qt.size(100, 100)
            fillMode: Image.TileHorizontally

            Rectangle {
                anchors.bottom: parent.bottom
                width: parent.width
                height: 1
                color: "#999"
            }
        }
    }
}
