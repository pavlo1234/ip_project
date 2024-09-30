import QtQuick

import Qt.labs.platform
import QtQuick.Dialogs
import QtQuick.Controls
import QtQuick.Layouts

import com.editing 1.0

Rectangle {
    id: toolBar
    
    signal filter(var params)
    signal reload()
    signal exit()

    color: "white"

    ColumnLayout {
        id: toolBarLayout
        anchors.fill: parent
        RowLayout {
            id: headerRow
            Layout.preferredWidth: 0.9*parent.width
            Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
            Layout.topMargin: 10
            Text {
                id: title
                text: "Spatial filtering: "
                font.bold: true
                font.pixelSize: 15
                color: "#575655"
                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
            }

            Text {
                id: exitButton
                text: "\u2716"
                font.bold: true
                font.pixelSize: 15
                color: "#575655"

                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter

                MouseArea {
                    anchors.fill: parent
                    onClicked: () => {
                        toolBar.exit();
                    }
                }

            }
        }
        

        ButtonGroup { id: radioGroup }

        RowLayout {
            id: radioGroupRow
            Layout.preferredWidth: 0.3*parent.width
            Layout.alignment: Qt.AlignTop | Qt.AlignHCenter

            RadioButton {
                checked: text == String(kernelMatrix.rows)
                text: qsTr("3")
                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                ButtonGroup.group: radioGroup
                onClicked: {
                    kernelMatrix.reshape(3,3);
                    methodList.setKernel(methodList.indexOfValue("Custom"));
                }
            }

            RadioButton {
                checked: text == String(kernelMatrix.rows)
                text: qsTr("5")
                ButtonGroup.group: radioGroup
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                onClicked: {
                    kernelMatrix.reshape(Number(text),Number(text));
                    methodList.setKernel(methodList.indexOfValue("Custom"));
                }
            }
        }
        
        Matrix {
            id: kernelMatrix
            columns: 3
            rows: 3
            Layout.preferredWidth: 150
            Layout.preferredHeight: 150
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
        }

        ComboBox {
            id: methodList
            editable: false

            Layout.preferredWidth: 0.9*parent.width
            Layout.alignment: Qt.AlignTop | Qt.AlignHCenter

            model: ListModel {
                id: model
                ListElement { text: "Custom" }
                ListElement { text: "Gauss Low Pass Filter (3x3)" }
                ListElement { text: "Gauss Low Pass Filter (5x5)" }
                ListElement { text: "Laplace High Pass Filter (3x3)" }
                ListElement { text: "Laplace High Pass Filter (5x5)" }
                ListElement { text: "Prewitt Gradient Filter (vertical)" }
                ListElement { text: "Prewitt Gradient Filter (horizontal)" }
                ListElement { text: "Sobel Gradient Filter (vertical)" }
                ListElement { text: "Sobel Gradient Filter (horizontal)" }
                ListElement { text: "Softening" }
                ListElement { text: "Sharpen" }
                ListElement { text: "Edge detection" }
                
            }

            function setKernel(ind) {
                currentIndex = ind;
                var method = textAt(ind);
                switch(method) {
                    case "Gauss Low Pass Filter (3x3)":
                        kernelMatrix.setValues([1, 2, 1, 2, 4, 2, 1, 2, 1], 3);
                        kernelMatrix.coeff = 16;
                        break;
                    case "Gauss Low Pass Filter (5x5)":
                        kernelMatrix.setValues([2, 7, 12, 7, 2, 7, 31, 52, 31, 7, 12, 52, 127, 52, 12, 7, 31, 52, 31, 7, 2, 7, 12, 7, 2], 5);
                        kernelMatrix.coeff = 571;
                        break;
                    case "Laplace High Pass Filter (3x3)":
                        kernelMatrix.setValues([-1, -1, -1, -1, 8, -1, -1, -1, -1], 3);
                        kernelMatrix.coeff = 1;
                        break;
                    case "Laplace High Pass Filter (5x5)":
                        kernelMatrix.setValues([-1, -3, -4, -3, -1, -3, 0, 6, 0, -3,-4, 6, 20, 6, -4, -3, 0, 6, 0, -3, -1, -3, -4, -3, -1], 5);
                        kernelMatrix.coeff = 1;
                        break;
                    case "Prewitt Gradient Filter (vertical)":
                        kernelMatrix.setValues([1, 0, -1, 1, 0, -1, 1, 0, -1], 3);
                        kernelMatrix.coeff = 1;
                        break;
                    case "Prewitt Gradient Filter (horizontal)":
                        kernelMatrix.setValues([-1, -1, -1, 0, 0, 0, 1, 1, 1], 3);
                        kernelMatrix.coeff = 1;
                        break;
                    case "Sobel Gradient Filter (vertical)":
                        kernelMatrix.setValues([1, 0, -1, 2, 0, -2, 1, 0, -1], 3);
                        kernelMatrix.coeff = 1;
                        break;
                    case "Sobel Gradient Filter (horizontal)":
                        kernelMatrix.setValues([-1, -2, -1, 0, 0, 0, 1, 2, 1], 3);
                        kernelMatrix.coeff = 1;
                        break;
                    case "Edge detection":
                        kernelMatrix.setValues([1, 1, 1, 1, 2, 1, -1, -1, -1], 3);
                        kernelMatrix.coeff = 4;
                        break;
                    case "Sharpen":
                        kernelMatrix.setValues([-1, -1, -1, -1, 16, -1, -1, -1, -1], 3);
                        kernelMatrix.coeff = 1;
                        break;
                    case "Softening":
                        kernelMatrix.setValues([2, 2, 2, 2, 0, 2, 2, 2, 2], 3);
                        kernelMatrix.coeff = 16;
                        break;
                    case "Custom":
                        kernelMatrix.clear();
                        break;
                }
            }

            onActivated: () => {
                setKernel(currentIndex);
            }
        }

        CheckBox {
            id: fileChoosingButton
            checked: false
            text: qsTr("To original image")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
        }

        Button {
            id: filterButton
            text: qsTr("Apply")
            Layout.preferredWidth: 0.7*parent.width
            Layout.preferredHeight: 40
            Layout.alignment: Qt.AlignTop | Qt.AlignHCenter

            onClicked: {
                filter({kernel: kernelMatrix.getValues(), N: kernelMatrix.rows, R: kernelMatrix.coeff, toOriginal: fileChoosingButton.checked});
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