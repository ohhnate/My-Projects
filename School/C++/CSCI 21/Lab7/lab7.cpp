// Lab 7 -- std::string/std::vector
// Unit test

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "functions.h"

/*
 * Unit test. Do not alter.
 */
TEST_CASE("Function implementations") {
  SECTION("Empty string") {
    CHECK(toupper("") == string(""));
    CHECK(tolower("") == string(""));
    CHECK(digits("") == 0);
    CHECK(punctuation("") == 0);
    CHECK(vowels("") == 0);
  }

  SECTION("Simple strings") {
    CHECK(toupper("abc") == string("ABC"));
    CHECK(tolower("ABC") == string("abc"));
    CHECK(digits("123") == 3);
    CHECK(punctuation(",.;") == 3);
    CHECK(vowels("aeiou") == 5);
  }

  SECTION("Harder strings") {
    CHECK(toupper("AbCd1.2,3;") == string("ABCD1.2,3;"));
    CHECK(tolower("AbCd1.2,3;") == string("abcd1.2,3;"));
    CHECK(digits("AbCd1.2,3;") == 3);
    CHECK(punctuation("AbCd1.2,3;") == 3);
    CHECK(vowels("AbCd1.2,3;") == 1);
  }

  SECTION("Empty file") {
    vector<string> vtest = readFile("nothere.txt");
    CHECK(vtest.size() == 0);
  }

  SECTION("Wordlist file") {
    vector<string> vtest = readFile("wordlist.txt");
    CHECK(vtest.size() == 50);
    CHECK(allCharacters(vtest) == 376);
    CHECK(allDigits(vtest) == 3);
    CHECK(allPunctuation(vtest) == 3);
    CHECK(allVowels(vtest) == 127);
  }
}
