#pragma once

#include <QtCore>
#include <QtQuick>
#include <QImage>
#include <QVariant>
#include <QMap>
#include <QList>
#include <QJSValue>
#include <QJSEngine>



class ColorTransformer: public QObject
{
    Q_OBJECT
    QML_ELEMENT

public: 

    explicit ColorTransformer(QObject *parent = nullptr): QObject(parent) {
        
    }
    Q_INVOKABLE bool transform(QImage* image, QString method, QVariantList jsList);
    Q_INVOKABLE QVariantMap getDistribution(QImage* image);

    bool invert_transform(QImage* image);
    bool gray_transform(QImage* image);
    bool log_transform(QImage* image, double c);
    bool pow_transform(QImage* image, double gamma);



};