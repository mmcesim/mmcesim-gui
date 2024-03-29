cmake_minimum_required(VERSION 3.5)

project(mmcesim-gui VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
    resources/icon.qrc
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

set(MACOSX_BUNDLE_ICON_FILE mmCEsim.icns)
set(app_icon_macos "${CMAKE_CURRENT_SOURCE_DIR}/resources/fig/logo/mmCEsim.icns")
set_source_files_properties(${app_icon_macos} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(mmcesim-gui
        MACOSX_BUNDLE
        ${app_icon_macos}
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET mmcesim-gui APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(mmcesim-gui SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(mmcesim-gui
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(mmcesim-gui PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(mmcesim-gui PROPERTIES
    MACOSX_BUNDLE_BUNDLE_NAME mmCEsim
    MACOSX_BUNDLE_GUI_IDENTIFIER mmcesim.org
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(mmcesim-gui)
endif()
