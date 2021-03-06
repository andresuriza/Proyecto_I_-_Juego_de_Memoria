cmake_minimum_required(VERSION 3.5)

project(Proyecto_I_UI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Network REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Network REQUIRED)

set(PROJECT_SOURCES
        Client.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        Game_logic.cpp
        dialog.cpp
        dialog.h
        dialog.ui
        )

set(SERVER_SOURCES
        Server.cpp
        Server_main.cpp
        serverwindow.h
        serverwindow.cpp
        serverwindow.ui
        )


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Proyecto_I_UI
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES})

    qt_add_executable(server
            MANUAL_FINALIZATION
            ${SERVER_SOURCES})
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET Proyecto_I APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Proyecto_I_UI SHARED
                ${PROJECT_SOURCES}
                )
        # Define properties for Android with Qt 5 after find_package() calls as:
        #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Proyecto_I_UI
                ${PROJECT_SOURCES}
                )
        add_executable(server
                ${SERVER_SOURCES})
    endif()
endif()

target_link_libraries(Proyecto_I_UI PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(server PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Proyecto_I_UI PRIVATE Qt${QT_VERSION_MAJOR}::Network)
target_link_libraries(server PRIVATE Qt${QT_VERSION_MAJOR}::Network)

set_target_properties(Proyecto_I_UI PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
        )

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Proyecto_I_UI)
endif()
