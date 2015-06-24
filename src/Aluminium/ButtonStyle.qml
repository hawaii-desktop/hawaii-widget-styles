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
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.1 as QtQuickControlsStyles
import Hawaii.Themes 1.0 as Themes
import "ColorUtils.js" as ColorUtils

QtQuickControlsStyles.ButtonStyle {
    id: buttonStyle

    property int margin: Themes.Units.smallSpacing

    padding {
        top: margin
        left: margin
        right: margin
        bottom: margin
    }

    SystemPalette {
        id: syspal
        colorGroup: control.enabled ? SystemPalette.Active : SystemPalette.Disabled
    }

    label: Text {
        renderType: Text.NativeRendering
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        text: control.text
        color: syspal.buttonText
    }
    background: Item {
        implicitWidth: Themes.Units.dp(96)
        implicitHeight: Themes.Units.dp(32)

        Rectangle {
            anchors.fill: parent
            color: "transparent"
            border {
                width: Themes.Units.dp(4)
                color: control.activeFocus ? ColorUtils.adjustAlpha(syspal.highlight, 0.5) : "transparent"
            }
            radius: Themes.Units.dp(4)
            antialiasing: true

            Rectangle {
                id: mainItem
                anchors {
                    fill: parent
                    margins: Themes.Units.dp(2)
                }
                border.color: syspal.shadow
                gradient: Gradient {
                    GradientStop {
                        position: 0.0
                        color: control.pressed ? syspal.mid : Qt.lighter(syspal.button, 1.05)
                    }
                    GradientStop {
                        position: 0.4
                        color: control.pressed ? syspal.shadow : syspal.button
                    }
                    GradientStop {
                        position: 1.0
                        color: control.pressed ? syspal.dark : Qt.darker(syspal.button, 1.08)
                    }
                }
                radius: Themes.Units.dp(4)
                antialiasing: true
            }
        }
    }
}
