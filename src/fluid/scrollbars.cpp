/****************************************************************************
 * This file is part of Widget Styles.
 *
 * Copyright (C) 2012-2013 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
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

#include <QStyle>
#include <QStyleOption>
#include <QPainter>

#include "scrollbars.h"

using namespace Fluid;

ScrollBars::ScrollBars(QObject *parent)
    : QObject(parent)
{
    m_svgImage = new Svg(this);
    m_svgImage->setUsingRenderingCache(true);
    m_svgImage->setImagePath("widgets/scrollbar");
}

ScrollBars::~ScrollBars()
{
    delete m_svgImage;
}

void ScrollBars::paintArrow(QStyle::PrimitiveElement element, const QStyleOption *option,
                            QPainter *painter, const QWidget *widget)
{
    m_svgImage->resize(option->rect.size());

    QString elementId;
    switch (element) {
        case QStyle::PE_IndicatorArrowUp:
            elementId = "arrow-up";
            break;
        case QStyle::PE_IndicatorArrowDown:
            elementId = "arrow-down";
            break;
        case QStyle::PE_IndicatorArrowRight:
            elementId = "arrow-right";
            break;
        case QStyle::PE_IndicatorArrowLeft:
            elementId = "arrow-left";
            break;
        default:
            break;
    }

    m_svgImage->paint(painter, QPointF(0, 0), elementId);
}

#include "moc_scrollbars.cpp"
