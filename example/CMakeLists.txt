cmake_minimum_required(VERSION 3.21)

project(libmem-example LANGUAGES CXX)

# Add libmem-cmake to CMAKE_PREFIX_PATH, which is used by find_package to search for packages config files
# In your project, replace "../" with the "path/to/libmem-cmake" (containing libmem-config.cmake)
set(CMAKE_PREFIX_PATH "../" "${CMAKE_PREFIX_PATH}")

# Find dependencies
set(LIBMEM_DOWNLOAD_VERSION "4.4.0-pre1")
find_package(libmem CONFIG REQUIRED)

# Find sources
set(EXAMPLE_INCLUDE_DIRS src)
set(EXAMPLE_SOURCES
    src/main.hpp
    src/main.cpp
)

# Define target
add_executable(libmem-example "${EXAMPLE_SOURCES}")

target_compile_features(libmem-example PUBLIC cxx_std_17)
if (NOT MSVC)
  target_compile_options(libmem-example PRIVATE "$<$<CONFIG:Debug>:-Wall;-Werror>")
  target_compile_options(libmem-example PUBLIC "$<$<CONFIG:Debug>:-ggdb;-O0>")
endif ()

target_include_directories(libmem-example PRIVATE "${EXAMPLE_INCLUDE_DIRS}")
target_link_libraries(libmem-example PRIVATE libmem::libmem)
