import QtQuick

import Qt.labs.platform
import QtQuick.Dialogs
import QtQuick.Controls
import QtQuick.Layouts

import com.editing 1.0

Rectangle {
    id: toolBar
    
    signal colorTransform(var params)
    signal reload()
    signal exit()

    color: "white"

    ColumnLayout {
        id: toolBarLayout
        anchors.fill: parent

        Text {
            id: title
            text: "Color transformation: "
            font.bold: true
            font.pixelSize: 15
            color: "#575655"
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            Layout.leftMargin: 0.05*parent.width
            Layout.topMargin: 10
        }

        ComboBox {
            id: methodList
            editable: false

            Layout.preferredWidth: 0.9*parent.width
            Layout.alignment: Qt.AlignTop | Qt.AlignHCenter

            model: ListModel {
                id: model
                ListElement { text: "Grayscale" }
                ListElement { text: "Invert" }
                ListElement { text: "Logarithmic" }
                ListElement { text: "Power" }
            }

            onActivated: () => {
                var method = textAt(currentIndex);

                paramsBox.clear();
                switch(method) {
                    case "Logarithmic":
                        paramsBox.addParams(["C"]);
                        break;
                    case "Power":
                        paramsBox.addParams(["Gamma"]);
                        break;
                }
            }

        }

        Column {
            id: paramsBox
            Layout.preferredWidth: 0.8*parent.width
            Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
            spacing: 10
            
            function addParams(params){
                var component = Qt.createComponent("ParamBox.qml");
                if (component.status == Component.Ready) {
                    for(var name of params) {
                        component.createObject(paramsBox, {title: name, width: paramsBox.width});
                    }
                }
                else console.log("Failed to load component: ParamBox");
            }

            function clear() {
                while(paramsBox.children.length>0) 
                    paramsBox.children.pop().destroy();
            }

            function getParams() {
                var params = [];
                for(var param of paramsBox.children) {
                    params.push([param.title, param.getValue()]);
                }
                return params;
            }
        }

        CheckBox {
            id: fileChoosingButton
            checked: false
            text: qsTr("To original image")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
        }

        Button {
            id: transformButton
            text: qsTr("Apply")
            Layout.preferredWidth: 0.7*parent.width
            Layout.preferredHeight: 40
            Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter

            onClicked: {
                colorTransform({method: methodList.textAt(methodList.currentIndex), coeff: paramsBox.getParams(), toOriginal: fileChoosingButton.checked});
            }

        }

        Button {
            id: reloadButton
            text: qsTr("Reload")
            Layout.preferredWidth: 0.5*parent.width
            Layout.preferredHeight: 30
            
            Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
            Layout.bottomMargin: 30

            onClicked: {
                reload();
            }

        }

    }

}