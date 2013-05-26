project(WidgetStyles)

cmake_minimum_required(VERSION 2.8.9)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

# Set version
set(WIDGETSTYLES_VERSION_MAJOR 0)
set(WIDGETSTYLES_VERSION_MINOR 1)
set(WIDGETSTYLES_VERSION_PATCH 90)
set(WIDGETSTYLES_VERSION_STRING "${WIDGETSTYLES_VERSION_MAJOR}.${WIDGETSTYLES_VERSION_MINOR}.${WIDGETSTYLES_VERSION_PATCH}")

# Installation directories
include(HawaiiInstallDirs)

# Log features
include(MacroLogFeature)

# Add custom uninstall target
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)
add_custom_target(uninstall "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")

# Set up packaging
set(CPACK_PACKAGE_NAME hawaii-widget-styles)
set(CPACK_PACKAGE_VERSION ${WIDGETSTYLES_VERSION_STRING})
set(CPACK_SYSTEM_NAME "generic")
set(CPACK_GENERATOR "TGZ")
set(CPACK_SET_DESTDIR FALSE)
include(CPack)

# Build flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden -fvisibility-inlines-hidden -Wall -std=c++0x")

# Assume release build by default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "" FORCE)
endif()

# Disable debug output for release builds
if(CMAKE_BUILD_TYPE MATCHES "^[Rr]elease$")
    add_definitions(-DQT_NO_DEBUG_OUTPUT)
endif()

# Find Qt5 libraries
find_package(Qt5Widgets REQUIRED)
if(NOT Qt5Widgets_FOUND)
    message(FATAL_ERROR "Qt5Widgets module is required!")
endif()
macro_log_feature(Qt5Widgets_FOUND "Qt5Widgets" "Support for Qt5Widgets" "http://qt-project.org" "")

# Find Vibe libraries
find_package(VibeCore REQUIRED)
if(NOT VibeCore_FOUND)
    message(FATAL_ERROR "VibeCore module is required!")
endif()
macro_log_feature(VibeCore_FOUND "VibeCore" "Support for VibeCore" "http://www.maui-project.org" "")

# Find Fluid libraries
find_package(Fluid REQUIRED)
if(NOT Fluid_FOUND)
    message(FATAL_ERROR "Fluid module is required!")
endif()
macro_log_feature(Fluid_FOUND "Fluid" "Support for Fluid" "http://www.maui-project.org" "")

# Subdirectories
add_subdirectory(src)

# Display featute log
macro_display_feature_log()
