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
import QtQuick.Controls.Styles 1.0 as QtQuickControlsStyles
import Hawaii.Themes 1.0 as Themes

QtQuickControlsStyles.StatusBarStyle {
    padding {
        left: Themes.Units.dp(4)
        top: Themes.Units.dp(4)
        right: Themes.Units.dp(4)
        bottom: Themes.Units.dp(4)
    }

    SystemPalette {
        id: syspal
        colorGroup: SystemPalette.Active
    }

    background: Rectangle {
        implicitWidth: Themes.Units.dp(200)
        implicitHeight: Themes.Units.dp(16)
        color: syspal.window
    }
}
