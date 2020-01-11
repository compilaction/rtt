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
#include <rtt/misc/constexpr_assert.hpp>
#include <iostream>

namespace rtt
{
  //==================================================================================================
  /**
    * **Required header:** `#include <rtt/types/literal_string.hpp>`
    *
    * literal_string is container designed to be filled with a constant, literal C string.
    * It provides the complete set of immutable string operations.
    *
    * @tparam CharType character type stored in the string literal.
    * @tparam N        size of the string literal.
  **/
  //==================================================================================================
  template <typename CharType, int N> struct literal_string
  {
    public:
    using value_type      = CharType;
    using pointer         = const value_type*;
    using const_pointer   = const value_type*;
    using iterator        = const value_type*;
    using const_iterator  = const value_type*;
    using reference       = const value_type&;
    using const_reference = const value_type&;

    /**
      * Constructor from literal string pointer
      * @param ptr Literal string to wrap
    **/
    constexpr literal_string(const_pointer ptr) noexcept
    {
      for(int i = 0;i != count(); ++i)
        content_[i] = ptr[i];
    }

    /**
      * Copy constructor
      * @param other literal_string to be copied
    **/
    constexpr literal_string(literal_string const& other) noexcept
    {
      for(int i = 0;i != count(); ++i)
        content_[i] = other[i];
    }

    literal_string& operator=(literal_string const& ) =delete;
    literal_string& operator=(literal_string &&     ) =delete;

    /**
      * Equality comparison operator
      * @param other literal string to compare
    **/
    template<typename LS>
    constexpr   auto operator==(LS const& other) const noexcept
            ->  decltype(std::declval<StringType>()[0] != other[0])
    {
      for(int i = 0;i != count(); ++i)
        if( content_[i+pos_] != other[i]) return false;
      return true;
    }

    /**
      * Inequality comparison operator
      * @param other literal string to compare
    **/
    template<typename LS>
    constexpr   auto operator!=(LS const& other) const noexcept
            ->  decltype(std::declval<StringType>()[0] == other[0])
    {
      for(int i = 0;i != count(); ++i)
        if( content_[i+pos_] == other[i]) return false;
      return true;
    }

    /// Returns the number of CharT elements in the literal string as an unsigned integer.
    constexpr std::size_t     size()  const noexcept { return (content_[N-1] == '\0') ? N - 1 : N; }

    /// Returns the number of CharT elements in the literal string as a signed integer.
    constexpr std::ptrdiff_t  count() const noexcept { return static_cast<std::ptrdiff_t>(size()); }

    constexpr auto substr(int pos, int sz) const noexcept
    {
      return literal_string_view<literal_string>( *this, pos, sz==-1?size():sz );
    }

    /// Returns an immutable iterator to the first character of the literal string.
    constexpr const_iterator begin() const noexcept  { return content_;          }

    /// Returns an immutable iterator past the last character of the literal string.
    constexpr const_iterator end()   const noexcept  { return begin() + size();  }

    /// Converts a string literal to a pointer to CharT
    constexpr operator const_pointer() const noexcept { return begin();    }

    /**
      * Random-access subscript operator
      * @param i Index to access
      * @return Character value at index @c i
    **/
    constexpr const_reference operator[](int i) const noexcept
    {
      RTT_CONSTEXPR_ASSERT(i<count());
      return content_[i];
    }

    private:
    value_type content_[N] {};
  };

#if !defined(DOXYGEN_ONLY)
  // Specialization for literal strings of size 0
  template <typename CharType> struct literal_string<CharType, 0>
  {
    using value_type       = CharType;
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
#endif

  // Stream insertion
  template <typename CharType, int N>
  std::ostream& operator<<( std::ostream& os, literal_string<CharType,N> const& s)
  {
    for(auto c : s) os << c;
    return os;
  }

  /// Template Deduction Guide to simplify initialization from actual literal strings
  template <typename T, int N> literal_string(const T (&)[N]) -> literal_string<T, N>;
}

#endif
