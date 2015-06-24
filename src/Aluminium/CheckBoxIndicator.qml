/****************************************************************************
 * This file is part of Hawaii Widget Styles.
 *
 * Copyright (C) 2013-2015 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
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
import Hawaii.Themes 1.0 as Themes
import "Constants.js" as Constants
import "ColorUtils.js" as ColorUtils

Item {
    width: Constants.indicatorSize
    height: width

    Rectangle {
        anchors.fill: parent
        color: "transparent"
        border {
            width: 2
            color: control.activeFocus ? ColorUtils.adjustAlpha(syspal.highlight, 0.7) : "transparent"
        }
        antialiasing: true

        Rectangle {
            id: mainItem
            anchors {
                fill: parent
                margins: 2
            }
            border.color: ColorUtils.adjustAlpha(syspal.dark, 0.5)
            color: Qt.darker("white", 1.0)
            antialiasing: true
            opacity: control.enabled ? 1.0 : 0.5

            Rectangle {
                anchors {
                    fill: parent
                    topMargin: control.checkedState == Qt.PartiallyChecked ? 6 : undefined
                    bottomMargin: control.checkedState == Qt.PartiallyChecked ? 6 : undefined
                    margins: mainItem.width / 4
                }
                antialiasing: true
                color: syspal.highlight
                opacity: control.checked ? 1.0 : 0.0

                Behavior on opacity { PropertyAnimation { duration: 100 } }
            }
        }
    }
}
