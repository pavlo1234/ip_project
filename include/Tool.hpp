#pragma once

#include <QtCore>
#include <QtQuick>
#include <QImage>

class Tool
{
    QML_INTERFACE

public:
    virtual bool process(QImage image) = 0;
};

Q_DECLARE_INTERFACE(Tool, "com.editing")