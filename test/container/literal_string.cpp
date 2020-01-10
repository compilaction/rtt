//==================================================================================================
/**
  RTT - Recurrent Template Tools for the masses
  Copyright 2020 Joel FALCOU

  Licensed under the MIT License <http://opensource.org/licenses/MIT>.
  SPDX-License-Identifier: MIT
**/
//==================================================================================================
#include "test.hpp"
#include <rtt/container/literal_string.hpp>
#include <rtt/type/constant.hpp>

#include <tts/tests/relation.hpp>
#include <tts/tests/basic.hpp>

using rtt::constant_;

TTS_CASE( "Empty literal_string" )
{
  constexpr rtt::literal_string<char,0> x;

  TTS_SUBCASE("Runtime behavior")
  {
    TTS_EQUAL(x.size()  , 0ULL    );
    TTS_EQUAL(x.count() , 0LL     );
    TTS_EQUAL(x.begin() , x.end() );
  }

  TTS_SUBCASE("Compile-time behavior")
  {
    TTS_EQUAL ( constant_<x.size()  >::value  , 0ULL  );
    TTS_EQUAL ( constant_<x.count() >::value  , 0LL   );
    TTS_EXPECT( constant_<x.begin()== x.end()>::value );
  }
}

TTS_CASE( "Non-empty literal_string" )
{
  constexpr rtt::literal_string x = "0123456789";
  constexpr rtt::literal_string z = "0123456789";
  constexpr rtt::literal_string y = "456";

  TTS_SUBCASE("Runtime behavior")
  {
    TTS_EQUAL( x.size()  , 10ULL               );
    TTS_EQUAL( x.count() , 10LL                );
    TTS_EQUAL( x.end()   , x.begin() + x.size());

    for(int i=0;i<x.count();++i)
      TTS_EQUAL( x[i], z[i]);

    TTS_EQUAL     ( x , z );
    TTS_NOT_EQUAL ( x , y );

    constexpr auto sub_x43 = x.substr(4,3);

    TTS_EQUAL( sub_x43.size() , 3ULL );
    TTS_EQUAL( sub_x43.count(), 3LL  );
    TTS_EQUAL( std::distance(sub_x43.begin(),sub_x43.end()), 3);

    for(int i=0;i<sub_x43.count();++i) TTS_EQUAL( sub_x43[i], x[i+4]);
    TTS_EQUAL( sub_x43, y );
  }

  TTS_SUBCASE("Compile-time behavior")
  {
    TTS_EQUAL ( constant_< x.size()  >::value , 10ULL );
    TTS_EQUAL ( constant_< x.count() >::value , 10LL  );
    TTS_EXPECT( constant_< x.end()== x.begin()+x.size() >::value);

    TTS_EXPECT( constant_< x[0] == z[0] >::value );
    TTS_EXPECT( constant_< x[4] == z[4] >::value );
    TTS_EXPECT( constant_< x[9] == z[9] >::value );

    TTS_EXPECT( constant_< x == z >::value );
    TTS_EXPECT( constant_< x != y >::value );

    constexpr auto sub_x43 = x.substr(4,3);

    TTS_EQUAL ( constant_< sub_x43.size()  >::value , 3ULL  );
    TTS_EQUAL ( constant_< sub_x43.count() >::value , 3LL   );
    TTS_EQUAL ( constant_< std::distance(sub_x43.begin(),sub_x43.end())>::value , 3LL  );

    TTS_EXPECT( constant_<sub_x43 == y>::value );
  }
}
