#ifndef IMAGEWRITER_H
#define IMAGEWRITER_H

#include <QQuickPaintedItem>
#include <QImage>
#include <QObject>
#include <QQuickItem>


class ImageWriter : public QQuickPaintedItem
{
    Q_OBJECT
public:
    ImageWriter( QQuickItem * parent=nullptr);
    void paint( QPainter *painter);
    QImage image;
};

#endif // IMAGEWRITER_H
