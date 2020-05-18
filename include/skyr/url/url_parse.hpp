// Copyright 2018-19 Glyn Matthews.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef SKYR_URL_PARSE_INC
#define SKYR_URL_PARSE_INC

#include <system_error>
#include <optional>
#include <variant>
#include <tl/expected.hpp>
#include <skyr/url/url_error.hpp>
#include <skyr/url/url_record.hpp>
#include <skyr/url/ipv4_address.hpp>
#include <skyr/url/ipv6_address.hpp>

namespace skyr {
inline namespace v1 {
/// Parses a URL and returns a `url_record`
///
/// \param input The input string
/// \param base An optional base URL
/// \returns A `url_record` on success and an error code on failure
tl::expected<url_record, std::error_code> parse(
    std::string_view input,
    std::optional<url_record> base = std::nullopt);
}  // namespace v1


using parsed_host =
   std::variant<
      std::string,
      ipv4_address,
      ipv6_address>;

tl::expected<parsed_host, url_parse_errc> parse_host2(
   std::string_view input,
   bool is_not_special = false);

}  // namespace skyr

#endif  // SKYR_URL_PARSE_INC
