
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
    Fluid::FrameSvg *m_background;
    QRectF m_activeRect;
    QMargins m_margins;

    void syncFrame(QSize size);
    void syncActiveRect(QSize size);
    void syncBorders(QSize size);
};

#endif // PUSHBUTTON_H
