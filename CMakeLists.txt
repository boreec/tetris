cmake_minimum_required(VERSION 3.5)

project(Tetris LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()
find_package(OpenGL)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS OpenGL REQUIRED)

if(ANDROID)
  add_library(Tetris SHARED
    main.cpp
    core/Board.cpp
    core/Board.hpp
    core/Tetromino.cpp
    core/Tetromino.hpp
    core/TetrominoFactory.cpp
    core/TetrominoFactory.hpp
    core/Tetromino_I.cpp
    core/Tetromino_I.hpp
    core/Tetromino_J.cpp
    core/Tetromino_J.hpp
    core/Tetromino_L.cpp
    core/Tetromino_L.hpp
    core/Tetromino_O.cpp
    core/Tetromino_O.hpp
    core/Tetromino_S.cpp
    core/Tetromino_S.hpp
    core/Tetromino_T.cpp
    core/Tetromino_T.hpp
    core/Tetromino_Z.cpp
    core/Tetromino_Z.hpp
    gui/MainWindow.cpp
    gui/MainWindow.hpp
    gui/RendererGame.cpp
    gui/RendererGame.hpp
    gui/RendererPreview.cpp
    gui/RendererPreview.hpp
  )
else()
  add_executable(Tetris
    main.cpp
    core/Board.cpp
    core/Board.hpp
    core/Tetromino.cpp
    core/Tetromino.hpp
    core/TetrominoFactory.cpp
    core/TetrominoFactory.hpp
    core/Tetromino_I.cpp
    core/Tetromino_I.hpp
    core/Tetromino_J.cpp
    core/Tetromino_J.hpp
    core/Tetromino_L.cpp
    core/Tetromino_L.hpp
    core/Tetromino_O.cpp
    core/Tetromino_O.hpp
    core/Tetromino_S.cpp
    core/Tetromino_S.hpp
    core/Tetromino_T.cpp
    core/Tetromino_T.hpp
    core/Tetromino_Z.cpp
    core/Tetromino_Z.hpp
    gui/MainWindow.cpp
    gui/MainWindow.hpp
    gui/RendererGame.cpp
    gui/RendererGame.hpp
    gui/RendererPreview.cpp
    gui/RendererPreview.hpp
  )
endif()

target_link_libraries(Tetris PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Tetris PRIVATE Qt${QT_VERSION_MAJOR}::OpenGL)
target_link_libraries(Tetris PRIVATE OpenGL)
