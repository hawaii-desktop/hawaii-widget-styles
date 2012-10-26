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

#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <Fluid/FrameSvg>

class PushButton : public QObject
{
    Q_OBJECT
public:
    PushButton(QObject *parent = 0);
    ~PushButton();

    void paint(const QStyleOption *option, QPainter *painter, const QWidget *widget = 0);
    void drawDefaultFrame(const QStyleOption *option, QPainter *painter, const QWidget *widget = 0);

private:
    Fluid::FrameSvg *m_svgImage;
    QRectF m_activeRect;
    QMargins m_margins;

    void setFrame(QSize size);
    void setRect(QSize size);
    void setBorders(QSize size);
};

#endif // PUSHBUTTON_H
