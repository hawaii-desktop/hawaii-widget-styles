
#include <QDebug>
#include <QStyle>
#include <QStyleOption>
#include <QPainter>

#include "pushbutton.h"

using namespace Fluid;

PushButton::PushButton(QObject *parent)
    : QObject(parent)
{
    m_background = new FrameSvg(this);
    m_background->setImagePath("widgets/button");
    m_background->setCacheAllRenderedFrames(true);
    m_background->setElementPrefix("normal");
}

PushButton::~PushButton()
{
    delete m_background;
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
    syncBorders(rect.size());
    syncFrame(rect.size());

    QPixmap bufferPixmap;

    if (isEnabled) {
        // A normal button (pressed or not)
        if (isDown || isChecked)
            m_background->setElementPrefix("pressed");
        else
            m_background->setElementPrefix("normal");
    } else if (!isEnabled || isFlat) {
        // A normal button disabled or a flat button
        bufferPixmap = QPixmap(rect.size());
        bufferPixmap.fill(Qt::transparent);

        QPainter bufferPainter(&bufferPixmap);
        m_background->paintFrame(&bufferPainter);
        bufferPainter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
        bufferPainter.fillRect(bufferPixmap.rect(), QColor(0, 0, 0, 128));

        painter->drawPixmap(0, 0, bufferPixmap);
    }

    if (!isDown && !isChecked && isEnabled && m_background->hasElementPrefix("active")) {
        //....
        m_background->setElementPrefix("active");
        m_background->paintFrame(painter, m_activeRect.topLeft());
    } else if (isEnabled) {
        m_background->paintFrame(painter, QPointF(m_margins.left() + 1, m_margins.top() + 1));
    }
}

void PushButton::drawDefaultFrame(const QStyleOption *option, QPainter *painter, const QWidget *widget)
{
    QRect rect(option->rect);

    syncFrame(rect.size());

    m_background->setElementPrefix("focus");
    m_background->paintFrame(painter);
}

void PushButton::syncFrame(QSize size)
{
    m_background->setElementPrefix("pressed");
    m_background->resizeFrame(size);

    m_background->setElementPrefix("focus");
    m_background->resizeFrame(size);

    syncActiveRect(size);

    m_background->setElementPrefix("normal");
    m_background->resizeFrame(size);
    //hoverAnimation->setProperty("startPixmap", m_background->framePixmap());

    m_background->setElementPrefix("active");
    m_background->resizeFrame(m_activeRect.size());
    //hoverAnimation->setProperty("targetPixmap", m_background->framePixmap());
}

void PushButton::syncActiveRect(QSize size)
{
    m_background->setElementPrefix("normal");

    qreal left, top, right, bottom;
    m_background->getMargins(left, top, right, bottom);

    m_background->setElementPrefix("active");
    qreal activeLeft, activeTop, activeRight, activeBottom;
    m_background->getMargins(activeLeft, activeTop, activeRight, activeBottom);

    m_activeRect = QRectF(QPointF(0, 0), size);
    m_activeRect.adjust(left - activeLeft, top - activeTop,
                        -(right - activeRight), -(bottom - activeBottom));

    m_background->setElementPrefix("normal");
}

void PushButton::syncBorders(QSize size)
{
    // Set margins from the normal element
    qreal left, top, right, bottom;

    m_background->setElementPrefix("normal");
    m_background->getMargins(left, top, right, bottom);
    left = top = right = bottom = 2;
    m_margins = QMargins(left, top, right, bottom);

    // Calculate the rect for the over effect
    syncActiveRect(size);
}

#include "moc_pushbutton.cpp"
