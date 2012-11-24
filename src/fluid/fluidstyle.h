/****************************************************************************
 * This file is part of Widget Styles.
 *
 * Copyright (c) 2012 Pier Luigi Fiorini
 *
 * Author(s):
 *    Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
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

#ifndef FLUIDSTYLE_H
#define FLUIDSTYLE_H

#include <private/qfusionstyle_p.h>

class LineEdit;
class PushButton;
class ScrollBars;

class FluidStyle : public QFusionStyle
{
    Q_OBJECT
public:
    FluidStyle();
    ~FluidStyle();

    void polish(QWidget *widget);
    void unpolish(QWidget *widget);

    void drawPrimitive(PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget = 0) const;
    void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget = 0) const;

    QSize sizeFromContents(ContentsType type, const QStyleOption *option, const QSize &size, const QWidget *widget = 0) const;

#if 0
    QPalette standardPalette() const;
#endif

private:
    LineEdit *m_lineEdit;
    PushButton *m_pushButton;
    ScrollBars *m_scrollBars;
};

#endif // FLUIDSTYLE_H
