//==================================================================================================
/**
  RTT - Recurrent Template Tools for the masses
  Copyright 2020 Joel FALCOU

  Licensed under the MIT License <http://opensource.org/licenses/MIT>.
  SPDX-License-Identifier: MIT
**/
//==================================================================================================

//! [constexpr_assert]
#include <rtt/misc/constexpr_assert.hpp>

constexpr inline bool assertion_fail(int i)
{
  RTT_CONSTEXPR_ASSERT(i != 0);
  return true;
}
//! [constexpr_assert]

//==================================================================================================
// This must trigger an error at compile time:
// In file included from test/misc/constexpr_assert.cpp:11:
// test/misc/constexpr_assert.cpp:19:57:   in ‘constexpr’ expansion of ‘assertion_fail(0)’
// include/rtt/misc/constexpr_assert.hpp:36:51: error: ‘constexpr void rtt::detail::assert_failed(A&&)
//                      [with A = assertion_fail(int)::<lambda()>]’ called in a constant expression
//  36 | ((void)((Cond) ? 0 : (::rtt::detail::assert_failed( [](){ assert(!#Cond); } ), 0)))
//     |                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~
// test/misc/constexpr_assert.cpp:15:3: note: in expansion of macro ‘RTT_CONSTEXPR_ASSERT’
//  15 |   RTT_CONSTEXPR_ASSERT(i != 0);
//     |   ^~~~~~~~~~~~~~~~~~~~
//==================================================================================================
constexpr inline bool this_is_a_failure = assertion_fail(0);
