//==================================================================================================
/**
  RTT - Recurrent Template Tools for the masses
  Copyright 2020 Joel FALCOU

  Licensed under the MIT License <http://opensource.org/licenses/MIT>.
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#ifndef RTT_CONSTEXPR_ASSERT_HPP_INCLUDED
#define RTT_CONSTEXPR_ASSERT_HPP_INCLUDED

#include <cassert>
#include <utility>

namespace rtt::detail
{
  template<typename A> inline constexpr void assert_failed( A&& a ) noexcept { std::forward<A>(a)(); }
}

#define RTT_CONSTEXPR_ASSERT(Cond)                                                                  \
((void)((Cond) ? 0 : (::rtt::detail::assert_failed( [](){ assert(!#Cond); } ), 0)))                 \
/**/

#endif
