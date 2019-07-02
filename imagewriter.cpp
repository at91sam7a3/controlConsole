#include "imagewriter.h"
#include <QPainter>

ImageWriter::ImageWriter(QQuickItem* parent ) : QQuickPaintedItem (parent)
{

}


void ImageWriter::paint(QPainter *painter)
{
  //  image = image.scaled (1920,1080,Qt::KeepAspectRatio);
    painter->drawImage(QPoint(0,0),this->image);
        //this will simply draw the image in your qml UI !
}
