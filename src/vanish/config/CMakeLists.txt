include_directories(
    ${Qt5Widgets_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
)

add_definitions(
    ${Qt5Widgets_DEFINITIONS}
    -DCONFIG_WRITE -DCONFIG_DIALOG
)

set(SOURCES
    vanishconfig.cpp
    imagepropertiesdialog.cpp
    exportthemedialog.cpp
    ../common.cpp
    ../config_file.cpp
)

set(UI_SOURCES
    imageproperties.ui
    stylepreview.ui
    vanishconfigbase.ui
)

qt5_wrap_ui(UI_FILES ${UI_SOURCES})

add_executable(VanishConfig ${SOURCES} ${UI_FILES})
set_target_properties(VanishConfig PROPERTIES COMPILE_FLAGS ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS})
target_link_libraries(VanishConfig ${Qt5Widgets_LIBRARIES})

install(TARGETS VanishConfig DESTINATION ${CMAKE_INSTALL_PROGSDIR})
