// Final -- hash table
// unittest.cpp

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "hash_table.h"

#include <array>
#include <sstream>
using std::array;
using std::stringstream;

TEST_CASE ("hash function and hash table functionality") {
	array<Item, 15> items = {
	    Item("apple"),
	    Item("banana"),
	    Item("grape"),
	    Item("lemon"),
	    Item("melon"),
	    Item("orange"),
	    Item("strawberry"),
	    Item("pear"),
	    Item("blueberry"),
	    Item("grapefruit"),
	    Item("apple"),
	    Item("banana"),
	    Item("grape"),
	    Item("lemon"),
	    Item("melon")
	};
	HashTable ht;

	CHECK(ht.size() == 0);
	CHECK(ht.printDetail() ==
		"Items in hash table: 0\n[0]\t\n[1]\t\n[2]\t\n[3]\t\n[4]\t\n");

	CHECK(ht.hash(items[0]) == 0);
	CHECK(ht.hash(items[4]) == 4);
	CHECK(ht.hash(items[8]) == 2);
	CHECK(ht.hash(items[12]) == 2);
	CHECK(ht.hash(items[14]) == 4);

	for (Item i : items) {
		ht.insert(i);
	}

	CHECK(ht.size() == 10);

	stringstream output;
	output << "Items in hash table: 10\n" << "[0]\t     apple (2) \n";
	output << "[1]\t    orange (1) grapefruit (1) \n" << "[2]\t     grape (2)  blueberry (1) \n";
	output << "[3]\t\n";
	output << "[4]\t    banana (2)      lemon (2)      melon (2) strawberry (1)       pear (1) \n";
	CHECK(ht.printDetail() == output.str());

	Item* tempItem = ht.getItem("shoe");
	CHECK(tempItem == nullptr);

	tempItem = ht.getItem("apple");
	CHECK(tempItem != nullptr);
	CHECK(tempItem->count == 2);

	tempItem = ht.getItem("pear");
	CHECK(tempItem != nullptr);
	CHECK(tempItem->count == 1);

	CHECK(ht.remove("shoe") == false);

	CHECK(ht.remove("apple") == true);
	CHECK(ht.size() == 9);

	CHECK(ht.remove("apple") == false);

	CHECK(ht.remove("orange") == true);
	CHECK(ht.remove("grapefruit") == true);
	CHECK(ht.remove("grape") == true);
	CHECK(ht.remove("blueberry") == true);
	CHECK(ht.remove("banana") == true);
	CHECK(ht.remove("lemon") == true);
	CHECK(ht.remove("melon") == true);
	CHECK(ht.remove("strawberry") == true);
	CHECK(ht.remove("pear") == true);

	CHECK(ht.size() == 0);
}
