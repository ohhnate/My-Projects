// Lab 16 -- overloading operators
// unittest.cpp

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "bstree.hpp"
#include "word.h"

#include <iostream>
#include <sstream>
using std::cout;
using std::ostringstream;
using std::streambuf;

/*
 * Unit tests. Do not alter.
 */
TEST_CASE("Word class") {

  ostringstream outs;

  SECTION("Default constructor") {
    Word word1;

    CHECK(word1.getWord() == string(""));
    CHECK(word1.getCount() == 1);

    outs << word1;
    CHECK(outs.str() == string(" 1"));
    outs.str("");

    word1.setWord("apple");
    CHECK(word1.getWord() == string("APPLE"));

    word1.incrementCount();
    CHECK(word1.getCount() == 2);

    outs << word1;
    CHECK(outs.str() == string("APPLE 2"));
    outs.str("");
  }

  SECTION("Overloaded constructor") {
    Word word1("apple");

    CHECK(word1.getWord() == string("APPLE"));
    CHECK(word1.getCount() == 1);

    outs << word1;
    CHECK(outs.str() == string("APPLE 1"));
    outs.str("");
  }

  SECTION("Overloaded operators") {
    Word word1("apple");
    Word word2("banana");

    CHECK((word1 > word2) == false);
    CHECK((word1 < word2) == true);
    CHECK((word1 == word2) == false);

    word2.setWord("apple");

    CHECK((word1 == word2) == true);
  }
}

TEST_CASE("Binary Search Tree (Word)") {
  streambuf *oldCout = cout.rdbuf();
  ostringstream captureCout;

  BSTree<Word> tree;

  tree.insert(Word("banana"));
  tree.insert(Word("apple"));
  tree.insert(Word("orange"));

  CHECK(tree.getSize() == 3);

  captureCout.str("");
  cout.rdbuf(captureCout.rdbuf());
  tree.printInOrder();
  cout.rdbuf(oldCout);
  CHECK(captureCout.str() == string("APPLE 1\nBANANA 1\nORANGE 1\n"));

  captureCout.str("");
  cout.rdbuf(captureCout.rdbuf());
  tree.printReverseOrder();
  cout.rdbuf(oldCout);
  CHECK(captureCout.str() == string("ORANGE 1\nBANANA 1\nAPPLE 1\n"));

  Word *w = tree.get(Word("apple"));
  w->incrementCount();
  w->incrementCount();

  w = tree.get(Word("orange"));
  w->incrementCount();

  captureCout.str("");
  cout.rdbuf(captureCout.rdbuf());
  tree.printInOrder();
  cout.rdbuf(oldCout);
  CHECK(captureCout.str() == string("APPLE 3\nBANANA 1\nORANGE 2\n"));

  CHECK(tree.insert(Word("apple")) == false);
}
