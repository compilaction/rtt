//==================================================================================================
/**
  RTT - Recurrent Template Tools for the masses
  Copyright 2020 Joel FALCOU

  Licensed under the MIT License <http://opensource.org/licenses/MIT>.
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#ifndef RTT_MISC_CONSTEXPR_ASSERT_HPP_INCLUDED
#define RTT_MISC_CONSTEXPR_ASSERT_HPP_INCLUDED

#include <cassert>
#include <utility>

namespace rtt::detail
{
  template<typename Assertion>
  inline constexpr void assert_failed( Assertion&& a ) noexcept { std::forward<Assertion>(a)(); }
}

//==================================================================================================
/**
  * @brief Performs assertion checking in constexpr context
  *
  * **Required header:** `#include <rtt/misc/constexpr_assert.hpp>`
  *
  *  **Example:**
  *
  *  @snippet misc/constexpr_assert.cpp constexpr_assert
  *
  *  @param Cond an expression that evaluates to a boolean.
**/
//==================================================================================================
#define RTT_CONSTEXPR_ASSERT(Cond)                                                                  \
((void)((Cond) ? 0 : (::rtt::detail::assert_failed( [](){ assert(!#Cond); } ), 0)))                 \
/**/

#endif
