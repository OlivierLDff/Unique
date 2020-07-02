#
#   Unique CTest script
#
#   Copyright Olivier Le Doeuff 2019
#

# DEPENDENCIES

set(UNIQUE_TEST_TARGET ${UNIQUE_TESTS_PREFIX}_Tests)

set(UNIQUE_TEST_SRCS
        Tests.cpp
        IdProviderTests.cpp
        MapTests.cpp
    )

message(STATUS "Add Test: ${UNIQUE_TEST_TARGET}")

# Create the executable
add_executable(${UNIQUE_TEST_TARGET} ${UNIQUE_TEST_SRCS})
target_link_libraries(${UNIQUE_TEST_TARGET} ${UNIQUE_TARGET} gtest)
set_target_properties(${UNIQUE_TEST_TARGET} PROPERTIES FOLDER "${UNIQUE_FOLDER_PREFIX}/Tests")

if(MSVC)
    target_compile_definitions(${UNIQUE_TEST_TARGET} PRIVATE "-D_CRT_SECURE_NO_WARNINGS")
endif()

# Register the test
add_test(NAME ${UNIQUE_TEST_TARGET} COMMAND ${UNIQUE_TEST_TARGET})
