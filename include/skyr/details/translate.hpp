// Copyright (c) Glyn Matthews 2012-2018.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef SKYR_URL_DETAILS_TRANSLATE_INC
#define SKYR_URL_DETAILS_TRANSLATE_INC

#include <string>
#include <locale>
#include <codecvt>

namespace skyr {
namespace details {
template <typename Source>
struct translate_impl;

template <>
struct translate_impl<std::string> {
  std::string operator()(const std::string &source) const { return source; }
};

template <int N>
struct translate_impl<char[N]> {
  std::string operator()(const char *source) const { return source; }
};

template <>
struct translate_impl<char *> {
  std::string operator()(const char *source) const { return source; }
};

template <>
struct translate_impl<const char *> {
  std::string operator()(const char *source) const { return source; }
};

template <int N>
struct translate_impl<const char[N]> {
  std::string operator()(const char *source) const { return source; }
};

template <>
struct translate_impl<std::wstring> {
  std::string operator()(const std::wstring &source) const {
    std::wstring_convert<std::codecvt_utf8<wchar_t >> convert;
    return convert.to_bytes(source);
  }
};

template <int N>
struct translate_impl<const wchar_t[N]> {
  std::string operator()(const wchar_t *source) const {
    translate_impl<std::wstring> impl;
    return impl(source);
  }
};

template <int N>
struct translate_impl<wchar_t[N]> {
  std::string operator()(const wchar_t *source) const {
    translate_impl<std::wstring> impl;
    return impl(source);
  }
};

template <>
struct translate_impl<wchar_t *> {
  std::string operator()(const wchar_t *source) const {
    translate_impl<std::wstring> impl;
    return impl(source);
  }
};

template <>
struct translate_impl<const wchar_t *> {
  std::string operator()(const wchar_t *source) const {
    translate_impl<std::wstring> impl;
    return impl(source);
  }
};

template <typename Source>
inline std::string translate(const Source &source) {
  translate_impl<Source> impl;
  return impl(source);
}

}  // namespace details
}  // namespace skyr

#endif  // SKYR_URL_DETAILS_TRANSLATE_INC