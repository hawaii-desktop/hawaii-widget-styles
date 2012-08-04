/****************************************************************************
 * This file is part of Vanish Style.
 *
 * Copyright (c) 2011-2012 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * Author(s):
 *	Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * Vanish Style is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License version 2
 * as published by the Free Software Foundation.
 *
 * Vanish Style is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Vanish Style.  If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#include <QtWidgets/QStylePlugin>

#include "vanishstyle.h"

class VanishStylePlugin : public QStylePlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QStyleFactoryInterface" FILE "vanish.json")
public:
    VanishStylePlugin() {}

    virtual QStyle *create(const QString &key);
    virtual QStringList keys() const;
};

QStyle *VanishStylePlugin::create(const QString &key)
{
    if (key.toLower() == "vanish")
        return new VanishStyle();
    return 0;
}

QStringList VanishStylePlugin::keys() const
{
    return QStringList() << "Vanish";
}

#include "main.moc"
