#pragma once

#include <string>

#include <QtCore>
#include <QtQuick>
#include <QImage>
#include <QUrl>

#include "Tool.hpp"


using namespace std;

class Editor : public QObject {

    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QImage* image READ getImage)
    Q_PROPERTY(QUrl temp_path MEMBER _temp_path)
    Q_PROPERTY(QUrl path MEMBER _path)

public:

    explicit Editor(QObject *parent = nullptr);

    QImage* getImage() {return &_image; }

    Q_INVOKABLE void load(QUrl url);
    Q_INVOKABLE bool save(QUrl url);
    Q_INVOKABLE void close();


    QImage _image;

private:
    QUrl _path, _temp_path;
    QString _temp_filepath;

    
signals:
    void loaded(QUrl temp_path);

};