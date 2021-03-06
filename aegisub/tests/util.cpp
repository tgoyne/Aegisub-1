// Copyright (c) 2010, Amar Takhar <verm@aegisub.org>
//
// Permission to use, copy, modify, and distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
//
// $Id$

/// @file util.cpp
/// @brief Common utilities used in tests.
/// @ingroup util common

#include <fstream>
#include <sstream>
#include "util.h"

namespace util {

void copy(const std::string &from, const std::string &to) {
	std::ifstream ifs(from.c_str(), std::ios::binary);
	std::ofstream ofs(to.c_str(), std::ios::binary);

	ofs << ifs.rdbuf();
}

bool compare(const std::string &file1, const std::string &file2) {
	std::stringstream ss1, ss2;
	std::ifstream if1(file1.c_str(), std::ios::binary), if2(file2.c_str(), std::ios::binary);
	ss1 << if1.rdbuf();
	ss2 << if2.rdbuf();
	return ss1.str() == ss2.str();
}

} // namespace util


