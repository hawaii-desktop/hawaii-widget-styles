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

#include <QDebug>
#include <QStyle>
#include <QStyleOption>
#include <QPainter>

#include "lineedit.h"

using namespace Fluid;

LineEdit::LineEdit(QObject *parent)
    : QObject(parent)
{
    m_svgImage = new FrameSvg(this);
    m_svgImage->setImagePath("widgets/lineedit");
    m_svgImage->setCacheAllRenderedFrames(true);
}

LineEdit::~LineEdit()
{
    delete m_svgImage;
}

void LineEdit::paint(const QStyleOption *option, QPainter *painter, const QWidget *widget)
{
    bool hasFocus = option->state & QStyle::State_HasFocus;
    bool isOver = option->state & QStyle::State_MouseOver;

    if (hasFocus)
        m_svgImage->setElementPrefix("focus");
    else if (isOver)
        m_svgImage->setElementPrefix("hover");
    else
        m_svgImage->setElementPrefix("base");
    m_svgImage->resizeFrame(option->rect.size());
    m_svgImage->paintFrame(painter, option->rect);
}

#include "moc_lineedit.cpp"
