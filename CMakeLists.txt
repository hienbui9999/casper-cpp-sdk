cmake_minimum_required(VERSION 3.0)
project(CasperSDK VERSION 1.0.0)

enable_testing()

message("CasperSDK Version: ${CMAKE_PROJECT_VERSION}")

# Set C++17 as the default C++ standard
set(CMAKE_CXX_STANDARD 17)

# Set the include paths.
include_directories(
    src/include
    lib
    test/TestLibrary
)

# Set the CMake lists for the SDK and the SDK's dependencies
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(examples)

install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION /usr/lib/CasperSDK)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/include DESTINATION /usr/lib/CasperSDK)