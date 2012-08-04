include_directories(
    ${Qt5Widgets_INCLUDE_DIRS}
)

add_definitions(${Qt5Widgets_DEFINITIONS} -DQT_PLUGIN)

set(SOURCES
    main.cpp
    vanishstyle.cpp
)

qt5_add_resources(RESOURCES_RCC vanish.qrc)

add_library(vanish SHARED ${SOURCES} ${RESOURCES_RCC})
set_target_properties(vanish PROPERTIES PREFIX "")
target_link_libraries(vanish ${Qt5Widgets_LIBRARIES})

#install(TARGETS vanish LIBRARY DESTINATION ${CMAKE_INSTALL_PLUGINSDIR}/styles)
install(TARGETS vanish LIBRARY DESTINATION /opt/qt5/plugins/styles)
