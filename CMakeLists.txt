cmake_minimum_required(VERSION 3.23 FATAL_ERROR)
project(ProjectName VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include external libraries
include_directories(include/ExternalLibrary/include)

add_subdirectory(src)

# built manually from external library
find_library(VARNAME libraryname_without_libprefix libs)

target_link_libraries(ProjectName
  PRIVATE
    ${VARNAME}
  )

enable_testing()
add_subdirectory(tests)

