//==================================================================================================
/**
  RTT - Recurrent Template Tools for the masses
  Copyright 2020 Joel FALCOU

  Licensed under the MIT License <http://opensource.org/licenses/MIT>.
  SPDX-License-Identifier: MIT
**/
//==================================================================================================

// ctor sample
#include <rtt/container/literal_string.hpp>

constexpr rtt::literal_string l = "Some literal";

// copy ctor sample
#include <rtt/container/literal_string.hpp>

constexpr rtt::literal_string o = "original string";
constexpr rtt::literal_string copy = o;

int main() {}
