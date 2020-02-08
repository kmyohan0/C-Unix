CMAKE_MINIMUM_REQUIRED(VERSION 2.8.4)

project(RShell)

set(CMAKE_CXX_STANDARD 14)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.40 REQUIRED COMPONENTS filesystem)
message(STATUS "Boost version: ${Boost_VERSION}")

# This is needed if your Boost version is newer than your CMake version
# or if you have an old version of CMake (<3.5)
if(NOT TARGET Boost::filesystem)
    add_library(Boost::filesystem IMPORTED INTERFACE)
    set_property(TARGET Boost::filesystem PROPERTY
            INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR})
    set_property(TARGET Boost::filesystem PROPERTY
            INTERFACE_LINK_LIBRARIES ${Boost_LIBRARIES})
endif()

target_link_libraries(MyExeOrLibrary PUBLIC Boost::filesystem)

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

