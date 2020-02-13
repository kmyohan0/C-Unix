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

ADD_EXECUTABLE(
        parser_unit_test
        unit_tests/parser_test.cpp
)

TARGET_LINK_LIBRARIES(parser_unit_test gtest)
TARGET_COMPILE_DEFINITIONS(parser_unit_test PRIVATE gtest_disable_pthreads=ON)