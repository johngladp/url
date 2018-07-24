// Copyright 2018 Glyn Matthews.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef SKYR_URL_PARSE_INC
#define SKYR_URL_PARSE_INC

#include <string>
#include <skyr/optional.hpp>
#include <skyr/expected.hpp>
#include <skyr/url_record.hpp>
#include <skyr/url_parse_state.hpp>
#include <skyr/url_error.hpp>

namespace skyr {
///
/// \param input The input string that will be parse
/// \param base An optional base URL
/// \param url An optional `url_record`
/// \param state_override
/// \returns An optional `url_record` on success
expected<url_record, parse_error> basic_parse(
    std::string input,
    const optional<url_record> &base = nullopt,
    const optional<url_record> &url = nullopt,
    optional<url_parse_state> state_override = nullopt);

/// Parses a URL
/// \param input The input string that will be parse
/// \param base An optional base URL
/// \returns An optional `url_record` on success
expected<url_record, parse_error> parse(
    std::string input,
    const optional<url_record> &base = nullopt);
}  // namespace skyr

#endif  // SKYR_URL_PARSE_INC
