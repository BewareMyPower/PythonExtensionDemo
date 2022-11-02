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

cmake_minimum_required(VERSION 3.18)

set(VCPKG_OVERLAY_TRIPLETS ${CMAKE_SOURCE_DIR}/triplets)
set(VCPKG_TARGET_TRIPLET x64-windows-static-boost)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")
project (boost-python-demo)

if (MSVC)
    set(CMAKE_SHARED_LIBRARY_SUFFIX .pyd)
endif ()

find_package(Python3 REQUIRED COMPONENTS Development.Module)
find_package(Boost REQUIRED COMPONENTS python310)

add_compile_definitions(BOOST_PYTHON_STATIC_LIB)
add_library(hello SHARED hello.cc)
target_link_libraries(hello PRIVATE
    Boost::python310
    Python3::Module
)
set_property(TARGET hello PROPERTY
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
