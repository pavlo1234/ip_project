import QtQuick

import Qt.labs.platform
import QtQuick.Dialogs
import QtQuick.Controls
import QtQuick.Layouts

import QtCharts 2.7


import com.editing 1.0


Rectangle {
    id: chartBlock

    signal reload()
    signal exit()

    ChartView {
        id: chart
        title: "Bar Chart"
        anchors.fill: parent
        legend.alignment: Qt.AlignBottom
        antialiasing: true

        
    }
    
}