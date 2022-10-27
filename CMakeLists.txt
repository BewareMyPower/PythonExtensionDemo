cmake_minimum_required (VERSION 3.12)

project ("CMakePythonExtension" C)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(PythonLibs REQUIRED)
message(STATUS "PYTHON_INCLUDE_DIRS: " ${PYTHON_INCLUDE_DIRS})
message(STATUS "PYTHON_LIBRARIES: " ${PYTHON_LIBRARIES})

if (NOT PYTHON_VERSION)
    set(PYTHON_VERSION 3.10)
endif ()

include_directories(
    ${PYTHON_INCLUDE_DIRS}
    ${PYTHON_INCLUDE_DIRS}/${PYTHON_VERSION}
)

set(CMAKE_SHARED_LIBRARY_SUFFIX ".pyd")

add_library(xyz SHARED module.c)
target_link_libraries(xyz ${PYTHON_LIBRARIES})
