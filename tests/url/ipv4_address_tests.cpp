// Copyright 2018-20 Glyn Matthews.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt of copy at
// http://www.boost.org/LICENSE_1_0.txt)

#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "../../src/url/ipv4_address.hpp"

TEST_CASE("ipv4 addresses", "[ipv4]") {
  using namespace std::string_literals;

  SECTION("zero_test") {
    auto instance = skyr::ipv4_address(0);
    CHECK("0.0.0.0" == instance.to_string());
  }

  SECTION("loopback_test") {
    auto instance = skyr::ipv4_address(0x7f000001);
    CHECK("127.0.0.1" == instance.to_string());
  }

  SECTION("address_test") {
    auto instance = skyr::ipv4_address(0x814ff5fc);
    CHECK("129.79.245.252" == instance.to_string());
  }

  SECTION("parse_zero_test") {
    const auto address = "0.0.0.0"s;
    auto instance = skyr::parse_ipv4_address(address);
    REQUIRE(instance);
    CHECK(0 == instance.value().address());
  }

  SECTION("parse_loopback_test") {
    const auto address = "127.0.0.1"s;
    auto instance = skyr::parse_ipv4_address(address);
    REQUIRE(instance);
    CHECK(0x7f000001 == instance.value().address());
  }

  SECTION("parse_address_test") {
    const auto address = "129.79.245.252"s;
    auto instance = skyr::parse_ipv4_address(address);
    REQUIRE(instance);
    CHECK(0x814ff5fc == instance.value().address());
  }

  SECTION("parse_address_with_hex") {
    const auto address = "0x7f.0.0.0x7f"s;
    auto instance = skyr::parse_ipv4_address(address);
    REQUIRE(instance);
    CHECK(0x7f00007f == instance.value().address());
  }

  SECTION("parse_invalid_address_with_hex") {
    const auto address = "0x7f.0.0.0x7g"s;
    auto instance = skyr::parse_ipv4_address(address);
    REQUIRE_FALSE(instance);
  }
}
