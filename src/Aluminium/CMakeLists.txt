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
    SliderStyle.qml
    SpinBoxStyle.qml
    StatusBarStyle.qml
    TabViewStyle.qml
    TableViewStyle.qml
    TextFieldStyle.qml
    ToolBarStyle.qml
    ToolButtonStyle.qml
)

if("${Qt5_VERSION}" VERSION_EQUAL "5.2.0" OR "${Qt5_VERSION}" VERSION_GREATER "5.2.0")
    set(FILES
        ${FILES}
        BusyIndicatorStyle.qml
        SwitchStyle.qml
    )

    install(FILES qmldir52
            DESTINATION ${QT_IMPORTS_DIR}/QtQuick/Controls/Styles/Aluminium
            RENAME qmldir)
else()
    set(FILES
        ${FILES}
        ScrollViewStyle.qml
        qmldir
    )
endif()

install(FILES ${FILES}
        DESTINATION ${QT_IMPORTS_DIR}/QtQuick/Controls/Styles/Aluminium)

set(IMAGES
    images/progress-indeterminate.png
    images/noise-texture.png
)

install(FILES ${IMAGES}
        DESTINATION ${QT_IMPORTS_DIR}/QtQuick/Controls/Styles/Aluminium/images)
