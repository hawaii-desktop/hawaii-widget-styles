/****************************************************************************
 * This file is part of Vanish.
 *
 * Copyright (c) 2011-2012 Pier Luigi Fiorini
 *
 * Author(s):
 *    Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * Vanish is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License version 2.1
 * as published by the Free Software Foundation.
 *
 * Vanish is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Vanish.  If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#ifndef VANISHSTYLE_H
#define VANISHSTYLE_H

#include <QApplication>
#include <QPlastiqueStyle>
#include <QWidget>

class VanishStyle : public QPlastiqueStyle
{
    Q_OBJECT
public:
    VanishStyle();
    ~VanishStyle();

    void polish(QApplication *a);

    void polish(QWidget *w);
    void unpolish(QWidget *w);

    QPalette standardPalette() const;
};

#endif // VANISHSTYLE_H
