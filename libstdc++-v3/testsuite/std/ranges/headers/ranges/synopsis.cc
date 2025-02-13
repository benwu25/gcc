// Copyright (C) 2019-2025 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

// { dg-do compile { target c++20 } }
// { dg-add-options no_pch }

#include <ranges>

#ifndef __cpp_lib_ranges
# error "Feature test macro for ranges is missing in <ranges>"
#elif __cplusplus > 202302L && __cpp_lib_ranges != 202406L
# error "Feature test macro for ranges has wrong value in <ranges>"
#elif __cplusplus == 202302L && __cpp_lib_ranges != 202302L
# error "Feature test macro for ranges has wrong value in <ranges>"
#elif __cplusplus == 202002L && __cpp_lib_ranges != 202110L
# error "Feature test macro for ranges has wrong value in <ranges>"
#endif

struct R { };
template<> constexpr bool std::ranges::disable_sized_range<R> = true;

namespace __gnu_test
{
  constexpr const bool* disable_sized_range
    = &std::ranges::disable_sized_range<void>;
  using std::ranges::begin;
  using std::ranges::end;
  using std::ranges::cbegin;
  using std::ranges::cend;
  using std::ranges::rbegin;
  using std::ranges::rend;
  using std::ranges::crbegin;
  using std::ranges::crend;
  using std::ranges::size;
  using std::ranges::ssize;
  using std::ranges::empty;
  using std::ranges::data;
  using std::ranges::cdata;

  using std::ranges::advance;
  using std::ranges::distance;
  using std::ranges::next;
  using std::ranges::prev;
}
