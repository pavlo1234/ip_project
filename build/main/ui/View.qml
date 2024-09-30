import QtQuick
import QtQml

Canvas {
    id: canvas

    property url image_path
    

    function show(path){
        if(image_path == path) 
            canvas.unloadImage(path);

        image_path = path;
        console.log("View: showing image with path ", path);
        
        loadImage(path);
       
    }

    onPaint: () => {
        if(image_path != "") {
            console.log("View: drawing image ", image_path, " on context");
            var ctx = getContext("2d");
            ctx.drawImage(image_path, 0, 0);
            ctx.save();
        }
        
        
    }

    onImageLoaded: () => {
        console.log("View: image is loaded.")
        requestPaint();
    }


}