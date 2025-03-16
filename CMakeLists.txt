cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

SET(CMAKE_C_COMPILER "gcc-12")
SET(CMAKE_CXX_COMPILER "g++-12")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

project ("BACH_demo" LANGUAGES CXX)

include_directories(${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp)

add_library(bach SHARED bind/BACH.cpp ${srcs})
target_include_directories(bach PUBLIC include)
target_compile_features(bach PUBLIC cxx_std_20)

add_subdirectory(include/dynamic_bitset)
target_link_libraries(bach PRIVATE sul::dynamic_bitset)
add_subdirectory(include/folly)
target_link_libraries(bach PRIVATE folly)

set(DEBUG OFF)

set(CMAKE_CXX_FLAGS "-O3 ${CMAKE_CXX_FLAGS}")

if(DEBUG)
	set(CMAKE_CXX_FLAGS " -Wall ${CMAKE_CXX_FLAGS}")
	target_link_options(bach PRIVATE -lprofiler -ltcmalloc)
endif()

