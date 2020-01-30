CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project(RShell)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        test
        prototype/main_prototype.cpp
        prototype/parser.cpp
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