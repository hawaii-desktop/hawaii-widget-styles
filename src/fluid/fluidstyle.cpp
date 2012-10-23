/****************************************************************************
 * This file is part of Widget Styles.
 *
 * Copyright (c) 2012 Pier Luigi Fiorini
 *
 * Author(s):
 *    Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * $BEGIN_LICENSE:LGPL-ONLY$
 *
 * This file may be used under the terms of the GNU Lesser General
 * Public License as published by the Free Software Foundation and
 * appearing in the file LICENSE.LGPL included in the packaging of
 * this file, either version 2.1 of the License, or (at your option) any
 * later version.  Please review the following information to ensure the
 * GNU Lesser General Public License version 2.1 requirements
 * will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
 *
 * If you have questions regarding the use of this file, please contact
 * us via http://www.maui-project.org/.
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
#include "pushbutton.h"

using namespace Fluid;

static QPolygon rotate(const QPolygon &p, double angle)
{
    QMatrix matrix;
    matrix.rotate(angle);
    return matrix.map(p);
}


FluidStyle::FluidStyle()
    : QFusionStyle()
{
    m_pushButton = new PushButton(this);
}

FluidStyle::~FluidStyle()
{
    delete m_pushButton;
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
        case PE_FrameLineEdit: {
            FrameSvg *item = new FrameSvg();

            item->setImagePath("widgets/lineedit");
            item->resizeFrame(option->rect.size());
            if (option->state & State_HasFocus)
                item->setElementPrefix("focus");
            else if (option->state & State_MouseOver)
                item->setElementPrefix("hover");
            else
                item->setElementPrefix("base");
            item->paintFrame(painter, option->rect);

            delete item;
        }
        break;
        //case PE_PanelLineEdit
        case PE_IndicatorButtonDropDown:
            FluidStyle::drawPrimitive(PE_IndicatorArrowDown, option, painter, widget);
            break;
            //case PE_FrameFocusRect
        case PE_IndicatorArrowUp:
        case PE_IndicatorArrowDown:
        case PE_IndicatorArrowRight:
        case PE_IndicatorArrowLeft: {
#if 0
            Svg svg;
            svg.setUsingRenderingCache(true);
            svg.setImagePath("widgets/scrollbar");
            svg.resize(option->rect.size());

            QString elementId;
            switch (element) {
                case PE_IndicatorArrowUp:
                    elementId = "arrow-up";
                    break;
                case PE_IndicatorArrowDown:
                    elementId = "arrow-down";
                    break;
                case PE_IndicatorArrowRight:
                    elementId = "arrow-right";
                    break;
                case PE_IndicatorArrowLeft:
                    elementId = "arrow-left";
                    break;
                default:
                    break;
            }
            svg.paint(painter, QPointF(0, 0), elementId);
#else
            QPolygon a;
            QRect r(option->rect);
            int          m = 0;
            a.setPoints(3,  3 + m, 1 + m,  0, -2,  -(3 + m), 1 + m,    -(3 + m), 2 + m,  -(2 + m), 2 + m, 0, 0,  2 + m, 2 + m, 3 + m, 2 + m);
            switch (element) {
                case PE_IndicatorArrowUp:
                    if (m)
                        r.adjust(0, -m, 0, -m);
                    break;
                case PE_IndicatorArrowDown:
                    if (m)
                        r.adjust(0, m, 0, m);
                    a = rotate(a, 180);
                    break;
                case PE_IndicatorArrowRight:
                    a = rotate(a, 90);
                    break;
                case PE_IndicatorArrowLeft:
                    a = rotate(a, 270);
                    break;
                default:
                    return;
            }

            a.translate((r.x() + (r.width() >> 1)), (r.y() + (r.height() >> 1)));

            painter->drawPolygon(a);
#endif
        }
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
#if 0
        case CE_ProgressBarContents:
            if (const QStyleOptionProgressBar *bar = qstyleoption_cast<const QStyleOptionProgressBar *>(option)) {
                bool vertical(false),
                     inverted(false),
                     indeterminate(0 == bar->minimum && 0 == bar->maximum);

                // Get extra style options if version 2
                if (const QStyleOptionProgressBarV2 *bar2 = qstyleoption_cast<const QStyleOptionProgressBarV2 *>(option)) {
                    vertical = Qt::Vertical == bar2->orientation;
                    inverted = bar2->invertedAppearance;
                }

                if (!indeterminate && -1 == bar->progress)
                    break;

                bool reverse = (!vertical && (bar->direction == Qt::RightToLeft)) || vertical;

                if (inverted)
                    reverse = !reverse;

                ////////////
                rect.adjusted(1, 1, -1, -1);

                FrameSvg frame;
                frame.setImagePath("widgets/bar_meter_horizontal");
                frame.setElementPrefix("bar-active");
                frame.paintFrame(painter, rect);
                ////////////////////

#if 0
                if (indeterminate) {
                    //Busy indicator
                    int chunkSize(PROGRESS_CHUNK_WIDTH * 3.4),
                        measure(vertical ? r.height() : r.width());

                    if (chunkSize > (measure / 2))
                        chunkSize = measure / 2;

                    int step(itsAnimateStep % ((measure - chunkSize) * 2));
                    QStyleOption opt(*option);

                    if (step > (measure - chunkSize))
                        step = 2 * (measure - chunkSize) - step;

                    opt.state |= State_Raised | State_Horizontal;
                    drawProgress(painter, vertical ? QRect(r.x(), r.y() + step, r.width(), chunkSize) : QRect(r.x() + step, r.y(), chunkSize, r.height()),
                                 option, vertical);
                } else if (r.isValid() && bar->progress > 0) {
                    // Workaround for bug in QProgressBar
                    qint64 progress = qMax<qint64>(bar->progress, bar->minimum);

                    double pg = ((progress - qint64(bar->minimum)) /
                                 qMax(double(1.0), double(qint64(bar->maximum) - qint64(bar->minimum))));

                    if (vertical) {
                        int height(qMin(r.height(), (int)(pg * r.height())));

                        if (inverted)
                            drawProgress(painter, QRect(r.x(), r.y(), r.width(), height), option, true);
                        else
                            drawProgress(painter, QRect(r.x(), r.y() + (r.height() - height), r.width(), height), option, true);
                    } else {
                        int width(qMin(r.width(), (int)(pg * r.width())));

                        if (reverse || inverted)
                            drawProgress(painter, QRect(r.x() + (r.width() - width), r.y(), width, r.height()), option, false, true);
                        else
                            drawProgress(painter, QRect(r.x(), r.y(), width, r.height()), option);
                    }
                }
#endif
            }
            break;
#endif
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

                if (!btn->text.isEmpty() && "..." != btn->text && newSize.width() < 80)
                    newSize.setWidth(80);

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
