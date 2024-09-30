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

        onPaint: {
            var ctx = getContext("2d");
            ctx.drawImage(image_path, 0, 0, canvas.width, canvas.height);
        }

    }


    function loadImage(path){
        image_path = path;
        canvas.requestPaint();
    }
}