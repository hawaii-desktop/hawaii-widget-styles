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
#include <QWidget>
#include <QStyleOption>
#include <QPainter>

#include <QPushButton>
#include <QComboBox>
#include <QSpinBox>
#include <QCheckBox>
#include <QGroupBox>
#include <QRadioButton>
#include <QSplitterHandle>
#include <QSlider>
#include <QHeaderView>
#include <QTabBar>
#include <QTextEdit>
#include <QLineEdit>
#include <QDial>

#include <Fluid/FrameSvg>

#include "fluidstyle.h"
#include "lineedit.h"
#include "pushbutton.h"
#include "scrollbars.h"

using namespace Fluid;

FluidStyle::FluidStyle()
    : QFusionStyle()
{
    m_lineEdit = new LineEdit(this);
    m_pushButton = new PushButton(this);
    m_scrollBars = new ScrollBars(this);
}

FluidStyle::~FluidStyle()
{
    delete m_scrollBars;
    delete m_pushButton;
    delete m_lineEdit;
}

void FluidStyle::polish(QWidget *widget)
{
    QFusionStyle::polish(widget);

    if (qobject_cast<QPushButton *>(widget) ||
            qobject_cast<QAbstractButton *>(widget) ||
            qobject_cast<QComboBox *>(widget) ||
            qobject_cast<QAbstractSpinBox *>(widget) ||
            qobject_cast<QCheckBox *>(widget) ||
            qobject_cast<QGroupBox *>(widget) ||
            qobject_cast<QRadioButton *>(widget) ||
            qobject_cast<QSplitterHandle *>(widget) ||
            qobject_cast<QSlider *>(widget) ||
            qobject_cast<QHeaderView *>(widget) ||
            qobject_cast<QTabBar *>(widget) ||
            qobject_cast<QAbstractScrollArea *>(widget) ||
            qobject_cast<QTextEdit *>(widget) ||
            qobject_cast<QLineEdit *>(widget) ||
            qobject_cast<QDial *>(widget) ||
            widget->inherits("QWorkspaceTitleBar") ||
            widget->inherits("QDockSeparator") ||
            widget->inherits("QDockWidgetSeparator"))
        widget->setAttribute(Qt::WA_Hover, true);
}

void FluidStyle::unpolish(QWidget *widget)
{
    if (qobject_cast<QPushButton *>(widget) ||
            qobject_cast<QAbstractButton *>(widget) ||
            qobject_cast<QComboBox *>(widget) ||
            qobject_cast<QAbstractSpinBox *>(widget) ||
            qobject_cast<QCheckBox *>(widget) ||
            qobject_cast<QGroupBox *>(widget) ||
            qobject_cast<QRadioButton *>(widget) ||
            qobject_cast<QSplitterHandle *>(widget) ||
            qobject_cast<QSlider *>(widget) ||
            qobject_cast<QHeaderView *>(widget) ||
            qobject_cast<QTabBar *>(widget) ||
            qobject_cast<QAbstractScrollArea *>(widget) ||
            qobject_cast<QTextEdit *>(widget) ||
            qobject_cast<QLineEdit *>(widget) ||
            qobject_cast<QDial *>(widget) ||
            widget->inherits("QWorkspaceTitleBar") ||
            widget->inherits("QDockSeparator") ||
            widget->inherits("QDockWidgetSeparator"))
        widget->setAttribute(Qt::WA_Hover, false);

    QFusionStyle::unpolish(widget);
}

