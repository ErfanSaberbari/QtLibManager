import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
//import LibraryManagement
//import QtQuick.Studio.DesignEffects

ApplicationWindow {
    visible: true
    width: 1920
    height: 1080
    title: qsTr("Hello World")

        // Side Navigation
        Rectangle {
            id: navigationPane
            x: 16
            y: 35
            width: 100
            height: 1000
            //height: parent.height
            color: "#f5f5f5"
            radius: 10

            Column {
                spacing: 10
                anchors.centerIn: parent
                Button {
                    text: "HOME"
                    highlighted: false
                    flat: true
                    icon.color: "#26282a"
                    onClicked: stackView.currentIndex = 0
                }
                Button {
                    text: "Members"
                    flat: true
                    onClicked: stackView.currentIndex = 1
                }
                Button {
                    text: "Books"
                    flat: true
                    onClicked: stackView.currentIndex = 2
                }
            }
        }

        // Stacked View for Pages
        StackLayout {
            id: stackView
            anchors.left: navigationPane.right
            width: parent.width - navigationPane.width
            height: parent.height

            currentIndex: 1  // Default page

            // Page 1: Home
            Item {
                Label {
                    text: "Page 1 - Home"
                    font.pixelSize: 18
                    font.bold: true
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Column {
                    spacing: 10
                    anchors.centerIn: parent
                    Button {
                        text: "All Books"
                    }
                    Button {
                        text: "Available Books"
                    }
                    Button {
                        text: "Borrowed Books"
                    }
                }
            }

            // Page 2: Members
            Item {
                Label {
                    y: 8
                    text: "Members"
                    font.pixelSize: 18
                    anchors.horizontalCenterOffset: -421
                    font.bold: true
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Column {
                    anchors.verticalCenterOffset: 229
                    anchors.horizontalCenterOffset: 660
                    spacing: 10
                    anchors.centerIn: parent
                    Button {
                        text: "All Books"
                    }
                    Button {
                        text: "Available Books"
                    }
                    Button {
                        text: "Borrowed Books"
                    }
                }
                TextField {
                    id: searchField
                    width: 650
                    placeholderText: "Search..."
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                TableView {
                    x: 0
                    y: 234
                    width: 1101
                    height: 672
                    anchors.horizontalCenterOffset: -233
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

            // Page 3: Books
            Item {
                Label {
                    text: "Page 3 - Books"
                    font.pixelSize: 18
                    font.bold: true
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
    }
