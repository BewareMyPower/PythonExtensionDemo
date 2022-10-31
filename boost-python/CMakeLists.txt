#
# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.
#

cmake_minimum_required(VERSION 3.15)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")
project (boost-python-demo)

if (MSVC)
    SET(CMAKE_SHARED_LIBRARY_SUFFIX .pyd)
endif ()

find_package(Python3 REQUIRED COMPONENTS Development)

set(BOOST_PYTHON_NAME_LIST python3 python310 python39 python38 python37)
foreach (BOOST_PYTHON_NAME IN LISTS BOOST_PYTHON_NAME_LIST)
    find_package(Boost QUIET COMPONENTS ${BOOST_PYTHON_NAME})
    if (${Boost_FOUND})
        set(BOOST_PYTHON_NAME_FOUND ${BOOST_PYTHON_NAME})
        message(STATUS "Found Boost COMPONENTS " ${BOOST_PYTHON_NAME_FOUND})
        break ()
    endif ()
endforeach ()
if (NOT BOOST_PYTHON_NAME_FOUND)
    message(FATAL_ERROR "Could not find Boost Python library")
endif ()
find_package(Boost REQUIRED COMPONENTS ${BOOST_PYTHON_NAME_FOUND})

add_library(hello SHARED hello.cc)
target_link_libraries(hello PRIVATE
    Boost::${BOOST_PYTHON_NAME_FOUND}
    Python3::Module
)
