// Lab 10 -- singly-linked list
// Unit test

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "slist.h"

/*
 * Unit test. Do not alter.
 */

TEST_CASE("Singly-linked list") {

  SECTION("empty list") {
    SList list;

    CHECK(list.empty() == true);
    CHECK(list.getSize() == 0);
    CHECK(list.toString() == string(""));
    CHECK_THROWS_AS(list.front(), logic_error);
  }

  SECTION("minimally populated list") {
    SList list;

    for (int i = 50; i >= -50; i -= 10) {
      list.pushFront(i);
    }

    CHECK(list.empty() == false);
    CHECK(list.getSize() == 11);
    CHECK(list.toString() == string("-50,-40,-30,-20,-10,0,10,20,30,40,50"));
    CHECK(list.front() == -50);
  }
}
