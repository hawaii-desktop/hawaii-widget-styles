set(FILES
    BusyIndicatorStyle.qml
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
    SwitchStyle.qml
    TabViewStyle.qml
    TableViewStyle.qml
    TextFieldStyle.qml
    ToolBarStyle.qml
    ToolButtonStyle.qml
    ColorUtils.js
    Constants.js
    qmldir
)

install(FILES ${FILES}
        DESTINATION ${QML_INSTALL_DIR}/QtQuick/Controls/Styles/Aluminium)

set(IMAGES
    images/progress-indeterminate.png
    images/noise-texture.png
)

install(FILES ${IMAGES}
        DESTINATION ${QML_INSTALL_DIR}/QtQuick/Controls/Styles/Aluminium/images)
