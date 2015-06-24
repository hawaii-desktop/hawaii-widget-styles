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
import QtQuick.Controls 1.1
import QtQuick.Controls.Private 1.0 as QtQuickControlsPrivate
import Hawaii.Components 1.0 as Components
import Hawaii.Themes 1.0 as Themes
import "Constants.js" as Constants

QtQuickControlsPrivate.Style {
    readonly property ToolButton control: __control

    SystemPalette {
        id: syspal
        colorGroup: control.enabled ? SystemPalette.Active : SystemPalette.Disabled
    }

    property Component panel: Rectangle {
        readonly property bool hasIcon: icon.status === Image.Ready || icon.status === Image.Loading
        readonly property bool hasText: control.text != ""
        readonly property bool pressed: control.pressed || (control.checkable && control.checked)
        readonly property real minSize: Themes.Units.iconSizes.smallMedium + (Themes.Units.smallSpacing * 2)

        implicitWidth: Math.max(row.width + row.spacing * 2, minSize) + (arrow.visible ? Themes.Units.dp(10) : 0)
        implicitHeight: Math.max(Math.max(hasIcon ? icon.height : label.implicitHeight), minSize)
        border.color: syspal.mid
        radius: Constants.roundedRectRadius
        gradient: Gradient {
            GradientStop { position: 0.0; color: pressed ? syspal.mid : Qt.lighter(syspal.button, 1.05); }
            GradientStop { position: 0.4; color: pressed ? syspal.midlight : syspal.button; }
            GradientStop { position: 1.0; color: pressed ? syspal.light : Qt.darker(syspal.button, 1.08); }
        }
        antialiasing: true
        opacity: control.enabled ? 1.0 : 0.5

        Item {
            anchors {
                left: parent.left
                top: parent.top
                right: arrow.left
                bottom: parent.bottom
            }
            clip: true

            Row {
                id: row
                anchors.centerIn: parent
                spacing: Themes.Units.smallSpacing

                Components.Icon {
                    id: icon
                    iconName: control.__action.iconName ? control.__action.iconName : ""
                    iconSource: {
                        if (control.__action && !control.__action.iconName)
                            return control.__action.iconSource;
                        if (control.iconSource)
                            return control.iconSource;
                        return "";
                    }
                    width: Themes.Units.iconSizes.smallMedium
                    height: width
                    color: syspal.text
                }

                Text {
                    id: label
                    anchors.verticalCenter: icon.verticalCenter
                    text: QtQuickControlsPrivate.StyleHelpers.stylizeMnemonics(control.text)
                    renderType: Text.NativeRendering
                    visible: hasText
                }
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
