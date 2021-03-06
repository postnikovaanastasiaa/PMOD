cmake_minimum_required(VERSION 2.8.8)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
project(Galois)
set(GALOIS_VERSION_MAJOR "2")
set(GALOIS_VERSION_MINOR "2")
set(GALOIS_VERSION_PATCH "1")
set(GALOIS_VERSION ${GALOIS_VERSION_MAJOR}.${GALOIS_VERSION_MINOR}.${GALOIS_VERSION_PATCH})
set(GALOIS_COPYRIGHT_YEAR "2014") # Also in COPYRIGHT

if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type selected, default to Release")
  set(CMAKE_BUILD_TYPE "Release")
endif()

###### Options (alternatively pass as options to cmake -DName=Value) ######
set(USE_GPROF OFF CACHE BOOL "Enable GCC profiling")
set(USE_VTUNE OFF CACHE BOOL "Use VTune for profiling")
set(USE_PAPI OFF CACHE BOOL "Use PAPI counters for profiling")
set(USE_HPCTOOLKIT OFF CACHE BOOL "Use HPCToolKit for profiling")
set(USE_STRICT_CONFIG OFF CACHE BOOL "Instead of falling back gracefully, fail")
set(USE_LONGJMP ON CACHE BOOL "Use longjmp instead of exceptions to signal aborts")
set(INSTALL_APPS OFF CACHE BOOL "Install apps as well as library")
set(SKIP_COMPILE_APPS OFF CACHE BOOL "Skip compilation of applications using Galois library")

set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set(INSTALL_BIN_DIR bin CACHE PATH "Installation directory for executables")
set(INSTALL_INCLUDE_DIR include CACHE PATH "Installation directory for header files")
set(INSTALL_CMAKE_DIR lib/cmake/Galois CACHE PATH "Installation directory for CMake files")
# Make relative paths absolute
foreach(p LIB BIN INCLUDE CMAKE)
  set(var INSTALL_${p}_DIR)
  if(NOT IS_ABSOLUTE "${${var}}")
    set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
  endif()
endforeach()

# Enable iss specific options; should be OFF in the general release; all guarded by USE_EXP
set(USE_EXP OFF CACHE BOOL "Use experimental features")
set(USE_HTM OFF CACHE BOOL "Use HTM")
set(EXP_DOALL "PTHREAD" CACHE STRING "Which type of implementation of parallel_doall")
set(USE_PROF OFF CACHE BOOL "Use profiling specific features")
set(USE_SUBVERSION_REVISION ON CACHE BOOL "Embed subversion numbers")

###### Configure (users don't need to go beyond here) ######

enable_testing()

###### Configure compiler ######

# ICC
if(CMAKE_CXX_COMPILER_ID MATCHES "Intel")
  execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion
                  OUTPUT_VARIABLE ICC_VERSION)
  if(ICC_VERSION VERSION_GREATER 13.0 OR ICC_VERSION VERSION_EQUAL 13.0)
    #message(STATUS "ICC Version >= 13.0")
  else()
    message(FATAL_ERROR "ICC must be 13.0 or higher found: ${ICC_VERSION}")
  endif()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -wd68 -wd981 -wd383 -wd869 -wd2196 -wd279 -wd2504 -wd2943 -wd32013")

  if("$ENV{GCC_BIN}" STREQUAL "")
    message(STATUS "Using default GCC toolchain; set environment variable GCC_BIN to override")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -gxx-name=$ENV{GCC_BIN}/g++")
  endif()
endif()

# Clang
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  if("$ENV{GCC_BIN}" STREQUAL "")
    message(STATUS "Using default GCC toolchain; set environment variable GCC_BIN to override")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -gcc-toolchain $ENV{GCC_BIN}/..")
  endif()
endif()

# XL
if(CMAKE_CXX_COMPILER_ID MATCHES "XL")
  execute_process(COMMAND ${CMAKE_CXX_COMPILER} -qversion
                  COMMAND sed 1d
                  COMMAND sed s/Version://
                  OUTPUT_VARIABLE XLC_VERSION)
  if(XLC_VERSION VERSION_GREATER 12.0)
    #message(STATUS "XLC Version > 12.0")
  else()
    message(FATAL_ERROR "XLC must be higher than 12.0")
  endif()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -qsuppress=1540-0724 -qsuppress=1500-029 -qmaxmem=-1 -qalias=noansi -qsmp=omp")
endif()

# check for incompatible GCC
if(CMAKE_COMPILER_IS_GNUCC)
  execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion
                  OUTPUT_VARIABLE GCC_VERSION)
  if(GCC_VERSION VERSION_GREATER 4.6 OR GCC_VERSION VERSION_EQUAL 4.6)
    #message(STATUS "GCC Version >= 4.6")
  else()
    message(FATAL_ERROR "GCC must be 4.6 or higher")
  endif()
