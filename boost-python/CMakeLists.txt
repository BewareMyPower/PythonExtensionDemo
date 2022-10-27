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

project (boost-python-demo)
cmake_minimum_required(VERSION 3.12)

if (MSVC)
    SET(CMAKE_SHARED_LIBRARY_SUFFIX .pyd)
    string(REGEX REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE})
    add_definitions(-DBOOST_PYTHON_STATIC_LIB)
endif ()

find_package (Python3 REQUIRED COMPONENTS Development)
message(STATUS "PYTHON: " ${Python3_VERSION} " - " ${Python3_INCLUDE_DIRS})
message(STATUS "Python3_LIBRARIES: " ${Python3_LIBRARIES})

#set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS python38)
message(STATUS "Boost_INCLUDE_DIRS: " ${Boost_INCLUDE_DIRS})
message(STATUS "Boost_PYTHON38_LIBRARIES: " ${Boost_PYTHON38_LIBRARIES})

add_library(hello SHARED hello.cc)
include_directories(
    ${Python3_INCLUDE_DIRS}
)
target_link_libraries(hello PRIVATE
    ${Boost_PYTHON38_LIBRARIES}
    ${Python3_LIBRARIES}
)
