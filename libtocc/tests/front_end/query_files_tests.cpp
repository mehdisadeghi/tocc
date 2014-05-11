/*
 * This file is part of Tocc. (see <http://www.github.com/aidin36/tocc>)
 * Copyright (C) 2013, 2014, Aidin Gharibnavaz <tocc@aidinhut.com>
 *
 * Tocc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Tocc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 *  along with Tocc.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <catch.hpp>

#include "libtocc/front_end/manager.h"
#include "libtocc/front_end/file_info.h"
#include "libtocc/exprs/query.h"
#include "libtocc/exprs/connectives.h"
#include "libtocc/exprs/fields.h"


TEST_CASE("query_files_tests: simple tag search")
{
  libtocc::Manager manager("/tmp/");

  SECTION("Assign and search 'test_tag_0xUi7'")
  {
    manager.assign_tags("0000001", "test_tag_0xUi7");

    libtocc::Tag* tag_expr = libtocc::Tag::create("test_tag_0xUi7");
    libtocc::And* main_and = libtocc::And::create(tag_expr);

    libtocc::Query query(main_and);

    libtocc::FileInfoCollection founded_files = manager.search_files(query);

    REQUIRE(founded_files.size() == 1);
  }
}