endif()

# solaris
if(CMAKE_SYSTEM MATCHES "SunOS.*")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64 -mcpu=niagara2 -lposix4")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -m64 -lposix4")
endif()

# Always include debug symbols
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g  -lrt")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -lrt")
# donot include debug symbols
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lrt")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lrt")

# Include GEM5 build flags
if (SIM MATCHES "ON")
  set(REPO_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/..)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DGEM5")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DGEM5")
endif()

# Enable architecture-specific optimizations
if(CMAKE_BUILD_TYPE MATCHES "Release" AND CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
endif()

# More warnings
if(CMAKE_BUILD_TYPE MATCHES "Debug")
  if(NOT CMAKE_CXX_COMPILER_ID MATCHES "XL")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
  endif()
  if(CMAKE_COMPILER_IS_GNUCC)
    if(GCC_VERSION VERSION_GREATER 4.8 OR GCC_VERSION VERSION_EQUAL 4.8)
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-local-typedefs")
    endif()
  endif()
endif()

# GNU profiling
if(USE_GPROF)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pg")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
endif(USE_GPROF)

# Include -static to linker flags
if (SIM MATCHES "ON")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
endif()

###### Configure features ######

# Experimental features
if(USE_EXP)
  set(USE_VTUNE ON)
  add_definitions(-DGALOIS_USE_EXP)
  include_directories("exp/include")

  find_package(OpenMP)
  if (OPENMP_FOUND)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
  endif ()

  if(USE_PROF)
    add_definitions(-DGALOIS_USE_PROF)
  endif()

  if(USE_SUBVERSION_REVISION)
    include(GetSVNVersion)
    set(GALOIS_USE_SVNVERSION on)
  endif()

  if(USE_HTM)
    if(CMAKE_CXX_COMPILER_ID MATCHES "XL")
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -qtm -qsmp=speculative")
      set(GALOIS_USE_HTM on)
      set(GALOIS_USE_SEQ_ONLY on)
      set(GALOIS_USE_LONGJMP on)
    else()
      message(FATAL_ERROR "Hardware transactional memory not supported")
    endif()
  endif()

  # Experimental Deterministic features
  if(USE_DET_INORDER)
    add_definitions(-DGALOIS_USE_DET_INORDER)
  endif()
  if(USE_DET_FIXED_WINDOW)
    add_definitions(-DGALOIS_USE_DET_FIXED_WINDOW)
  endif()
endif()

if (SIM MATCHES "ON")
else()
  # PThreads
  find_package(Threads REQUIRED)
endif()

# NUMA (linux)
find_package(NUMA)
if(NUMA_FOUND)
  if (SIM MATCHES "ON")
    set(GALOIS_USE_NUMA off)
  else()
    set(GALOIS_USE_NUMA on)
  endif()
elseif(USE_STRICT_CONFIG)
  message(FATAL_ERROR "Need libnuma")
endif()

# CILK
include(CheckCilk)

# HugePages
include(CheckHugePages)
if(NOT HAVE_HUGEPAGES AND USE_STRICT_CONFIG)
  message(FATAL_ERROR "Need huge pages")
endif()

# Longjmp
if(USE_LONGJMP)
  set(GALOIS_USE_LONGJMP on)
endif()

# Boost
set(Boost_ADDITIONAL_VERSIONS "1.40" "1.40.0" "1.47" "1.47.0" "1.49" "1.49.0" "1.51.0")
if(NOT "$ENV{BOOST_DIR}" STREQUAL "")
  set(BOOST_ROOT $ENV{BOOST_DIR})
endif()
find_package(Boost 1.38.0 REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

# C++11 features
find_package(CXX11)
if ("${CXX11_FLAGS}" STREQUAL "")
   message( FATAL_ERROR "Needs C++11")
endif()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX11_FLAGS}")

include(CheckEndian)

include(llvm-extras)
#always import c99 stdint functions into c++
#include(UseStdMacro) # HandleLLVMOptions.cmake (via llvm-extras) already does this for us
#include_directories("${PROJECT_BINARY_DIR}/include") # llvm-extra already does this for us

###### Build Hacks ######

# XXX(ddn): Hack for lonestar machines
if(NUMA_FOUND)
  if(NUMA_OLD)
    set(GALOIS_USE_NUMA_OLD on)
  endif()
endif()

###### Global Functions ######

include(ParseArguments)

function(compileApp name)
  if(ARGN)
    set(Sources ${ARGN})
  else()
    file(GLOB Sources *.cpp)
  endif()
  add_executable(${name} ${Sources})
endfunction (compileApp)

function(app name)
  PARSE_ARGUMENTS(APP "REQUIRES;EXTLIBS" "" ${ARGN})

  foreach(required ${APP_REQUIRES})
    if(${${required}} MATCHES "TRUE")
    else()
      message("-- NOT compiling ${name} (missing: ${required})")
      return()
    endif()
  endforeach()

  compileApp(${name} ${APP_DEFAULT_ARGS})
  target_link_libraries(${name} ${APP_EXTLIBS})
  target_link_libraries(${name} galois)
  if (SIM MATCHES "ON")
    # GEM5 doesn't use the system pthread library, but the one provided by
    # m5threads
    target_link_libraries(${name} ${REPO_ROOT}/simulator/m5threads/libpthread.a)
  endif()
  if(INSTALL_APPS)
    install(TARGETS ${name} DESTINATION bin)
  endif()
endfunction(app)

###### Source finding ######
include_directories(include)
if (SIM MATCHES "ON")
  include_directories(${REPO_ROOT}/simulator/util/m5)
endif()

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(tools)
add_subdirectory(scripts)
if(NOT SKIP_COMPILE_APPS)
  add_subdirectory(apps)
  add_subdirectory(inputs)
  add_subdirectory(test)
endif()
if(USE_EXP)
  add_subdirectory(exp)
endif()

###### Documentation ######
set(DOXYFILE_SOURCE_DIR "src\" \"include")
include(UseDoxygen OPTIONAL)

###### Distribution ######
include(InstallRequiredSystemLibraries)
set(CPACK_GENERATOR "TGZ")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/COPYRIGHT")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README")
set(CPACK_PACKAGE_VERSION_MAJOR ${GALOIS_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${GALOIS_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${GALOIS_VERSION_PATCH})
include(CPack)

###### Installation ######

export(TARGETS galois APPEND FILE "${PROJECT_BINARY_DIR}/GaloisTargets.cmake")
export(PACKAGE Galois)

# Galois include files
file(RELATIVE_PATH rel_include_dir "${INSTALL_CMAKE_DIR}" "${INSTALL_INCLUDE_DIR}")
set(GALOIS_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include" "${PROJECT_BINARY_DIR}/include")
if(USE_EXP)
  set(GALOIS_INCLUDE_DIR "${GALOIS_INCLUDE_DIR}" "${PROJECT_SOURCE_DIR}/exp/include")
endif()

# Galois include dependencies
set(GALOIS_INCLUDE_DIRS)
get_target_property(defs galois INCLUDE_DIRECTORIES)
foreach(d ${defs})
  string(FIND ${d} ${PROJECT_BINARY_DIR} pos1)
  string(FIND ${d} ${PROJECT_SOURCE_DIR} pos2)
  if(NOT ${pos1} EQUAL 0 AND NOT ${pos2} EQUAL 0)
    set(GALOIS_INCLUDE_DIRS ${GALOIS_INCLUDE_DIRS} ${d})
  endif()
endforeach()

# Galois compiler definitions
set(galois_defs)
get_directory_property(defs DIRECTORY "${PROJECT_SOURCE_DIR}/src" COMPILE_DEFINITIONS)
foreach(d ${defs})
  set(galois_defs "-D${d} ${galois_defs}")
endforeach()
get_directory_property(defs DIRECTORY "${PROJECT_SOURCE_DIR}/src" COMPILE_DEFINITIONS_${CMAKE_BUILD_TYPE})
foreach(d ${defs})
  set(galois_defs "-D${d} ${galois_defs}")
endforeach()
string(TOUPPER ${CMAKE_BUILD_TYPE} upper_build_type)
set(GALOIS_FLAGS "${galois_defs} ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_${upper_build_type}}")
set(GALOIS_CXX_COMPILER "${CMAKE_CXX_COMPILER}")

# Generate appropriate CMake files for installation and build trees
configure_file("${PROJECT_SOURCE_DIR}/cmake/Modules/GaloisConfig.cmake.in"
  "${PROJECT_BINARY_DIR}/GaloisConfig.cmake" @ONLY)
set(GALOIS_INCLUDE_DIR "\${GALOIS_CMAKE_DIR}/${rel_include_dir}")
configure_file("${PROJECT_SOURCE_DIR}/cmake/Modules/GaloisConfig.cmake.in"
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/GaloisConfig.cmake" @ONLY)
configure_file("${PROJECT_SOURCE_DIR}/cmake/Modules/GaloisConfigVersion.cmake.in"
  "${PROJECT_BINARY_DIR}/GaloisConfigVersion.cmake" @ONLY)
install(FILES
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/GaloisConfig.cmake"
  "${PROJECT_BINARY_DIR}/GaloisConfigVersion.cmake"
  DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)
install(EXPORT GaloisTargets DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)
