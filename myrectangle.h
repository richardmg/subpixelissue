#ifndef MYRECTANGLE_H
#define MYRECTANGLE_H

#include <QtQuick/qquickitem.h>

QT_BEGIN_NAMESPACE

class MyRectangle : public QQuickItem
{
    Q_OBJECT

public:
    explicit MyRectangle(QQuickItem *parent = nullptr);

protected:
    QSGNode *updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *updatePaintNodeData) override;
};

#endif // MYRECTANGLE_H
