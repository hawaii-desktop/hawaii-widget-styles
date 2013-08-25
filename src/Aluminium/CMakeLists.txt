set(FILES
    ButtonStyle.qml
    CheckBoxStyle.qml
    ComboBoxStyle.qml
    FocusFrameStyle.qml
    GroupBoxStyle.qml
    MenuBarStyle.qml
    MenuStyle.qml
    ProgressBarStyle.qml
    RadioButtonStyle.qml
    ScrollViewStyle.qml
    SliderStyle.qml
    SpinBoxStyle.qml
    StatusBarStyle.qml
    TabViewStyle.qml
    TableViewStyle.qml
    TextFieldStyle.qml
    ToolBarStyle.qml
    ToolButtonStyle.qml
    images/progress-indeterminate.png
    images/noise-texture.png
    qmldir
)

install(FILES ${FILES}
        DESTINATION ${QT_IMPORTS_DIR}/QtQuick/Controls/Styles/Aluminium)