void FluidStyle::drawPrimitive(PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
{
    painter->save();

    switch (element) {
        case PE_PanelItemViewItem: {
            FrameSvg frame;

            frame.setImagePath("widgets/viewitem");
            frame.setEnabledBorders(FrameSvg::AllBorders);
            frame.setElementPrefix("hover");
            frame.resizeFrame(option->rect.size());
            frame.paintFrame(painter, option->rect);
        }
        break;
        case PE_FrameMenu: {
            FrameSvg frame;

            frame.setImagePath("widgets/background");
            frame.setEnabledBorders(FrameSvg::AllBorders);
            frame.resizeFrame(option->rect.size());
            frame.paintFrame(painter, option->rect);
        }
        break;
        case PE_FrameTabBarBase: {
            FrameSvg frame;

            frame.setImagePath("widgets/button");
            frame.setEnabledBorders(FrameSvg::AllBorders);
            frame.setElementPrefix("normal");
            frame.resizeFrame(option->rect.size());
            frame.paintFrame(painter, option->rect);

        }
        break;
        //case PE_FrameStatusBar
        case PE_PanelButtonCommand:
            m_pushButton->paint(option, painter, widget);
            break;
        case PE_FrameDefaultButton:
            m_pushButton->drawDefaultFrame(option, painter, widget);
            break;
            //case PE_PanelButtonBevel
        case PE_PanelButtonTool: {
            FrameSvg item;
            item.setImagePath("widgets/button");
            if (option->state & State_HasFocus)
                item.setElementPrefix("focus");
            else if (option->state & (State_Sunken | State_On))
                item.setElementPrefix("pressed");
            else
                item.setElementPrefix("normal");
            item.resizeFrame(option->rect.size());
            item.paintFrame(painter, option->rect);
        }
        break;
        case PE_FrameLineEdit:
            m_lineEdit->paint(option, painter, widget);
            break;
            //case PE_PanelLineEdit
        case PE_IndicatorButtonDropDown:
            FluidStyle::drawPrimitive(PE_IndicatorArrowDown, option, painter, widget);
            break;
            //case PE_FrameFocusRect
        case PE_IndicatorArrowUp:
        case PE_IndicatorArrowDown:
        case PE_IndicatorArrowRight:
        case PE_IndicatorArrowLeft:
            m_scrollBars->paintArrow(element, option, painter, widget);
            break;
            //case PE_IndicatorSpinUp
            //case PE_IndicatorSpinDown
            //case PE_IndicatorSpinPlus
            //case PE_IndicatorSpinMinus
            //case PE_IndicatorItemViewItemCheck
        case PE_IndicatorCheckBox: {
            Svg *svg = new Svg();

            QSizeF size(proxy()->pixelMetric(PM_IndicatorWidth, option, widget),
                        proxy()->pixelMetric(PM_IndicatorHeight, option, widget));

            svg->setImagePath("widgets/button");
            svg->resize(size * 6);
            svg->paint(painter, QPointF(0, 0), "normal");

            if (option->state & State_On) {
                svg->setImagePath("widgets/checkmarks");
                svg->resize(size);
                svg->paint(painter, QPointF(size.width() / 3, size.height() / 3), "checkbox");
            }

            delete svg;
        }
        break;
        case PE_IndicatorRadioButton: {
            Svg *svg = new Svg();

            QSizeF size(proxy()->pixelMetric(PM_ExclusiveIndicatorWidth, option, widget),
                        proxy()->pixelMetric(PM_ExclusiveIndicatorHeight, option, widget));

            svg->setImagePath("widgets/actionbutton");
            svg->resize(size * 6);
            svg->paint(painter, QPointF(0, 0), "normal");

            if (option->state & State_On) {
                svg->setImagePath("widgets/checkmarks");
                svg->resize(size);
                svg->paint(painter, QPointF(size.width() / 3, size.height() / 3), "radiobutton");
            }

            delete svg;
        }
        break;
        //case PE_IndicatorDockWidgetResizeHandle
        //case PE_Frame
        //case PE_FrameMenu
        //case PE_PanelMenuBar
        //case PE_PanelScrollAreaCorner
        default:
            QFusionStyle::drawPrimitive(element, option, painter, widget);
    }

    painter->restore();
}

void FluidStyle::drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
{
    QRect rect(option->rect);

    painter->save();

    switch (element) {
        case CE_ProgressBarGroove: {
            rect.adjusted(1, 1, -1, -1);

            FrameSvg frame;
            frame.setImagePath("widgets/bar_meter_horizontal");
            frame.setEnabledBorders(FrameSvg::AllBorders);
            frame.setElementPrefix("bar-inactive");
            frame.resize(rect.size());
            frame.paintFrame(painter, option->rect);
        }
        break;
        default:
            QFusionStyle::drawControl(element, option, painter, widget);
    }

    painter->restore();
}

QSize FluidStyle::sizeFromContents(ContentsType type, const QStyleOption *option, const QSize &size, const QWidget *widget) const
{
    QSize newSize(QFusionStyle::sizeFromContents(type, option, size, widget));

    switch (type) {
        case CT_PushButton: {
            newSize = size;
            newSize.setWidth(newSize.width() + 12);

            if (const QStyleOptionButton *btn = qstyleoption_cast<const QStyleOptionButton *>(option)) {
                int margin = (pixelMetric(PM_ButtonMargin, btn, widget) +
                              (pixelMetric(PM_DefaultFrameWidth, btn, widget) * 2)) - 1;

                newSize += QSize(margin, margin);

                if (btn->features & QStyleOptionButton::HasMenu)
                    newSize += QSize(4, 0);

                newSize.rheight() += ((1 - newSize.rheight()) & 1);
            }
            break;
        }
        default:
            break;
    }

    return newSize;
}

#if 0
QPalette FluidStyle::standardPalette() const
{
    QPalette palette;

    palette.setBrush(QPalette::Active, QPalette::Window, QColor(QRgb(0xfff7f7f7)));
    palette.setBrush(QPalette::Active, QPalette::WindowText, QColor(QRgb(0xff2e3436)));
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
    palette.setBrush(QPalette::Active, QPalette::Highlight, QColor(QRgb(0xff117ad8)));
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

    for (int i = 0; i < QPalette::NColorRoles; i++) {
        palette.setColor(QPalette::Disabled, QPalette::ColorRole(i),
                         palette.color(QPalette::Active, QPalette::ColorRole(i)));

        palette.setColor(QPalette::Disabled, QPalette::ButtonText, Qt::darkGray);
        palette.setColor(QPalette::Disabled, QPalette::WindowText, Qt::darkGray);
        palette.setColor(QPalette::Disabled, QPalette::Text, Qt::darkGray);
        palette.setColor(QPalette::Disabled, QPalette::HighlightedText, Qt::darkGray);
    }

    return palette;
}
#endif

#include "moc_fluidstyle.cpp"
