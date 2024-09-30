import QtQuick

import Qt.labs.platform
import QtQuick.Dialogs
import QtQuick.Controls

import QtQml

TextField {
    id: cell 

    horizontalAlignment: TextInput.AlignHCenter
    verticalAlignment: TextInput.AlignVCenter
    inputMethodHints: Qt.ImhFormattedNumbersOnly
    validator: IntValidator{bottom: -999999; top: 999999;}

}