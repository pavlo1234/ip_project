import QtQuick

import Qt.labs.platform
import QtQuick.Dialogs
import QtQuick.Controls

import QtQml

Grid {
    id: matrix 

    property int coeff: 1

    width: 150
    height: 150

    Component.onCompleted: () => {
        reshape(rows, columns);
    }

    function reshape(rows: int, columns: int) {
        matrix.rows = rows;
        matrix.columns = columns;
        console.log("Matrix: trying reshape to ", rows, "*", columns);

        var component = Qt.createComponent("Cell.qml");
        if(matrix.children.length != 0) {
            while(matrix.children.length>0) matrix.children.pop().destroy();
        }

        if (component.status == Component.Ready) {
            for(var i=0;i<rows*columns;i++)
                component.createObject(matrix, {width: width/columns, 
                                                height: height/rows,
                                                });
        }
    }

    function clear() {
        for(var i = 0; i < rows*rows; i+=1) {
            matrix.children[i].text = "";
        }
    }

    function setValues(array: list, N: int) {
        if(rows != N) reshape(N, N);
        for(var i = 0; i < N*N; i+=1) {
            matrix.children[i].text = String(array[i]);
        }
    }

    function getValues() {
        var array = [];
        for(var cell of matrix.children) {
            array.push(Number(cell.text));
        }

        console.log("Matrix items: ");
        for(var i=0;i<rows*columns;i++) console.log(array[i], " ");

        return array;
    }

}