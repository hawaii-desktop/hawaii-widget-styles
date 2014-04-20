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
    qmldir
)

install(FILES ${FILES}
        DESTINATION ${STYLES_INSTALLDIR}/Aluminium)

set(IMAGES
    images/progress-indeterminate.png
    images/noise-texture.png
)

install(FILES ${IMAGES}
        DESTINATION ${STYLES_INSTALLDIR}/Aluminium/images)
