// Lab 15 -- binary search tree
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
    CHECK(tree.find(1) == false);
    CHECK(tree.get(1) == nullptr);
    CHECK(tree.remove(1) == false);

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printInOrder();
    cout.rdbuf(oldCout);
    CHECK(captureCout.str() == string(""));

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printReverseOrder();
    cout.rdbuf(oldCout);
    CHECK(captureCout.str() == string(""));
  }

  SECTION("BSTree<int> -- ONE ITEM") {
    BSTree<int> tree;

    CHECK(tree.insert(100) == true);

    CHECK(tree.getSize() == 1);
    CHECK(tree.find(100) == true);

    int *t = tree.get(100);
    CHECK(t != nullptr);
    CHECK(*t == 100);

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printInOrder();
    cout.rdbuf(oldCout);

    CHECK(captureCout.str() == string("100\n"));

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printReverseOrder();
    cout.rdbuf(oldCout);
    CHECK(captureCout.str() == string("100\n"));

    CHECK(tree.insert(100) == false);

    CHECK(tree.remove(100) == true);
    CHECK(tree.getSize() == 0);
    CHECK(tree.find(100) == false);
    CHECK(tree.get(100) == nullptr);
    CHECK(tree.remove(100) == false);

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printInOrder();
    cout.rdbuf(oldCout);
    CHECK(captureCout.str() == string(""));

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printReverseOrder();
    cout.rdbuf(oldCout);
    CHECK(captureCout.str() == string(""));
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

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printReverseOrder();
    cout.rdbuf(oldCout);
    CHECK(captureCout.str() == string("175\n150\n125\n100\n75\n50\n25\n"));

    CHECK(tree.insert(25) == false);
    CHECK(tree.insert(50) == false);
    CHECK(tree.insert(75) == false);
    CHECK(tree.insert(100) == false);
    CHECK(tree.insert(125) == false);
    CHECK(tree.insert(150) == false);
    CHECK(tree.insert(175) == false);
    CHECK(tree.getSize() == 7);

    CHECK(tree.remove(25) == true);
    CHECK(tree.getSize() == 6);

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printInOrder();
    cout.rdbuf(oldCout);
    CHECK(captureCout.str() == string("50\n75\n100\n125\n150\n175\n"));

    CHECK(tree.remove(125) == true);
    CHECK(tree.getSize() == 5);

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printReverseOrder();
    cout.rdbuf(oldCout);
    CHECK(captureCout.str() == string("175\n150\n100\n75\n50\n"));

    CHECK(tree.remove(100) == true);
    CHECK(tree.getSize() == 4);

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printInOrder();
    cout.rdbuf(oldCout);
    CHECK(captureCout.str() == string("50\n75\n150\n175\n"));

    CHECK(tree.remove(75) == true);
    CHECK(tree.getSize() == 3);

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printReverseOrder();
    cout.rdbuf(oldCout);
    CHECK(captureCout.str() == string("175\n150\n50\n"));

    CHECK(tree.remove(150) == true);
    CHECK(tree.getSize() == 2);

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printInOrder();
    cout.rdbuf(oldCout);
    CHECK(captureCout.str() == string("50\n175\n"));

    CHECK(tree.remove(50) == true);
    CHECK(tree.getSize() == 1);

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printReverseOrder();
    cout.rdbuf(oldCout);
    CHECK(captureCout.str() == string("175\n"));

    CHECK(tree.remove(50) == false);
    CHECK(tree.find(50) == false);
    CHECK(tree.get(50) == nullptr);

    CHECK(tree.remove(175) == true);
    CHECK(tree.getSize() == 0);

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printInOrder();
    cout.rdbuf(oldCout);
    CHECK(captureCout.str() == string(""));

    tree.insert(100);
    tree.insert(50);
    tree.insert(150);
    tree.insert(25);
    tree.insert(75);
    tree.insert(125);
    tree.insert(175);
    tree.clear();
    CHECK(tree.getSize() == 0);

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printInOrder();
    cout.rdbuf(oldCout);
    CHECK(captureCout.str() == string(""));
  }
}
