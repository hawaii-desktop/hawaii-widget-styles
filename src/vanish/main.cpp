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

#include <QDir>
#include <QStylePlugin>
#include <QDebug>

#include <VStandardDirectories>

#include "vanishstyle.h"

using namespace VStandardDirectories;

namespace Vanish
{
    class StylePlugin : public QStylePlugin
    {
        Q_OBJECT
        Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QStyleFactoryInterface" FILE "vanish.json")
    public:
        StylePlugin();

        virtual QStyle *create(const QString &key);
        virtual QStringList keys() const;

    private:
        QMap<QString, QString> m_themes;

        void getThemes(const QString &dir);
    };

    StylePlugin::StylePlugin()
    {
        getThemes(QString("%1/vanish").arg(findDirectory(UserThemesDirectory)));
        getThemes(QString("%1/vanish").arg(findDirectory(CommonThemesDirectory)));
        getThemes(QString("%1/vanish").arg(findDirectory(SystemThemesDirectory)));
    }

    QStyle *StylePlugin::create(const QString &k)
    {
        QString key = k.toLower();

        if (key == "vanish")
            return new Style();
        else if (m_themes.contains(key))
            return new Style(m_themes[key]);
        return 0;
    }

    QStringList StylePlugin::keys() const
    {
        QStringList styles;
        styles << "Vanish";

        return styles + m_themes.keys();
    }

    void StylePlugin::getThemes(const QString &dir)
    {
        QDir d(dir);

        if (d.exists()) {
            QStringList filters;

            filters << QString("*."THEME_SUFFIX);
            d.setNameFilters(filters);

            QStringList entries(d.entryList());
            QStringList::ConstIterator it(entries.begin()),
                        end(entries.end());

            for (; it != end; ++it) {
                QString fileName((*it));
                QString style = fileName.left(fileName.lastIndexOf("."THEME_SUFFIX)).toLower();

                qDebug() << fileName;
                if (!m_themes.contains(style))
                    m_themes[style] = fileName;
            }
        }
    }
}

#include "main.moc"
