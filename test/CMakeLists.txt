##==================================================================================================
##  RTT - Recurrent Template Tools for the masses
##  Copyright 2020 Joel FALCOU
##
##  Licensed under the MIT License <http://opensource.org/licenses/MIT>.
##  SPDX-License-Identifier: MIT
##==================================================================================================
include(make_unit)

set ( SOURCES
      container/literal_string.cpp
      type/constant.cpp
    )

make_unit( "rtt" ${SOURCES})


check_failure( "rtt" misc/constexpr_assert.cpp )
