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

#ifndef QTC_COLOR_UTILS_H
#define QTC_COLOR_UTILS_H

extern color ColorUtils_lighten(const color *color, double ky, double kc);
extern color ColorUtils_darken(const color *color, double ky, double kc);
extern color ColorUtils_shade(const color *color, double ky, double kc);
extern color ColorUtils_tint(const color *base, const color *col, double amount);
extern color ColorUtils_mix(const color *c1, const color *c2, double bias);
extern double ColorUtils_luma(const color *color);

#endif
