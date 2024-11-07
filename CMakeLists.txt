# Seongryul.park Minki.cho.
# Class Project
# CS225, Fall & 2022.

cmake_minimum_required(VERSION 3.11)
project(calculator)
include(FetchContent)

FetchContent_Declare(
    GSL
    GIT_REPOSITORY "https://github.com/microsoft/GSL"
    GIT_TAG "v4.0.0"
)

FetchContent_MakeAvailable(GSL)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Dependencies
set(RAYLIB_VERSION 4.2.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    SYSTEM
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()


#warning
add_library(project_warnings-calc INTERFACE)
include(CompilerWarnings.cmake)
set_project_warnings(project_warnings-calc)

# Our Project

add_executable(${PROJECT_NAME} main.cpp CalcWindow.cpp ButtonManager.cpp Button.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_link_libraries(${PROJECT_NAME} PRIVATE project_warnings-calc)
target_link_libraries(${PROJECT_NAME} PRIVATE GSL)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

