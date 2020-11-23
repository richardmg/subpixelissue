#include "myrectangle.h"

#include <QtGui/qpainter.h>
#include <QtQuick/qsgimagenode.h>
#include <QtQuick/qquickwindow.h>

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

MyRectangle::MyRectangle(QQuickItem *parent)
    : QQuickItem(parent)
{
    setFlag(QQuickItem::ItemHasContents);
}

QSGNode *MyRectangle::updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *)
{
    QSGImageNode *node = static_cast<QSGImageNode *>(oldNode);
    if (!node)
        node = window()->createImageNode();

    QImage image(QSize(100, 100), QImage::Format_ARGB32_Premultiplied);
    image.fill(Qt::white);

    QPainter painter(&image);
    painter.setPen(QColor(255, 0, 0, 255));
    painter.drawRect(QRect(QPoint(0, 0), QSize(50, 10)));

    auto texture = window()->createTextureFromImage(image);

//    QRectF bounds = boundingRect();
    QRect bounds(QPoint(0, 0), image.size());

    node->setSourceRect(bounds);
    node->setRect(bounds);
    node->setTexture(texture);

    return node;
}


QT_END_NAMESPACE
