// Copyright 2019 Glyn Matthews.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt of copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <string>
#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <skyr/url/details/to_bytes.hpp>

TEST_CASE("weird_01", "byte_conversion_tests") {
  auto bytes = skyr::details::to_bytes(U"http://\xfdD0zyx.com");
  CHECK(bytes);
}

TEST_CASE("weird_02", "byte_conversion_tests") {
  auto bytes = skyr::details::to_bytes("/\xf0\x9f\x8d\xa3\xf0\x9f\x8d\xba");
  CHECK(bytes);
}
