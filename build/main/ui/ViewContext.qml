import QtQuick
import QtQml

Rectangle {
    id: canvasBackground
    color: "#c3c6c9"

    property url image_path;

    Canvas {
        id: canvas
        anchors.fill: parent
        anchors.margins: 10

    }

    function loadImage(path){
        image_path = path;
    }
}