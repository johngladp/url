// Copyright 2018 Glyn Matthews.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef SKYR_IPV6_ADDRESS_INC
#define SKYR_IPV6_ADDRESS_INC

#include <string>
#include <array>
#include <algorithm>
#include <iterator>
#include <skyr/string_view.hpp>

namespace skyr {
///
class ipv6_address {

  std::array<unsigned short, 8> repr_;
  bool validation_error_;

  using repr_type = decltype(repr_);

 public:

  using value_type = repr_type::value_type;
  using iterator = repr_type::iterator;
  using const_iterator = repr_type::const_iterator;
  using reference = repr_type::reference;
  using const_reference = repr_type::const_reference;
  using size_type = repr_type::size_type;
  using difference_type = repr_type::difference_type;

  /// Constructor
  ipv6_address()
      : repr_(), validation_error_(false) {
    std::fill(std::begin(repr_), std::end(repr_), 0);
  }

  /// Constructor
  /// \param repr
  explicit ipv6_address(std::array<unsigned short, 8> repr)
      : repr_(repr), validation_error_(false) {}

  /// Constructor
  /// \param repr
  /// \param validation_error
  ipv6_address(std::array<unsigned short, 8> repr, bool validation_error)
      : repr_(repr), validation_error_(validation_error) {}

   /// \returns
  std::string to_string() const;

};

/// \param input
/// \param returns
optional<ipv6_address> parse_ipv6_address(string_view input);
}  // namespace skyr

#endif //SKYR_IPV6_ADDRESS_INC
