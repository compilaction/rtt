//==================================================================================================
/**
  RTT - Recurrent Template Tools for the masses
  Copyright 2020 Joel FALCOU

  Licensed under the MIT License <http://opensource.org/licenses/MIT>.
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#ifndef RTT_CONTAINER_LITERAL_STRING_HPP_INCLUDED
#define RTT_CONTAINER_LITERAL_STRING_HPP_INCLUDED

#include <rtt/container/literal_string_view.hpp>
#include <rtt/constexpr_assert.hpp>
#include <iostream>

namespace rtt
{
  /*!

  **/
  template <typename CharType, int N> struct literal_string
  {
    public:
    using char_type       = CharType;
    using pointer         = const char_type*;
    using const_pointer   = const char_type*;
    using iterator        = const char_type*;
    using const_iterator  = const char_type*;
    using reference       = const char_type&;
    using const_reference = const char_type&;

    constexpr literal_string()                noexcept : content_{} {}
    constexpr literal_string(const_pointer ptr) noexcept
    {
      for(int i = 0;i != count(); ++i)
        content_[i] = ptr[i];
    }

    constexpr literal_string(literal_string const& other) noexcept
    {
      for(int i = 0;i != count(); ++i)
        content_[i] = other[i];
    }

    literal_string& operator=(literal_string const& ) =delete;
    literal_string& operator=(literal_string &&     ) =delete;

    constexpr auto operator==(literal_string const& other) const noexcept
    {
      for(int i = 0;i != count(); ++i)
        if( content_[i] != other[i]) return false;
      return true;
    }

    constexpr auto operator!=(literal_string const& other) const noexcept
    {
      for(int i = 0;i != count(); ++i)
        if( content_[i] == other[i]) return false;
      return true;
    }

    template<typename S>
    constexpr auto operator==(literal_string_view<S> const& other) const noexcept
    {
      for(int i = 0;i != other.count(); ++i)
        if( content_[i] != other[i]) return false;
      return true;
    }

    template<typename S>
    constexpr auto operator!=(literal_string_view<S> const& other) const noexcept
    {
      for(int i = 0;i != other.count(); ++i)
        if( content_[i] == other[i]) return false;
      return true;
    }

    constexpr std::size_t     size()  const noexcept { return (content_[N-1] == '\0') ? N - 1 : N; }
    constexpr std::ptrdiff_t  count() const noexcept { return static_cast<std::ptrdiff_t>(size()); }


    constexpr auto substr(int pos, int sz) const noexcept
    {
      return literal_string_view<literal_string>( *this, pos, sz==-1?size():sz );
    }

    constexpr const_iterator begin() const noexcept  { return content_;          }
    constexpr const_iterator end()   const noexcept  { return begin() + size();  }

    constexpr operator const_pointer() const noexcept { return begin();    }

    constexpr const_reference operator[](int i) const noexcept
    {
      RTT_CONSTEXPR_ASSERT(i<count());
      return content_[i];
    }

    private:
    char_type content_[N] {};
  };

  // Specialization for literal strings of size 0
  template <typename CharType> struct literal_string<CharType, 0>
  {
    using char_type       = CharType;
    using pointer         = std::nullptr_t;
    using const_pointer   = std::nullptr_t;
    using iterator        = std::nullptr_t;
    using const_iterator  = std::nullptr_t;

    constexpr literal_string()                      noexcept {}
    constexpr literal_string(const_pointer)         noexcept {}
    constexpr literal_string(literal_string const&) noexcept {}

    constexpr std::size_t     size()  const noexcept  { return 0; }
    constexpr std::ptrdiff_t  count() const noexcept  { return 0; }

    constexpr const_iterator begin() const noexcept { return nullptr; }
    constexpr const_iterator end()   const noexcept { return nullptr; }

    explicit constexpr operator const_pointer() const noexcept { return nullptr; }
  };

  // Stream insertion
  template <typename CharType, int N>
  std::ostream& operator<<( std::ostream& os, literal_string<CharType,N> const& s)
  {
    for(auto c : s) os << c;
    return os;
  }

  // Template Deduction Guide to simplify initialization from actual literal strings
  template <typename T, int N> literal_string(const T (&)[N]) -> literal_string<T, N>;
}

#endif
