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
#include <QStyle>
#include <QStyleOption>
#include <QPainter>

#include "pushbutton.h"

using namespace Fluid;

PushButton::PushButton(QObject *parent)
    : QObject(parent)
{
    m_svgImage = new FrameSvg(this);
    m_svgImage->setImagePath("widgets/button");
    m_svgImage->setCacheAllRenderedFrames(true);
    m_svgImage->setElementPrefix("normal");
}

PushButton::~PushButton()
{
    delete m_svgImage;
}

void PushButton::paint(const QStyleOption *option, QPainter *painter, const QWidget *widget)
{
    QRect rect(option->rect);
    bool isEnabled = option->state & QStyle::State_Enabled;
    bool isDown = option->state & QStyle::State_Sunken;
    bool isChecked = option->state & QStyle::State_On;
    bool isFlat = false;

    //rect.adjust(m_margins.left(), m_margins.top(), -m_margins.right(), -m_margins.bottom());
    qDebug() << m_margins;
    rect.adjust(2, 2, -2, -2);
    setBorders(rect.size());
    setFrame(rect.size());

    QPixmap bufferPixmap;

    if (isEnabled) {
        // A normal button (pressed or not)
        if (isDown || isChecked)
            m_svgImage->setElementPrefix("pressed");
        else
            m_svgImage->setElementPrefix("normal");
    } else if (!isEnabled || isFlat) {
        // A normal button disabled or a flat button
        bufferPixmap = QPixmap(rect.size());
        bufferPixmap.fill(Qt::transparent);

        QPainter bufferPainter(&bufferPixmap);
        m_svgImage->paintFrame(&bufferPainter);
        bufferPainter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
        bufferPainter.fillRect(bufferPixmap.rect(), QColor(0, 0, 0, 128));

        painter->drawPixmap(0, 0, bufferPixmap);
    }

    if (!isDown && !isChecked && isEnabled && m_svgImage->hasElementPrefix("active")) {
        //....
        m_svgImage->setElementPrefix("active");
        m_svgImage->paintFrame(painter, m_activeRect.topLeft());
    } else if (isEnabled) {
        m_svgImage->paintFrame(painter, QPointF(m_margins.left() + 1, m_margins.top() + 1));
    }
}

void PushButton::drawDefaultFrame(const QStyleOption *option, QPainter *painter, const QWidget *widget)
{
    QRect rect(option->rect);

    setFrame(rect.size());

    m_svgImage->setElementPrefix("focus");
    m_svgImage->paintFrame(painter);
}

void PushButton::setFrame(QSize size)
{
    m_svgImage->setElementPrefix("pressed");
    m_svgImage->resizeFrame(size);

    m_svgImage->setElementPrefix("focus");
    m_svgImage->resizeFrame(size);

    setRect(size);

    m_svgImage->setElementPrefix("normal");
    m_svgImage->resizeFrame(size);

    m_svgImage->setElementPrefix("active");
    m_svgImage->resizeFrame(m_activeRect.size());
}

void PushButton::setRect(QSize size)
{
    m_svgImage->setElementPrefix("normal");

    qreal left, top, right, bottom;
    m_svgImage->getMargins(left, top, right, bottom);

    m_svgImage->setElementPrefix("active");
    qreal activeLeft, activeTop, activeRight, activeBottom;
    m_svgImage->getMargins(activeLeft, activeTop, activeRight, activeBottom);

    m_activeRect = QRectF(QPointF(0, 0), size);
    m_activeRect.adjust(left - activeLeft, top - activeTop,
                        -(right - activeRight), -(bottom - activeBottom));

    m_svgImage->setElementPrefix("normal");
}

void PushButton::setBorders(QSize size)
{
    // Set margins from the normal element
    qreal left, top, right, bottom;

    m_svgImage->setElementPrefix("normal");
    m_svgImage->getMargins(left, top, right, bottom);
    left = top = right = bottom = 2;
    m_margins = QMargins(left, top, right, bottom);

    // Calculate the rect for the over effect
    setRect(size);
}

#include "moc_pushbutton.cpp"