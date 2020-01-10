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
#include <tts/tests/types.hpp>
#include <tts/tests/basic.hpp>

int f(double) { return 0; }

TTS_CASE( "constant_ type informations" )
{
  TTS_TYPE_IS( rtt::constant_<true>::value_type         , bool              );
  TTS_TYPE_IS( rtt::constant_<'Z'>::value_type          , char              );
  TTS_TYPE_IS( rtt::constant_<short(12345)>::value_type , short             );
  TTS_TYPE_IS( rtt::constant_<123456>::value_type       , int               );
  TTS_TYPE_IS( rtt::constant_<sizeof(0)>::value_type    , std::size_t       );
  TTS_TYPE_IS( rtt::constant_<f>::value_type            , (int)(*)(double)  );
}

TTS_CASE( "constant_ values" )
{
  TTS_EQUAL( rtt::constant_<true>::value         , true       );
  TTS_EQUAL( rtt::constant_<'Z'>::value          , 'Z'        );
  TTS_EQUAL( rtt::constant_<short(12345)>::value , 12345      );
  TTS_EQUAL( rtt::constant_<123456>::value       , 123456     );
  TTS_EQUAL( rtt::constant_<sizeof(0)>::value    , sizeof(0)  );
  TTS_EQUAL( rtt::constant_<f>::value            , f          );
}

TTS_CASE( "constant_ literal" )
{
  using namespace rtt::literals;

  TTS_TYPE_IS ( decltype(133742_c)::value_type , std::uint64_t );
  TTS_EQUAL   ( 216942_c                       , 216942ULL     );
}
