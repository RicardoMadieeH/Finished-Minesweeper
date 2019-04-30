cmake_minimum_required(VERSION 3.13)
project(Suffering)

set(CMAKE_CXX_STANDARD 14)

add_executable(Suffering main.cpp Button.cpp Button.h GameManager.cpp GameManager.h IntroController.cpp IntroController.h 
IntroView.cpp IntroView.h MinesweeperBoard.cpp MinesweeperBoard.h MinesweeperController.cpp MinesweeperController.h 
MinesweeperView.cpp MinesweeperView.h ScoreController.cpp ScoreController.h ScoreView.cpp ScoreView.h Textbox.cpp Textbox.h)

# Detect and add SFML
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Suffering ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()
