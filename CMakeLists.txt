CMAKE_MINIMUM_REQUIRED(VERSION 2.8.4)

ADD_SUBDIRECTORY(googletest)

set(CMAKE_CXX_STANDARD 14)

project(RShell)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.41.0 COMPONENTS filesystem regex)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(main src/main.cpp src/Parser.cpp src/andToken.cpp src/orToken.cpp  src/quitToken.cpp src/nextToken.cpp src/executable.cpp)
    target_link_libraries(main ${Boost_LIBRARIES})
endif()

add_executable(
        parser_unit_test
        unit_tests/parser_test.cpp
        src/Parser.cpp
)

ADD_EXECUTABLE(integration_testing
        integration_tests/integration_tokens_test src/andToken.cpp src/nextToken.cpp src/orToken.cpp src/quitToken.cpp header/testToken.h
        )

TARGET_LINK_LIBRARIES(integration_testing gtest)
TARGET_COMPILE_DEFINITIONS(integration_testing PRIVATE gtest_disable_pthreads=ON)

#TARGET_LINK_LIBRARIES(parser_unit_test gtest)
#TARGET_COMPILE_DEFINITIONS(parser_unit_test PRIVATE gtest_disable_pthreads=ON)

add_executable(
        test
        prototype/main_prototype.cpp
        prototype/parser_prototype.cpp
)

add_executable(
        fork_test
        prototype/fork_prototype.cpp
)

add_executable(
        waitpid_test
        prototype/waitpid_prototype.cpp
)

add_executable(
        execvp_test
        prototype/execvp_prototype.cpp
)

add_executable(
        all_together_test
        prototype/function_prototype.cpp
)

