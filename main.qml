import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    width: 400
    height: 300
    title: "Mongo Launcher"
    visible: true
    color: "#102f11"

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 20

        Text {
            text: "🍃 Mongo Launcher"
            font.pixelSize: 24
            font.bold: true
            color: "#4CAF50"
            Layout.alignment: Qt.AlignHCenter
        }

        Button {
            text: "Hello Mongo!"
            onClicked: {
                console.log("MongoDB launched!")
                statusText.text = "✅ MongoDB Running on port 27017"
            }
            Layout.alignment: Qt.AlignHCenter
        }

        Text {
            id: statusText
            text: "⏳ Not connected"
            color: "#666"
            Layout.alignment: Qt.AlignHCenter
        }
    }
}