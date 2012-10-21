/****************************************************************************
 * This file is part of Widget Styles.
 *
 * Copyright (c) 2011-2012 Pier Luigi Fiorini
 *
 * Author(s):
 *    Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * $BEGIN_LICENSE:LGPL$
 *
 * Widget Styles is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * Widget Styles is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Widget Styles.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $END_LICENSE$
 ***************************************************************************/

#include <QStylePlugin>

#include "fluidstyle.h"

class StylePlugin : public QStylePlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QStyleFactoryInterface" FILE "fluid.json")
public:
    StylePlugin();

    virtual QStyle *create(const QString &key);
    virtual QStringList keys() const;
};

StylePlugin::StylePlugin()
{
}

QStyle *StylePlugin::create(const QString &key)
{
    if (key.toLower() == "fluid")
        return new FluidStyle();
    return 0;
}

QStringList StylePlugin::keys() const
{
    QStringList styles;
    styles << "Fluid";
    return styles;
}

#include "main.moc"
