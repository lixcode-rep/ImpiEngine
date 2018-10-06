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
	color: "transparent"

    Connections
    {
        target: qmlApp
    }

	Rectangle {
		x: 10;
		y: 100;
		width: 400
		height: 450
		color: "white"
	}

    RowLayout
    {
		anchors.left: parent.left
		anchors.right: parent.horizontalCenter
		anchors.top: parent.top
		anchors.bottom: parent.bottom

		visible: true

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
