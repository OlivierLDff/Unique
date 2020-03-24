#
#   Unique CMake build script
#
#   Copyright Olivier Le Doeuff 2019
#

# ┌──────────────────────────────────────────────────────────────────┐
# │                       CMAKE PROPERTIES                           │
# └──────────────────────────────────────────────────────────────────┘

cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# ┌──────────────────────────────────────────────────────────────────┐
# │                       PROJECT SETTINGS                           │
# └──────────────────────────────────────────────────────────────────┘

# OPTIONS

set(UNIQUE_VERSION_MAJOR 1)
set(UNIQUE_VERSION_MINOR 0)
set(UNIQUE_VERSION_PATCH 0)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.git")
    EXECUTE_PROCESS(
        COMMAND git describe --always
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        OUTPUT_VARIABLE UNIQUE_VERSION_TAG
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
endif()
if(NOT UNIQUE_VERSION_TAG)
    set(UNIQUE_VERSION_TAG 00000000)
endif(NOT UNIQUE_VERSION_TAG)
set(UNIQUE_VERSION_TAG_HEX 0x${UNIQUE_VERSION_TAG})
set(UNIQUE_VERSION ${UNIQUE_VERSION_MAJOR}.${UNIQUE_VERSION_MINOR}.${UNIQUE_VERSION_PATCH} CACHE STRING "" FORCE)

# General
set(UNIQUE_PROJECT "Unique" CACHE STRING "Project Name")
set(UNIQUE_TARGET ${UNIQUE_PROJECT} CACHE STRING "Unique library name")
set(UNIQUE_VERSION ${UNIQUE_VERSION_MAJOR}.${UNIQUE_VERSION_MINOR}.${UNIQUE_VERSION_PATCH} CACHE STRING "Unique current version, this is only decorative and will not configure any files" FORCE)

set(UNIQUE_FOLDER_PREFIX ${UNIQUE_PROJECT} CACHE STRING "Prefix folder for all Unique generated targets in generated project (only decorative)")

# Tests
set(UNIQUE_ENABLE_TESTS ON CACHE BOOL "Create or not a target for test (compatible with CTests)")
set(UNIQUE_TESTS_PREFIX ${UNIQUE_PROJECT} CACHE STRING "Prefix for all Unique tests")

# CREATE PROJECT

project(${UNIQUE_PROJECT} VERSION ${UNIQUE_VERSION} LANGUAGES C CXX)

# LOG OPTIONS

message(STATUS "---------------- UNIQUE OPTIONS. ----------------")

#General
message(STATUS "UNIQUE_PROJECT            : " ${UNIQUE_PROJECT})
message(STATUS "UNIQUE_TARGET             : " ${UNIQUE_TARGET})
message(STATUS "UNIQUE_VERSION            : " ${UNIQUE_VERSION})
message(STATUS "UNIQUE_VERSION_TAG        : " ${UNIQUE_VERSION_TAG})

# Tests
message(STATUS "UNIQUE_ENABLE_TESTS       : " ${UNIQUE_ENABLE_TESTS})
if(UNIQUE_ENABLE_TESTS)
message(STATUS "UNIQUE_TESTS_PREFIX       : " ${UNIQUE_TESTS_PREFIX})
endif() # UNIQUE_ENABLE_TESTS

message(STATUS "---------------- DONE WITH OPTIONS. -----------------")

# ┌──────────────────────────────────────────────────────────────────┐
# │                          UNIQUE                              │
# └──────────────────────────────────────────────────────────────────┘

set(UNIQUE_INCS_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(UNIQUE_PRIVATE_INCS_FOLDER ${UNIQUE_INCS_FOLDER}/Unique)

set(UNIQUE_UTILS_INCS
    ${UNIQUE_PRIVATE_INCS_FOLDER}/Unique.hpp
)

set(UNIQUE_API_INCS
    ${UNIQUE_PRIVATE_INCS_FOLDER}/TMap.hpp
    ${UNIQUE_PRIVATE_INCS_FOLDER}/UnorderedMap.hpp
    ${UNIQUE_PRIVATE_INCS_FOLDER}/Map.hpp
    ${UNIQUE_PRIVATE_INCS_FOLDER}/IdProvider.hpp
)

set(UNIQUE_INCS
    ${UNIQUE_UTILS_INCS}
    ${UNIQUE_API_INCS}
)

source_group("Utils" FILES ${UNIQUE_UTILS_INCS})
source_group("Api" FILES ${UNIQUE_API_INCS})

# UNIQUE TARGET
add_library(${UNIQUE_TARGET} INTERFACE)
target_compile_features(${UNIQUE_TARGET} INTERFACE cxx_std_14)

foreach(SRC_FILE ${UNIQUE_INCS})
    target_sources(${UNIQUE_TARGET} INTERFACE ${SRC_FILE})
endforeach()

target_include_directories(${UNIQUE_TARGET} INTERFACE ${UNIQUE_INCS_FOLDER})

# ┌──────────────────────────────────────────────────────────────────┐
# │                           TESTS                                  │
# └──────────────────────────────────────────────────────────────────┘

if(UNIQUE_ENABLE_TESTS)
    include(${CMAKE_CURRENT_SOURCE_DIR}/CTestLists.txt)
endif() # UNIQUE_ENABLE_TESTS