cmake_minimum_required(VERSION 3.0)
project(indie_studio)

include(modules/FindIrrlicht.cmake)

message(status "Lib: ${Irrlicht_LIBRARIES}")

set(CMAKE_CXX_STANDARD 11)

set(SRCS_PATH src
            src/graphics
            src/utils
            src/game_components
	    src/ui/gui
	    src/ui/menu)

include_directories(inc)

foreach(PATH IN LISTS SRCS_PATH)
    AUX_SOURCE_DIRECTORY(${PATH} SRCS)
endforeach()



message("${CMAKE_SOURCE_DIR}")

add_compile_options(-g3 -D PROJECT_DIR="${CMAKE_SOURCE_DIR}")
add_executable(bomberman ${SRCS})
target_include_directories(bomberman PRIVATE ${Irrlicht_INCLUDE_DIRS})
target_link_libraries(bomberman ${Irrlicht_LIBRARIES})
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.5 COMPONENTS audio REQUIRED)
if(SFML_FOUND)
    message("${SFML_LIBRARIES}")
  include_directories(${SFML_INCLUDE_DIR}/Audio)
  target_link_libraries(bomberman sfml-audio)
endif()
