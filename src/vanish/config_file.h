/****************************************************************************
 * This file is part of Vanish.
 *
 * Copyright (c) 2011-2012 Pier Luigi Fiorini
 *
 * Author(s):
 *    Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * $BEGIN_LICENSE:LGPL$
 *
 * Vanish is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * Vanish is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Vanish.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $END_LICENSE$
 ***************************************************************************/

#ifndef QTC_CONFIG_FILE_H
#define QTC_CONFIG_FILE_H

#include "common.h"

#define MAX_CONFIG_FILENAME_LEN   1024
#define MAX_CONFIG_INPUT_LINE_LEN 256

#define QTC_MENU_FILE_PREFIX   "menubar-"
#define QTC_STATUS_FILE_PREFIX "statusbar-"

#define qtcMenuBarHidden(A)         qtcBarHidden((A), QTC_MENU_FILE_PREFIX)
#define qtcSetMenuBarHidden(A, H)   qtcSetBarHidden((A), (H), QTC_MENU_FILE_PREFIX)
#define qtcStatusBarHidden(A)       qtcBarHidden((A), QTC_STATUS_FILE_PREFIX)
#define qtcSetStatusBarHidden(A, H) qtcSetBarHidden((A), (H), QTC_STATUS_FILE_PREFIX)

extern bool qtcBarHidden(const QString &app, const char *prefix);
extern void qtcSetBarHidden(const QString &app, bool hidden, const char *prefix);

extern void qtcLoadBgndImage(QtCImage *img);

extern const char *qtcGetHome();
extern const char *qtcConfDir();
extern void qtcSetRgb(color *col, const char *str);
extern void qtcDefaultSettings(Options *opts);
extern void qtcCheckConfig(Options *opts);
extern bool qtcReadConfig(const QString &file, Options *opts, Options *defOpts = 0L, bool checkImages = true);
extern WindowBorders qtcGetWindowBorderSize(bool force = false);

#ifdef CONFIG_WRITE
class KConfig;
extern bool qtcWriteConfig(KConfig *cfg, const Options &opts, const Options &def, bool exportingStyle = false);
#endif

#endif
