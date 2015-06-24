import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

GridLayout {
    SystemPalette { id: sysPalette; colorGroup: SystemPalette.Active }

    anchors.fill: parent
    anchors.margins: 16
    Layout.minimumWidth: 400
    Layout.minimumHeight: 300
    columns: 1
    rows: 1

    Calendar {
    }
}
