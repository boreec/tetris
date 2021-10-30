cmake_minimum_required(VERSION 3.5)

project(Tetris LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS OpenGLWidgets REQUIRED)

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
	gui/RendererFacilities.cpp
	gui/RendererFacilities.hpp
	gui/RendererGame.cpp
	gui/RendererGame.hpp
	gui/RendererPreview.cpp
	gui/RendererPreview.hpp
)

target_link_libraries(Tetris PRIVATE Qt6::Widgets)
target_link_libraries(Tetris PRIVATE Qt6::OpenGLWidgets)

add_subdirectory(doc)

