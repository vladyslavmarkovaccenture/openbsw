# This file is to be included into an application CMakeLists.txt to use OpenBSW.
# The variable OPENBSW_DIR should be set to the location of the OpenBSW root and
# OPENBSW_APP_DIR to the root of the application sources.

cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

if (CMAKE_CXX_STANDARD AND NOT ${CMAKE_CXX_STANDARD} EQUAL 14)
    message(WARNING "Using custom CXX standard (C++${CMAKE_CXX_STANDARD})")
else ()
    set(CMAKE_CXX_STANDARD 14)
endif ()

if (CMAKE_C_STANDARD AND NOT ${CMAKE_C_STANDARD} EQUAL 99)
    message(WARNING "Using custom C standard (C${CMAKE_C_STANDARD})")
else ()
    set(CMAKE_C_STANDARD 99)
endif ()

set(BUILD_TARGET_PLATFORM
    "POSIX"
    CACHE STRING "Target Platform")

# Convert target name to lower case to match directory name
string(TOLOWER "${BUILD_TARGET_PLATFORM}" OPENBSW_TARGET)
include(executables/referenceApp/platforms/${OPENBSW_TARGET}/Options.cmake)

message(STATUS "Target platform: <${BUILD_TARGET_PLATFORM}>")

# Set preprocessor defines based on cmake options by the same name to configure
# platform features.
get_cmake_property(_all_vars VARIABLES)
foreach (var ${_all_vars})
    if (var MATCHES "^PLATFORM_SUPPORT_")
        if (${var})
            add_compile_definitions(${var}=1)
            message(STATUS "${var} ON")
        endif ()
    endif ()
endforeach ()

project(
    "Eclipse OpenBSW"
    VERSION 0.1.0
    DESCRIPTION
        "BSW workspace with reference application for multiple platforms"
    LANGUAGES CXX C ASM)

list(APPEND CMAKE_MODULE_PATH "admin/cmake")

option(BUILD_UNIT_TESTS "Build unit tests" OFF)

option(BUILD_TRACING "Build CTF tracing" OFF)

add_compile_options(
    "$<$<COMPILE_LANG_AND_ID:CXX,Clang,GNU>:-O2;-g3;-Werror;-Wall;-Wextra;-Wvla;-Wno-deprecated-volatile>"
    # todo: enforce -Wunused-parameter
    "$<$<COMPILE_LANG_AND_ID:CXX,Clang,GNU>:-Wno-error=unused-parameter>"
    # note: the below warnings are often false positive
    "$<$<COMPILE_LANG_AND_ID:CXX,GNU>:-Wno-error=stringop-overflow;-Wno-error=maybe-uninitialized>"
)

add_compile_options(
    "$<$<COMPILE_LANG_AND_ID:C,Clang,GNU>:-O2;-g3;-Werror;-Wall;-Wextra>")

add_link_options(-Wl,--noinhibit-exec)

if (BUILD_UNIT_TESTS)
    add_compile_definitions(UNIT_TEST=1)
    include(GoogleTest)
    include(CTest)
    include(CodeCoverage)
    append_coverage_compiler_flags()
    enable_testing()
endif ()

if (BUILD_TRACING)
    add_compile_definitions(TRACING=1)
    if (TRACING_BUFFER_SIZE)
        add_compile_definitions(TRACING_BUFFER_SIZE=${TRACING_BUFFER_SIZE})
    endif ()
endif ()

set(INCLUDE_OPENBSW_LIBS_BSP
    ON
    CACHE BOOL "Include openbsw/libs/bsp/ in build")

add_subdirectory(platforms EXCLUDE_FROM_ALL)
add_subdirectory(libs EXCLUDE_FROM_ALL)

if (BUILD_UNIT_TESTS)
    add_subdirectory(libs/bsw/async/test/gtest)
    add_subdirectory(libs/bsw/asyncConsole/test/gtest)
    add_subdirectory(libs/bsw/asyncFreeRtos/test/gtest)
    add_subdirectory(libs/bsw/asyncImpl/examples)
    add_subdirectory(libs/bsw/asyncImpl/test/gtest)
    add_subdirectory(libs/bsw/bsp/test/gtest)
    add_subdirectory(libs/bsw/cpp2can/test/gtest)
    add_subdirectory(libs/bsw/docan/test/gtest)
    add_subdirectory(libs/bsw/estd/examples)
    add_subdirectory(libs/bsw/estd/test/gtest)
    add_subdirectory(libs/bsw/io/examples)
    add_subdirectory(libs/bsw/io/test)
    add_subdirectory(libs/bsw/lifecycle/examples)
    add_subdirectory(libs/bsw/lifecycle/test/gtest)
    add_subdirectory(libs/bsw/logger/test)
    add_subdirectory(libs/bsw/platform/test/gtest)
    add_subdirectory(libs/bsw/runtime/test/gtest)
    add_subdirectory(libs/bsw/timer/test/gtest)
    add_subdirectory(libs/bsw/transport/test/gtest)
    add_subdirectory(libs/bsw/uds/test/gtest)
    add_subdirectory(libs/bsw/util/test/gtest)

    add_subdirectory(libs/bsp/bspInputManager/test/gtest)
    add_subdirectory(libs/bsp/bspCharInputOutput/test/gtest)
    add_subdirectory(libs/bsp/bspDynamicClient/test/gtest)
    add_subdirectory(libs/bsp/bspInterrupts/test/gtest)
    add_subdirectory(libs/bsp/bspOutputManager/test/gtest)
    add_subdirectory(libs/bsp/bspOutputPwm/test/gtest)

    add_subdirectory(libs/safety/safeLifecycle/test/gtest)
    add_subdirectory(libs/safety/safeMonitor/test)

    add_subdirectory(platforms/posix/bsp/socketCanTransceiver)
    add_subdirectory(platforms/posix/bsp/socketCanTransceiver/test/gtest)
    add_subdirectory(platforms/s32k1xx/bsp/bspCore/test/gtest)
    add_subdirectory(platforms/s32k1xx/bsp/bspIo/test/gtest)
    add_subdirectory(platforms/s32k1xx/bsp/bspSci/test/gtest)
    add_subdirectory(platforms/s32k1xx/bsp/canflex2Transceiver)
    add_subdirectory(platforms/s32k1xx/bsp/canflex2Transceiver/test/gtest)
    add_subdirectory(platforms/s32k1xx/bsp/canflex2Transceiver/test/mock)

    add_subdirectory(executables/unitTest)
elseif(BUILD_REFERENCE)
    add_subdirectory(executables/referenceApp)
endif()
