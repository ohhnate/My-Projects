// Lab 14 -- binary search tree
// Unit test

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "bstree.hpp"

#include <iostream>
#include <sstream>
#include <string>
using std::cout;
using std::ostringstream;
using std::streambuf;
using std::string;

/*
 * Unit tests. Do not alter.
 */
TEST_CASE("Binary Search Tree (int)") {

  streambuf *oldCout = cout.rdbuf();
  ostringstream captureCout;

  SECTION("BSTree<int> -- EMPTY") {
    BSTree<int> tree;

    CHECK(tree.getSize() == 0);

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printInOrder();
    cout.rdbuf(oldCout);
    CHECK(captureCout.str() == string(""));
  }

  SECTION("BSTree<int> -- ONE ITEM") {
    BSTree<int> tree;

    CHECK(tree.insert(100) == true);

    CHECK(tree.getSize() == 1);

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printInOrder();
    cout.rdbuf(oldCout);
    CHECK(captureCout.str() == string("100\n"));

    CHECK(tree.insert(100) == false);

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printInOrder();
    cout.rdbuf(oldCout);
    CHECK(captureCout.str() == string("100\n"));
  }

  SECTION("BSTree<int> -- MULTIPLE ITEMS") {
    BSTree<int> tree;

    tree.insert(100);
    tree.insert(50);
    tree.insert(150);
    tree.insert(25);
    tree.insert(75);
    tree.insert(125);
    tree.insert(175);

    CHECK(tree.getSize() == 7);

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printInOrder();
    cout.rdbuf(oldCout);
    CHECK(captureCout.str() == string("25\n50\n75\n100\n125\n150\n175\n"));

    CHECK(tree.insert(25) == false);
    CHECK(tree.insert(50) == false);
    CHECK(tree.insert(75) == false);
    CHECK(tree.insert(100) == false);
    CHECK(tree.insert(125) == false);
    CHECK(tree.insert(150) == false);
    CHECK(tree.insert(175) == false);
    CHECK(tree.getSize() == 7);

    tree.clear();
    CHECK(tree.getSize() == 0);

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printInOrder();
    cout.rdbuf(oldCout);
    CHECK(captureCout.str() == string(""));
  }
}
