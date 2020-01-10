//==================================================================================================
/**
  RTT - Recurrent Template Tools for the masses
  Copyright 2020 Joel FALCOU

  Licensed under the MIT License <http://opensource.org/licenses/MIT>.
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#ifndef RTT_CONTAINER_TYPE_CONSTANT_HPP_INCLUDED
#define RTT_CONTAINER_TYPE_CONSTANT_HPP_INCLUDED

#include <type_traits>
#include <cstddef>

namespace rtt
{
  template<auto N>
  struct constant_ : std::integral_constant<decltype(N),N>
  {};

  // -----------------------------------------------------------------------------------------------
  // Literal integral constants
  namespace detail
  {
    template<char... c> constexpr std::uint64_t chars_to_int()
    {
      std::uint64_t value = 0;
      char arr[] = {c...};

      for(std::size_t i = 0;i<sizeof...(c);++i)
        value = value*10 + (arr[i] - '0');

      return value;
    }
  }

  namespace literals
  {
    template<char ...c> constexpr auto operator"" _c() noexcept
    {
      return constant_<detail::chars_to_int<c...>()>{};
    }
  }
}

#endif
