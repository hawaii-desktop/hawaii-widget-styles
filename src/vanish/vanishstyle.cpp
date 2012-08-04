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

#include <QFile>
#include <QMenuBar>
#include <QScrollBar>
#include <QScroller>
#include <QDebug>

#include "vanishstyle.h"

/*!
    Constructs a VanishStyle object.
*/
VanishStyle::VanishStyle()
    : QPlastiqueStyle()
{
    setObjectName(QLatin1String("Vanish"));
}

/*!
    Destructs the VanishStyle object.
*/
VanishStyle::~VanishStyle()
{
}

/*!
  \reimp
*/
void VanishStyle::polish(QApplication *a)
{
    QPlastiqueStyle::polish(a);

    QFile cssFile(":/stylesheet/vanish.css");
    if (cssFile.open(QIODevice::ReadOnly)) {
        QString stylesheet = cssFile.readAll();
        stylesheet.replace("@bg_color", "#dadada");
        cssFile.close();
        qDebug() << stylesheet;

        a->setStyleSheet(stylesheet);
    }
}

/*!
  \reimp
*/
void VanishStyle::polish(QWidget *w)
{
    QPlastiqueStyle::polish(w);

    // Hover flag
    if (qobject_cast<QScrollBar *>(w))
        w->setAttribute(Qt::WA_Hover, true);

    // Enable kinetic scrolling with touch gestures
    if (!QScroller::hasScroller(w))
        QScroller::grabGesture(w, QScroller::TouchGesture);

    // No background role for menu bars
    if (qobject_cast<QMenuBar *>(w))
        w->setBackgroundRole(QPalette::NoRole);
}

/*!
  \reimp
*/
void VanishStyle::unpolish(QWidget *w)
{
    // Hover flag
    if (qobject_cast<QScrollBar *>(w))
        w->setAttribute(Qt::WA_Hover, false);

    QPlastiqueStyle::unpolish(w);
}

/*!
  \reimp
*/
QPalette VanishStyle::standardPalette() const
{
    QPalette palette;

    palette.setBrush(QPalette::Active, QPalette::Window, QColor(QRgb(0xffdadada)));
    palette.setBrush(QPalette::Active, QPalette::WindowText, QColor(QRgb(0xff363636)));
    palette.setBrush(QPalette::Active, QPalette::Button, QColor(QRgb(0xffededed)));
    palette.setBrush(QPalette::Active, QPalette::Light, QColor(QRgb(0xffffffff)));
    palette.setBrush(QPalette::Active, QPalette::Midlight, QColor(QRgb(0xffdadada)));
    palette.setBrush(QPalette::Active, QPalette::Dark, QColor(QRgb(0xfa0a0a0)));
    palette.setBrush(QPalette::Active, QPalette::Mid, QColor(QRgb(0xfff7f7f7)));
    palette.setBrush(QPalette::Active, QPalette::Text, QColor(QRgb(0xff2e3436)));
    palette.setBrush(QPalette::Active, QPalette::BrightText, QColor(QRgb(0xffffffff)));
    palette.setBrush(QPalette::Active, QPalette::ButtonText, QColor(QRgb(0xff000000)));
    palette.setBrush(QPalette::Active, QPalette::Base, QColor(QRgb(0xfffffafa)));
    palette.setBrush(QPalette::Active, QPalette::AlternateBase, palette.color(QPalette::Active, QPalette::Base).darker(110));
    palette.setBrush(QPalette::Active, QPalette::Shadow, QColor(QRgb(0xff828282)));
    palette.setBrush(QPalette::Active, QPalette::Highlight, QColor(QRgb(0x1a487392)));
    palette.setBrush(QPalette::Active, QPalette::HighlightedText, QColor(QRgb(0xffffffff)));
    palette.setBrush(QPalette::Active, QPalette::Link, QColor(QRgb(0xff4a90d9)));
    palette.setBrush(QPalette::Active, QPalette::LinkVisited, QColor(QRgb(0xff52188b)));

    palette.setBrush(QPalette::Inactive, QPalette::Window, palette.window());
    palette.setBrush(QPalette::Inactive, QPalette::WindowText, palette.windowText());
    palette.setBrush(QPalette::Inactive, QPalette::Button, palette.button());
    palette.setBrush(QPalette::Inactive, QPalette::Light, palette.light());
    palette.setBrush(QPalette::Inactive, QPalette::Midlight, palette.midlight());
    palette.setBrush(QPalette::Inactive, QPalette::Dark, palette.dark());
    palette.setBrush(QPalette::Inactive, QPalette::Mid, palette.mid());
    palette.setBrush(QPalette::Inactive, QPalette::Text, palette.text());
    palette.setBrush(QPalette::Inactive, QPalette::BrightText, palette.brightText());
    palette.setBrush(QPalette::Inactive, QPalette::ButtonText, palette.buttonText());
    palette.setBrush(QPalette::Inactive, QPalette::Base, palette.base());
    palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, palette.alternateBase());
    palette.setBrush(QPalette::Inactive, QPalette::Shadow, palette.shadow());
    palette.setBrush(QPalette::Inactive, QPalette::Highlight, palette.highlight());
    palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, palette.highlightedText());
    palette.setBrush(QPalette::Inactive, QPalette::Link, palette.link());
    palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, palette.linkVisited());

    palette.setBrush(QPalette::Disabled, QPalette::Window, QColor(QRgb(0xfff1f0ef)));
    palette.setBrush(QPalette::Disabled, QPalette::WindowText, QColor(QRgb(0xffa8a8a8)));
    palette.setBrush(QPalette::Disabled, QPalette::Button, QColor(QRgb(0xffdddfe4)));
    palette.setBrush(QPalette::Disabled, QPalette::Light, QColor(QRgb(0xffffffff)));
    palette.setBrush(QPalette::Disabled, QPalette::Midlight, QColor(QRgb(0xffffffff)));
    palette.setBrush(QPalette::Disabled, QPalette::Dark, QColor(QRgb(0xff555555)));
    palette.setBrush(QPalette::Disabled, QPalette::Mid, QColor(QRgb(0xffc7c7c7)));
    palette.setBrush(QPalette::Disabled, QPalette::Text, QColor(QRgb(0xffc7c7c7)));
    palette.setBrush(QPalette::Disabled, QPalette::BrightText, QColor(QRgb(0xffffffff)));
    palette.setBrush(QPalette::Disabled, QPalette::ButtonText, QColor(QRgb(0xff808080)));
    palette.setBrush(QPalette::Disabled, QPalette::Base, QColor(QRgb(0xffefefef)));
    palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, palette.color(QPalette::Disabled, QPalette::Base).darker(110));
    palette.setBrush(QPalette::Disabled, QPalette::Shadow, QColor(QRgb(0xff000000)));
    palette.setBrush(QPalette::Disabled, QPalette::Highlight, QColor(QRgb(0xff567594)));
    palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, QColor(QRgb(0xffffffff)));
    palette.setBrush(QPalette::Disabled, QPalette::Link, QColor(QRgb(0xff0000ee)));
    palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, QColor(QRgb(0xff52188b)));

    return palette;
}

#include "vanishstyle.moc"
