include_directories(
    ${Qt5Widgets_INCLUDE_DIRS}
    ${Qt5Widgets_PRIVATE_INCLUDE_DIRS}
    ${Fluid_INCLUDE_DIRS}
)

add_definitions(
    ${Qt5Widgets_DEFINITIONS}
    -DQT_PLUGIN
)

set(SOURCES
    main.cpp
    fluidstyle.cpp
    lineedit.cpp
    pushbutton.cpp
    scrollbars.cpp
)

add_library(fluid SHARED ${SOURCES})
set_target_properties(fluid PROPERTIES PREFIX "")
target_link_libraries(fluid
    ${Qt5Widgets_LIBRARIES}
    ${Fluid_LIBRARIES}
)

install(TARGETS fluid LIBRARY DESTINATION ${CMAKE_INSTALL_PLUGINSDIR}/styles)
