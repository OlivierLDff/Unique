#
#   Unique CMake build script
#
#   Copyright Olivier Le Doeuff 2019
#

# ┌──────────────────────────────────────────────────────────────────┐
# │                       CMAKE PROPERTIES                           │
# └──────────────────────────────────────────────────────────────────┘

cmake_minimum_required( VERSION 3.11 FATAL_ERROR )

# DEPENDENCIES

set( GTEST_REPOSITORY "https://github.com/google/googletest" CACHE STRING "Repository of googletest" )
set( GTEST_TAG "master" CACHE STRING "Git tag/branch of googletest" )

# ┌──────────────────────────────────────────────────────────────────┐
# │                       PROJECT SETTINGS                           │
# └──────────────────────────────────────────────────────────────────┘

# OPTIONS

set(UNIQUE_VERSION_MAJOR 1)
set(UNIQUE_VERSION_MINOR 0)
set(UNIQUE_VERSION_PATCH 0)
if( EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.git" )
    EXECUTE_PROCESS(
        COMMAND git describe --always
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        OUTPUT_VARIABLE UNIQUE_VERSION_TAG
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
endif()
if(NOT UNIQUE_VERSION_TAG)
    set( UNIQUE_VERSION_TAG 00000000 )
endif(NOT UNIQUE_VERSION_TAG)
set( UNIQUE_VERSION_TAG_HEX 0x${UNIQUE_VERSION_TAG})
set( UNIQUE_VERSION ${UNIQUE_VERSION_MAJOR}.${UNIQUE_VERSION_MINOR}.${UNIQUE_VERSION_PATCH} CACHE STRING "" FORCE )

# General
set( UNIQUE_PROJECT "Unique" CACHE STRING "Project Name")
set( UNIQUE_TARGET ${UNIQUE_PROJECT} CACHE STRING "Unique library name" )
set( UNIQUE_VERSION ${UNIQUE_VERSION_MAJOR}.${UNIQUE_VERSION_MINOR}.${UNIQUE_VERSION_PATCH} CACHE STRING "Unique current version, this is only decorative and will not configure any files" FORCE )

set( UNIQUE_BUILD_SHARED OFF CACHE BOOL "Build as a shared library (ON) or as static (OFF)" )
set( UNIQUE_FOLDER_PREFIX ${UNIQUE_PROJECT} CACHE STRING "Prefix folder for all Unique generated targets in generated project (only decorative)" )

set( UNIQUE_USE_NAMESPACE ON CACHE BOOL "Should we use namespace" )
set( UNIQUE_NAMESPACE ${UNIQUE_PROJECT} CACHE STRING "Namespace for the library" )

# Tests
set( UNIQUE_ENABLE_TESTS ON CACHE BOOL "Create or not a target for test (compatible with CTests)" )
set( UNIQUE_TESTS_PREFIX ${UNIQUE_PROJECT} CACHE STRING "Prefix for all Unique tests" )

# Install
set( UNIQUE_ENABLE_INSTALL OFF CACHE BOOL "Create or not a target for install" )
set( UNIQUE_INSTALL_PREFIX ${UNIQUE_PROJECT} CACHE STRING "Prefix for all Unique headers in the install folder" )

# CREATE PROJECT

project( ${UNIQUE_PROJECT} VERSION ${UNIQUE_VERSION} LANGUAGES C CXX )
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set( CMAKE_CXX_STANDARD 14 )

# LOG OPTIONS

message(STATUS "---------------- UNIQUE OPTIONS. ----------------")

#General
message(STATUS "UNIQUE_PROJECT            : " ${UNIQUE_PROJECT})
message(STATUS "UNIQUE_TARGET             : " ${UNIQUE_TARGET})
message(STATUS "UNIQUE_VERSION            : " ${UNIQUE_VERSION})
message(STATUS "UNIQUE_VERSION_TAG        : " ${UNIQUE_VERSION_TAG})
message(STATUS "UNIQUE_BUILD_SHARED       : " ${UNIQUE_BUILD_SHARED})
message(STATUS "UNIQUE_FOLDER_PREFIX      : " ${UNIQUE_FOLDER_PREFIX})

# Tests
message(STATUS "UNIQUE_ENABLE_TESTS       : " ${UNIQUE_ENABLE_TESTS})
if(UNIQUE_ENABLE_TESTS)
message(STATUS "UNIQUE_TESTS_PREFIX       : " ${UNIQUE_TESTS_PREFIX})
endif() # UNIQUE_ENABLE_TESTS

# Install
message(STATUS "UNIQUE_ENABLE_INSTALL     : " ${UNIQUE_ENABLE_INSTALL})
if(UNIQUE_ENABLE_INSTALL)
message(STATUS "UNIQUE_INSTALL_PREFIX     : " ${UNIQUE_INSTALL_PREFIX})
endif() # UNIQUE_ENABLE_INSTALL

message(STATUS "---------------- DONE WITH OPTIONS. -----------------")

# ┌──────────────────────────────────────────────────────────────────┐
# │                       DEPENDENCIES                               │
# └──────────────────────────────────────────────────────────────────┘

include(FetchContent)

# googletest
FetchContent_Declare(
    googletest
    GIT_REPOSITORY ${GTEST_REPOSITORY}
    GIT_TAG        ${GTEST_TAG}
)

set(FETCHCONTENT_UPDATES_DISCONNECTED ON)
set(FETCHCONTENT_QUIET ON)

# ┌──────────────────────────────────────────────────────────────────┐
# │                          UNIQUE                              │
# └──────────────────────────────────────────────────────────────────┘

set(UNIQUE_SRCS_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(UNIQUE_INCS_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/src/include)
set(UNIQUE_PRIVATE_INCS_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/src/include/Unique)

# UNIQUE SOURCES
set(UNIQUE_UTILS_SRCS
    ${UNIQUE_SRCS_FOLDER}/Version.cpp
)

set(UNIQUE_API_SRCS
)

set(UNIQUE_SRCS
    ${UNIQUE_UTILS_SRCS}
    ${UNIQUE_API_SRCS}
)

set(UNIQUE_UTILS_INCS
    ${UNIQUE_INCS_FOLDER}/Unique.hpp
    ${UNIQUE_PRIVATE_INCS_FOLDER}/Export.hpp
    ${UNIQUE_PRIVATE_INCS_FOLDER}/Version.hpp
)

set(UNIQUE_API_INCS
    ${UNIQUE_PRIVATE_INCS_FOLDER}/Map.hpp
    ${UNIQUE_PRIVATE_INCS_FOLDER}/IdProvider.hpp
)

set(UNIQUE_INCS
    ${UNIQUE_UTILS_INCS}
    ${UNIQUE_API_INCS}
)

source_group("Utils" FILES ${UNIQUE_UTILS_INCS})
source_group("Api" FILES ${UNIQUE_API_INCS})

source_group("Utils" FILES ${UNIQUE_UTILS_SRCS})
source_group("Api" FILES ${UNIQUE_API_SRCS})

# UNIQUE TARGET
if(UNIQUE_BUILD_SHARED)

    add_library(${UNIQUE_TARGET} SHARED ${UNIQUE_SRCS} ${UNIQUE_INCS})
    target_compile_definitions(${UNIQUE_TARGET} PRIVATE "-DUNIQUE_DLL_EXPORT")

else() # UNIQUE_BUILD_SHARED

    add_library(${UNIQUE_TARGET} STATIC  ${UNIQUE_SRCS} ${UNIQUE_INCS})
    target_compile_definitions(${UNIQUE_TARGET} PUBLIC "-DUNIQUE_STATIC")

endif() # UNIQUE_BUILD_SHARED

# Set include directory
target_include_directories(${UNIQUE_TARGET} PUBLIC $<BUILD_INTERFACE:${UNIQUE_INCS_FOLDER}> $<INSTALL_INTERFACE:${UNIQUE_INSTALL_PREFIX}>)

# Avoid libUnique on darwin for example.
set_target_properties(${UNIQUE_TARGET} PROPERTIES PREFIX "")

# Link libraries

set_target_properties(${UNIQUE_TARGET} PROPERTIES FOLDER ${UNIQUE_FOLDER_PREFIX})

# Version
target_compile_definitions( ${UNIQUE_TARGET} PRIVATE -DUNIQUE_VERSION_MAJOR=${UNIQUE_VERSION_MAJOR} )
target_compile_definitions( ${UNIQUE_TARGET} PRIVATE -DUNIQUE_VERSION_MINOR=${UNIQUE_VERSION_MINOR} )
target_compile_definitions( ${UNIQUE_TARGET} PRIVATE -DUNIQUE_VERSION_PATCH=${UNIQUE_VERSION_PATCH} )
target_compile_definitions( ${UNIQUE_TARGET} PRIVATE -DUNIQUE_VERSION_TAG=${UNIQUE_VERSION_TAG} )
target_compile_definitions( ${UNIQUE_TARGET} PRIVATE -DUNIQUE_VERSION_TAG_HEX=${UNIQUE_VERSION_TAG_HEX} )

if(UNIQUE_USE_NAMESPACE)
    target_compile_definitions( ${UNIQUE_TARGET} PUBLIC -DUNIQUE_USE_NAMESPACE )
    target_compile_definitions( ${UNIQUE_TARGET} PUBLIC -DUNIQUE_NAMESPACE=${UNIQUE_NAMESPACE} )
endif() # UNIQUE_USE_NAMESPACE

# ┌──────────────────────────────────────────────────────────────────┐
# │                           TESTS                                  │
# └──────────────────────────────────────────────────────────────────┘

if(UNIQUE_ENABLE_TESTS)
    include(${CMAKE_CURRENT_SOURCE_DIR}/CTestLists.txt)
endif() # UNIQUE_ENABLE_TESTS

# ┌──────────────────────────────────────────────────────────────────┐
# │                         INSTALL                                  │
# └──────────────────────────────────────────────────────────────────┘

if(UNIQUE_ENABLE_INSTALL)
    include(${CMAKE_CURRENT_SOURCE_DIR}/CInstallLists.txt)
endif() # UNIQUE_ENABLE_INSTALL
