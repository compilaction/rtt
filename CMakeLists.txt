##==================================================================================================
##  RTT - Recurrent Template Tools for the masses
##  Copyright 2020 Joel FALCOU
##
##  Licensed under the MIT License <http://opensource.org/licenses/MIT>.
##  SPDX-License-Identifier: MIT
##==================================================================================================
cmake_minimum_required(VERSION 3.5)

##==================================================================================================
## Setup project
##==================================================================================================
project(RTT VERSION 0.1 LANGUAGES CXX)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

##==================================================================================================
## Prevent in-source build
##==================================================================================================
if(${PROJECT_SOURCE_DIR} STREQUAL ${PROJECT_BINARY_DIR})
  message( FATAL_ERROR "[rtt] Building in-source, not recommended! Build in a separate directory." )
endif()

##==================================================================================================
## Options
##==================================================================================================
option( RTT_BUILD_TEST    "Build tests for rtt"     ON  )
option( RTT_BUILD_DOC     "Build doc for rtt"       ON  )
option( RTT_IS_DEPENDENT  "Dependent mode for rtt"  OFF )

##==================================================================================================
## Setup Documentation
##==================================================================================================
if( RTT_BUILD_DOC )
  add_subdirectory(doc)
endif()

##==================================================================================================
## Setup Install target only if not used as dependent
##==================================================================================================
# UNCOMMENT WHEN SOMETHING CAN BE INSTALLED
# if( NOT RTT_IS_DEPENDENT )
#   include(install)
# else()
#   message(STATUS "[rtt] RTT is used as a in-project dependency - No install targets available")
# endif()

##==================================================================================================
## Setup Testing
##==================================================================================================
if( RTT_BUILD_TEST )
  enable_testing()
  include(CTest)
  add_custom_target(tests)
  add_custom_target(unit)

  add_dependencies(tests unit)
  add_subdirectory(test)
endif()
