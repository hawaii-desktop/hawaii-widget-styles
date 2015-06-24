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
import QtQuick.Controls.Styles 1.0 as QtQuickControlsStyles
import QtGraphicalEffects 1.0
import Hawaii.Themes 1.0 as Themes
import "Constants.js" as Constants
import "ColorUtils.js" as ColorUtils

QtQuickControlsStyles.SliderStyle {
    SystemPalette {
        id: syspal
        colorGroup: control.enabled ? SystemPalette.Active : SystemPalette.Disabled
    }

    handle: Item {
        implicitWidth: Constants.indicatorSize
        implicitHeight: implicitWidth

        Rectangle {
            id: knobItem
            anchors.fill: parent
            border.color: ColorUtils.blendColors(syspal.window, syspal.dark)
            radius: height
            antialiasing: true
            visible: false
        }

        RadialGradient {
            anchors.fill: knobItem
            source: knobItem
            gradient: Gradient {
                GradientStop { position: 0.0; color: syspal.highlight }
                GradientStop { position: 1.0; color: Qt.darker(syspal.highlight, 1.5) }
            }
            horizontalOffset: -2
            verticalOffset: 2
        }
    }
    groove: Item {
        property color baseColor: "#f1f1f1"

        implicitWidth: Themes.Units.dp(300)
        implicitHeight: Themes.Units.dp(10)

        Rectangle {
            anchors.verticalCenter: parent.verticalCenter
            width: parent.width
            height: Themes.Units.dp(8)
            border.color: ColorUtils.blendColors(syspal.window, syspal.dark)
            radius: height / 2
            gradient: Gradient {
                GradientStop { position: 0.0; color: syspal.mid }
                GradientStop { position: 0.5; color: syspal.shadow }
                GradientStop { position: 1.0; color: syspal.dark }
            }
            antialiasing: true
            opacity: 0.8

            Rectangle {
                width: parent.width * control.value / control.maximumValue
                height: parent.height
                border.color: ColorUtils.blendColors(Qt.darker(syspal.highlight, 1.3), syspal.dark)
                radius: height / 2
                gradient: Gradient {
                    GradientStop { position: 0.0; color: Qt.darker(syspal.highlight, 1.5) }
                    GradientStop { position: 0.5; color: Qt.darker(syspal.highlight, 1.2) }
                    GradientStop { position: 1.0; color: syspal.highlight }
                }
                antialiasing: true
            }
        }
    }
}
