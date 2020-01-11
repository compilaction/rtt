##==================================================================================================
##  RTT - Recurrent Template Tools for the masses
##  Copyright 2020 Joel FALCOU
##
##  Licensed under the MIT License <http://opensource.org/licenses/MIT>.
##  SPDX-License-Identifier: MIT
##==================================================================================================
set ( SOURCES
#
    )

#make_unit( "misc" ${SOURCES})

check_failure( "misc.failure" constexpr_assert.cpp )
