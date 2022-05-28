import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import MulticastTableModel

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Table View - Resizable Columns")

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 5

        RowLayout {

            Label {
                text: qsTr("Interface:")
            }
            ComboBox {
                Layout.fillWidth: true
                implicitHeight: 40
            }
        }

        Label {
            text: qsTr("Multicasts:")
        }

        ResizableColumnsTableView {
            Layout.fillHeight: true
            Layout.fillWidth: true
            model: MulticastTableModel {}
            columnWidths: [250, 200, 100]
        }

        RowLayout {
            Layout.alignment: Qt.AlignRight

            Button {
                text: "Add"
            }

            Button {
                text: "Edit"
            }

            Button {
                text: "Delete"
            }
        }
    }

}
