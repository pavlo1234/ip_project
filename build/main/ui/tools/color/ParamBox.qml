import QtQuick

import Qt.labs.platform
import QtQuick.Dialogs
import QtQuick.Controls
import QtQuick.Layouts

import QtQml

RowLayout {
    id: paramBox

    property string title

    Text {
        id: paramTitle
        text: paramBox.title + " = "
        font.bold: true
        font.pixelSize: 15
        color: "#575655"
        Layout.alignment:  Qt.AlignLeft | Qt.AlignVCenter
    }
    TextField {
        id: paramInput
        width: 0.8*parent.width
        horizontalAlignment: TextInput.AlignHCenter
        verticalAlignment: TextInput.AlignVCenter
        inputMethodHints: Qt.ImhFormattedNumbersOnly
        validator: DoubleValidator{bottom: -999999.0; top: 999999.0;}

        Layout.alignment:  Qt.AlignRight | Qt.AlignVCenter
    }

    function getValue() {
        return parseFloat(paramInput.text.replace(",", "."));
    }
}