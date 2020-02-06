CMAKE_MINIMUM_REQUIRED(VERSION 2.8.4)

project(RShell)

set(CMAKE_CXX_STANDARD 14)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(main src/main.cpp src/Parser.cpp)
    target_link_libraries(program ${Boost_LIBRARIES})
endif()

add_executable(
        main
        src/main.cpp
        src/Parser.cpp
)

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

