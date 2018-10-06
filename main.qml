import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3

import OpenGLUnderQML 1.0

Window
{
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Connections
    {
        target: qmlApp
    }

    RowLayout
    {
        anchors.fill: parent
        ColumnLayout
        {
            ToolButton
            {
                id: oneButton

                text: qsTr("Click me ONE")

                onClicked: console.log("First button clicked.");
            }
            ToolButton
            {
                id: twoButton

                text: qsTr("Click me TWO")

                onClicked: console.log("Second button clicked.");
            }
            ToolButton
            {
                id: threeutton

                text: qsTr("Click me THREE")

                onClicked: console.log("Thrid button clicked.");
            }
        }

        OpenGLWidget
        {
            id: openGL
        }
    }

}
