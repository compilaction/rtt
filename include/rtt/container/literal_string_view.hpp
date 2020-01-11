//==================================================================================================
/**
  RTT - Recurrent Template Tools for the masses
  Copyright 2020 Joel FALCOU

  Licensed under the MIT License <http://opensource.org/licenses/MIT>.
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#ifndef RTT_CONTAINER_LITERAL_STRING_VIEW_HPP_INCLUDED
#define RTT_CONTAINER_LITERAL_STRING_VIEW_HPP_INCLUDED

#include <rtt/misc/constexpr_assert.hpp>
#include <iostream>

namespace rtt
{
  /*!

  **/
  template <typename StringType> struct literal_string_view
  {
    public:
    using char_type       = typename StringType::char_type;
    using pointer         = typename StringType::pointer;
    using const_pointer   = typename StringType::const_pointer;
    using iterator        = typename StringType::iterator;
    using const_iterator  = typename StringType::const_iterator;
    using reference       = typename StringType::reference;
    using const_reference = typename StringType::const_reference;

    constexpr literal_string_view(StringType const& other, int p, int s) noexcept
            : content_(other), pos_(p), size_(s)
    {}

    constexpr auto operator==(literal_string_view const& other) const noexcept
    {
      for(int i = 0;i != count(); ++i)
        if( content_[i] != other[i]) return false;
      return true;
    }

    constexpr auto operator!=(literal_string_view const& other) const noexcept
    {
      for(int i = 0;i != count(); ++i)
        if( content_[i] == other[i]) return false;
      return true;
    }

    template<typename LS>
    constexpr   auto operator==(LS const& other) const noexcept
            ->  decltype(other == std::declval<literal_string_view>())
    {
      return other == *this;
    }

    template<typename LS>
    constexpr   auto operator!=(LS const& other) const noexcept
            ->  decltype(other == std::declval<literal_string_view>())
    {
      return !(*this == other);
    }

    constexpr std::size_t     size()  const noexcept { return size_; }
    constexpr std::ptrdiff_t  count() const noexcept { return size_; }

    constexpr const_iterator begin() const noexcept  { return content_.begin() + pos_;  }
    constexpr const_iterator end()   const noexcept  { return begin() + size_;          }

    constexpr operator const_pointer() const noexcept { return content_.begin(); }

    constexpr auto operator[](int i) const noexcept -> decltype(std::declval<StringType>()[0])
    {
      RTT_CONSTEXPR_ASSERT(i<count());
      return content_[i+pos_];
    }

    //private:
    StringType content_;
    int pos_, size_;
  };

  template <typename StringType>
  std::ostream& operator<<( std::ostream& os, literal_string_view<StringType> const& s)
  {
    for(auto c : s) os << c;
    return os;
  }
}

#endif
