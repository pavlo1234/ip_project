import QtQuick

import Qt.labs.platform
import QtQuick.Dialogs
import QtQuick.Controls

import QtQml

import QtCharts



import "tools/"
import com.editing 1.0

Window {
    id: mainWindow
    visible: true
    width: 900
    height: 600
    color: "#c3c6c9"

    FileDialog {
        id: fileDialog
        signal imageOpened(path: url)
        signal imageSaved(path: url)

        function openImage() {
            fileDialog.fileMode = FileDialog.OpenFile;
            fileDialog.open();
        }

        function saveImage() {
            fileDialog.fileMode = FileDialog.SaveFile;
            fileDialog.open();
        }

        currentFolder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
        onAccepted: function() {
            if(selectedFile != "") 
                if(fileDialog.fileMode == FileDialog.OpenFile)
                    imageOpened(selectedFile);
                else
                    imageSaved(selectedFile);
        }
    }

    MenuBar {
        id: menuBar

        Menu {
            id: fileMenu
            title: qsTr("File")

            MenuItem {
                text: "Open..."
                onTriggered: () => {
                    console.log("Menu: Image opening...");
                    fileDialog.openImage();
                }
                
            }
            MenuItem {
                text: "Save..."
                onTriggered: {
                    fileDialog.saveImage();
                }
            }
            MenuItem {
                text: "Close..."
                onTriggered: {
                    editor.close();
                    view.close();
                }
            }

        }

        Menu {
            id: editMenu
            title: qsTr("&Edit")

            MenuItem {
                text: "1. Custom filtering"
                onTriggered: () => {
                    console.log("Menu: Enabling filtering tab...");
                    toolLoader.load("tools/filter/FilterTool.qml");
                }
            }
            MenuItem {
                text: "2. Color transformation"
                onTriggered: () => {
                    console.log("Menu: Enabling color tab...");
                    toolLoader.load("tools/color/ColorTool.qml");
                }
            }
            Menu {
                id: colorAnalysisMenu
                title: "3. Color analysis"
                MenuItem {
                    text: " - Perform analysis"
                    onTriggered: () => {
                        console.log("Menu: Enabling graph tab...");
                        //toolLoader.load("tools/color/DistPlotView.qml");
                    }
                }
                MenuItem {
                    text: " - Close"
                    onTriggered: () => {
                       // toolLoader.close();
                    }
                }
            }
            
        }

        Menu {
            id: helpMenu
            title: qsTr("&Help")
        }
    }

    SplitView {
        id: splitView
        anchors.fill: parent

        handle: Rectangle {
            id: handle
            height: parent.height
            width: 2
            color: "#575655"
        }

        Loader {
            id:  toolLoader
            property alias tool: toolLoader.item

            SplitView.preferredWidth: toolLoader.tool ? 250 : 0 
            SplitView.preferredHeight: parent.height

            asynchronous: true
            visible: status == Loader.Ready

            function load(path: url) {
                toolLoader.setSource(path);
                toolLoader.active = true;
            }

            function close() {
                toolLoader.active = false;
            }


            onLoaded: () => {
                console.log("ToolBar: content has been loaded.");
            }
        }

        
        Filter {
            id: filter
        }

        ColorTransformer {
            id: color_transformer
        }

        Connections {
            target: toolLoader.tool

            function onColorTransform(params) {
                if(color_transformer.transform(editor.image, params.method, params.coeff)) {
                    console.log("ColorTransformer: successed.");
                    
                    var path = params.toOriginal ? editor.path : editor.temp_path;
                    if(editor.save(path))
                        view.show(path);
                }
            }

            function onFilter(params) {
                filter.setKernel(params.kernel, params.N, params.R);
                if(filter.process(editor.image)){
                    console.log("Filter: successed.");
                    var path = params.toOriginal ? editor.path : editor.temp_path;
                    if(editor.save(path))
                        view.show(path);
                }
                
            }

            function onReload() {
                editor.load(editor.path);
                view.show(editor.path);
            }

            function onExit() {
                toolLoader.close();
            }
        }
      

        Item {
            id: viewContainer
            SplitView.fillWidth: true
            SplitView.fillHeight: true
          
            ChartView {
                id: chart
                title: "Bar Chart"
                anchors.fill: parent

                
            }

          /*
            Image {
                id: view 
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                anchors.margins: 30
                anchors.fill: parent

                fillMode: Image.PreserveAspectFit
                asynchronous: true
                cache: false
                function show(path){
                    close();
                    view.source = path;
                }
                function close(){
                    view.source = "";
                }
                onStatusChanged: if (view.status == Image.Ready) console.log("View: Image is loaded.");
                State { name: 'loaded'; when: view.status == Image.Ready }
            }
            */
        }

        
    }

    
    Editor {
        id: editor
        onLoaded: (path) => {
            console.log("Editor: image is loaded");
            view.show(path);
        }
    }

    Connections {
        target: fileDialog
        function onImageOpened(path) {
            console.log("Loading image to Editor...");
            editor.load(path);
        }
        function onImageSaved(path) {
            console.log("Saving image...");
            editor.save(path);
        }
    }

    onClosing: {
        editor.close();
    }

}