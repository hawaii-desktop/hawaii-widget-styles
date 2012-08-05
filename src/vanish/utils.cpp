/*
  Vanish (C) Craig Drummond, 2007 - 2010 craig.p.drummond@gmail.com

  ----

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public
  License version 2 as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; see the file COPYING.  If not, write to
  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
  Boston, MA 02110-1301, USA.
*/

#include "utils.h"
#include "config.h"
#include <stdio.h>

#if defined QTC_QT_ONLY
#undef KDE_IS_VERSION
#define KDE_IS_VERSION(A, B, C) 0
#else
#include <kdeversion.h>
#include <KDE/KWindowSystem>
#endif

namespace Vanish
{
    namespace Utils
    {
        bool compositingActive()
        {
#if defined QTC_QT_ONLY || !KDE_IS_VERSION(4, 4, 0)
            return false;
#else // QTC_QT_ONLY
            return KWindowSystem::compositingActive();
#endif // QTC_QT_ONLY
        }

        bool hasAlphaChannel(const QWidget *widget)
        {
            return compositingActive();
        }
    }
}
