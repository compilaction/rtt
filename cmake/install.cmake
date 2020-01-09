##==================================================================================================
##  RTT - Recurrent Template Tools for the masses
##  Copyright 2020 Joel FALCOU
##
##  Licensed under the MIT License <http://opensource.org/licenses/MIT>.
##  SPDX-License-Identifier: MIT
##==================================================================================================

##==================================================================================================
## Install process
##==================================================================================================
include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/rtt)

install(TARGETS rtt
    EXPORT rtt-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

##==================================================================================================
## This is required so that the exported target has the name RTT and not rtt
##==================================================================================================
set_target_properties(rtt PROPERTIES EXPORT_NAME rtt)

install ( DIRECTORY ${PROJECT_SOURCE_DIR}/include/rtt
          DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        )

##==================================================================================================
## Export the targets to a script
##==================================================================================================
install(EXPORT rtt-targets
  FILE
    rttTargets.cmake
  NAMESPACE
    rtt::
  DESTINATION
    ${INSTALL_CONFIGDIR}
)

##==================================================================================================
## Create a ConfigVersion.cmake file
##==================================================================================================
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/rttConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/rttConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/rttConfig.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

##==================================================================================================
##Install the config, configversion and custom find modules
##==================================================================================================
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/rttConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/rttConfigVersion.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)

##==================================================================================================
## Exporting from the build tree
##==================================================================================================
export(EXPORT rtt-targets FILE ${CMAKE_CURRENT_BINARY_DIR}/rttTargets.cmake NAMESPACE rtt::)

##==================================================================================================
## Register package in user's package registry
##==================================================================================================
export(PACKAGE rtt)
