#include "Editor.hpp"
#include <QDebug>
#include <QImageReader>
#include <QImageWriter>

Editor::Editor(QObject *parent): QObject(parent) {

}

void Editor::load(QUrl url) 
{

    close();

    _path = url;
    QString filepath = url.path();
    filepath.erase(filepath.begin());
    
    QImageReader reader(filepath);
    _image = reader.read();
   
    if(_image.isNull()) {
        qDebug() << " - Editor::load(url) : " << "Failed to read image in path " << filepath << ": " << reader.errorString();
        return;
    }

    _temp_filepath = filepath.insert(filepath.lastIndexOf("."), "_temp");   
    _temp_path = QUrl("file:///"+_temp_filepath);
    save(_temp_path);

    emit loaded(_path);

}

bool Editor::save(QUrl url)
{
    QString filepath = url.path();
    filepath.erase(filepath.begin());
    
    QImageWriter writer;
    writer.setFileName(filepath);
    if(writer.write(_image)) {
        qDebug() << " - Editor::save(url) : Image saved at path " << filepath;
        return true;
    }
    else {
        qDebug() << " - Editor::save(url) : Failed to write image at path " << filepath;
        return false;
    }

}

void Editor::close() 
{
    if(!_path.isEmpty()) {
        QFile temp_file(_temp_filepath);
        temp_file.open(QIODeviceBase::ReadWrite);
        temp_file.remove();    
    }
    _path = QUrl();
    _temp_path = QUrl();
    _image = QImage();

}