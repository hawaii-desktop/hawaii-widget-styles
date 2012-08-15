/****************************************************************************
 * This file is part of Vanish.
 *
 * Copyright (c) 2011-2012 Pier Luigi Fiorini
 * Copyright (c) 2007-2010 Craig Drummond
 *
 * Author(s):
 *    Craig Drummond <craig.p.drummond@gmail.com>
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

#ifndef SHORTCUTHANDLER_H
#define SHORTCUTHANDLER_H

#include <QObject>
#include <QSet>
#include <QList>

class QWidget;

namespace Vanish
{
    class ShortcutHandler : public QObject
    {
        Q_OBJECT
    public:
        explicit ShortcutHandler(QObject *parent = 0);
        virtual ~ShortcutHandler();

        bool hasSeenAlt(const QWidget *widget) const;
        bool isAltDown() const {
            return itsAltDown;
        }
        bool showShortcut(const QWidget *widget) const;

    private Q_SLOTS:
        void widgetDestroyed(QObject *o);

    protected:
        void updateWidget(QWidget *w);
        bool eventFilter(QObject *watched, QEvent *event);

    private:
        bool             itsAltDown;
        QSet<QWidget *>  itsSeenAlt,
             itsUpdated;
        QList<QWidget *> itsOpenMenus;
    };
}

#endif // SHORTCUTHANDLER_H
