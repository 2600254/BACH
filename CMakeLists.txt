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

# Exclude Cypher module from basic build (requires additional dependencies)
list(FILTER srcs EXCLUDE REGEX ".*cypher/.*")

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

# ============================================================================
# Cypher Query Language Module (with ANTLR4) - Optional
# ============================================================================
option(BUILD_CYPHER "Build Cypher query language module" OFF)

if(BUILD_CYPHER)
    message(STATUS "Cypher module enabled - checking for ANTLR4...")

    # Find ANTLR4 runtime manually
    find_path(ANTLR4_INCLUDE_DIR antlr4-runtime.h
        PATHS /usr/include/antlr4-runtime
        NO_DEFAULT_PATH
    )
    find_library(ANTLR4_LIBRARY
        NAMES antlr4-runtime libantlr4-runtime
        PATHS /usr/lib/x86_64-linux-gnu
        NO_DEFAULT_PATH
    )

    if(ANTLR4_INCLUDE_DIR AND ANTLR4_LIBRARY)
        message(STATUS "ANTLR4 runtime found")
        message(STATUS "  Include: ${ANTLR4_INCLUDE_DIR}")
        message(STATUS "  Library: ${ANTLR4_LIBRARY}")

        # Add generated source files (if they exist)
        set(PARSER_GENERATED_DIR ${CMAKE_CURRENT_SOURCE_DIR}/parser/generated)

        # Check if parser files have been generated
        if(EXISTS ${PARSER_GENERATED_DIR}/CypherParser.h)
            message(STATUS "Using pre-generated ANTLR4 parser files")

            # Add generated source files
            file(GLOB PARSER_SOURCES
                ${PARSER_GENERATED_DIR}/*.cpp
            )

            # Add Cypher source files
            file(GLOB_RECURSE CYPER_SOURCES CONFIGURE_DEPENDS src/cypher/*.cpp)

            # Add parser and Cypher sources to the library
            target_sources(bach PRIVATE ${PARSER_SOURCES} ${CYPER_SOURCES})
            target_include_directories(bach PRIVATE ${PARSER_GENERATED_DIR} ${ANTLR4_INCLUDE_DIR})

            # Link ANTLR4 runtime
            target_link_libraries(bach PRIVATE ${ANTLR4_LIBRARY})

            # Define that Cypher module is enabled
            target_compile_definitions(bach PRIVATE BACH_ENABLE_CYPHER)

            # Cypher test executable
            add_executable(cypher_test src/cypher/tests/cypher_test.cpp)
            target_include_directories(cypher_test PRIVATE include include/dynamic_bitset/include include/folly ${ANTLR4_INCLUDE_DIR})
            target_link_libraries(cypher_test PRIVATE bach sul::dynamic_bitset folly ${ANTLR4_LIBRARY})

            # Cypher interactive test executable
            add_executable(cypher_interactive_test cypher_interactive_test.cpp)
            target_include_directories(cypher_interactive_test PRIVATE include include/dynamic_bitset/include include/folly ${ANTLR4_INCLUDE_DIR})
            target_link_libraries(cypher_interactive_test PRIVATE bach sul::dynamic_bitset folly ${ANTLR4_LIBRARY})

            # Cypher demo test executable
            add_executable(cypher_demo_test cypher_demo_test.cpp)
            target_include_directories(cypher_demo_test PRIVATE include include/dynamic_bitset/include include/folly ${ANTLR4_INCLUDE_DIR})
            target_link_libraries(cypher_demo_test PRIVATE bach sul::dynamic_bitset folly ${ANTLR4_LIBRARY})
            message(STATUS "Cypher test executables will be built")
        else()
            message(WARNING "ANTLR4 parser files not found in ${PARSER_GENERATED_DIR}")
            message(WARNING "Run 'cd grammar && ./generate.sh' to generate parser files")
            message(STATUS "Cypher module will be stub only")
        endif()
    else()
        message(WARNING "ANTLR4 runtime not found")
        message(WARNING "Install ANTLR4: sudo apt-get install libantlr4-runtime-dev")
        message(STATUS "Cypher module will be stub only")
    endif()
else()
    message(STATUS "Cypher module disabled (set -DBUILD_CYPHER=ON to enable)")
endif()

# ============================================================================
# Test Executables
# ============================================================================

# Example test executable
add_executable(example_test example_test.cpp)
target_include_directories(example_test PRIVATE include/dynamic_bitset/include)
target_include_directories(example_test PRIVATE include/folly)
target_link_libraries(example_test PRIVATE bach)

# Visualization test executable
add_executable(visualize_test visualize_test.cpp)
target_include_directories(visualize_test PRIVATE include/dynamic_bitset/include)
target_include_directories(visualize_test PRIVATE include/folly)
target_link_libraries(visualize_test PRIVATE bach)
