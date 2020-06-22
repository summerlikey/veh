#版本
cmake_minimum_required(VERSION 3.0)

project(veh3)


set(CMAKE_BUILD_TYPE Debug)
set(veh "3.0")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
# boost
find_package(Boost REQUIRED COMPONENTS
        program_options
        filesystem
        graph
        regex
        system
        unit_test_framework)

set(THIRD_PARTY_LIBS
        ${OpenCV_LIBS}
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_PROGRAM_OPTIONS_LIBRARY}
        ${Boost_REGEX_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
)

set(THIRD_INCLUDE_DIRS
        ${OpenCV_INCLUDE_DIRS}
        ${Boost_INCLUDE_DIRS}
)


set(INTERNAL_INCLUDE
        ${PROJECT_SOURCE_DIR}/include)

set(INTERNAL_LIB

)

enable_testing()

############### source and test ######################

include_directories(
        ${PROJECT_SOURCE_DIR}/src
        ${INTERNAL_INCLUDE}
        ${THIRD_INCLUDE_DIRS})

link_libraries(${INTERNAL_LIB})

add_subdirectory(src)
add_subdirectory(test)
