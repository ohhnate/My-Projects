// Lab 11 -- singly-linked list
// Unit test

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "SList.h"

#include <cstdlib> // srand, rand
#include <ctime>   // time

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
    CHECK_THROWS_AS(list.popFront(), logic_error);
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
    list.popFront();
    CHECK(list.front() == -40);
    list.popFront();
    CHECK(list.front() == -30);
    list.popFront();
    CHECK(list.front() == -20);
    list.popFront();
    CHECK(list.front() == -10);
    list.popFront();

    CHECK(list.getSize() == 6);
    CHECK(list.toString() == string("0,10,20,30,40,50"));

    list.clear();
    CHECK(list.empty() == true);
    CHECK(list.getSize() == 0);
    CHECK(list.toString() == "");
    CHECK_THROWS_AS(list.front(), logic_error);
    CHECK_THROWS_AS(list.popFront(), logic_error);
  }

  SECTION("stress test") {
    srand(time(nullptr));

    SList list;

    for (unsigned int i = 0; i < 1000; i++) {
      list.pushFront(rand() % 1000);
    }

    for (unsigned int i = 0; i < 500; i++) {
      list.popFront();
    }

    CHECK(list.getSize() == 500);

    list.clear();
    CHECK(list.empty() == true);
    CHECK(list.getSize() == 0);
    CHECK(list.toString() == "");
    CHECK_THROWS_AS(list.front(), logic_error);
    CHECK_THROWS_AS(list.popFront(), logic_error);
  }
}
