// Lab 8 -- WordList with std::vector
// Unit test

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "WordList.h"

/*
 * Unit test. Do not alter.
 */

TEST_CASE("WordList") {

  SECTION("basic functionality") {
    WordList w;

    CHECK(w.getWordCount() == 0);
    CHECK(w.hasWord("") == false);
    CHECK(w.removeWord("") == false);
    CHECK(w.toString() == "");

    w.addWord("apple");
    CHECK(w.getWordCount() == 1);
    CHECK(w.hasWord("apple") == true);
    CHECK(w.toString() == "[1] apple\n");

    CHECK(w.removeWord("apple") == true);
    CHECK(w.hasWord("apple") == false);
    CHECK(w.toString() == "");
    CHECK(w.getWordCount() == 0);
    CHECK(w.removeWord("apple") == false);
  }

  SECTION("has a few words") {
    WordList w;

    w.addWord("apple");
    w.addWord("banana");
    w.addWord("cherry");

    CHECK(w.getWordCount() == 3);
    CHECK(w.hasWord("apple") == true);
    CHECK(w.hasWord("banana") == true);
    CHECK(w.hasWord("cherry") == true);
    CHECK(w.toString() == "[1] apple\n[2] banana\n[3] cherry\n");

    CHECK(w.removeWord("banana") == true);
    CHECK(w.getWordCount() == 2);
    CHECK(w.hasWord("apple") == true);
    CHECK(w.hasWord("banana") == false);
    CHECK(w.hasWord("cherry") == true);
    CHECK(w.toString() == "[1] apple\n[2] cherry\n");

    CHECK(w.removeWord("apple") == true);
    CHECK(w.getWordCount() == 1);
    CHECK(w.hasWord("apple") == false);
    CHECK(w.hasWord("banana") == false);
    CHECK(w.hasWord("cherry") == true);
    CHECK(w.toString() == "[1] cherry\n");

    CHECK(w.removeWord("cherry") == true);
    CHECK(w.getWordCount() == 0);
    CHECK(w.hasWord("apple") == false);
    CHECK(w.hasWord("banana") == false);
    CHECK(w.hasWord("cherry") == false);
    CHECK(w.toString() == "");
  }

  SECTION("stress test") {
    WordList w;

    for (unsigned int i = 0; i < 100; i++) {
      w.addWord("hello");
    }

    CHECK(w.getWordCount() == 100);

    w.removeWord("hello");

    CHECK(w.hasWord("hello") == false);
    CHECK(w.removeWord("hello") == false);
    CHECK(w.getWordCount() == 0);
    CHECK(w.toString() == "");

    for (unsigned int i = 0; i < 100; i++) {
      w.addWord("hello");
    }

    w.clear();
    CHECK(w.getWordCount() == 0);
    CHECK(w.toString() == "");
  }
}
