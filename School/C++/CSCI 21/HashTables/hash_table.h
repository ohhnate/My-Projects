// Final -- hash table
// hash_table.h

#pragma once

#include <array>
#include <iomanip>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
using std::array;
using std::endl;
using std::list;
using std::setw;
using std::string;
using std::stringstream;

/*
 * An Item to be stored in a HashTable.
 */
struct Item {
	Item (string newContents)
	: count(1), contents(newContents) {}

	unsigned int count;
	string contents;
};

/*
 * A class representing a hash table
 */
class HashTable {
	public:

		/**
		 * Insert an item into the hash table.
		 * @param i the Item to be inserted
		 */
		void insert(Item i);

		/**
		 * Remove an item from the hash table.
		 * @param contents the contents of the Item to remove
		 * @return true if an Item with the contents was removed, or false if no matching Item is found
		 */
		bool remove(string contents);

		/**
		 * Return a pointer to an Item in the hash table, by contents.
		 * @param contents the contents of the Item to return
		 * @return a pointer to the Item with the contents, or nullptr if no Item matches the contents
		 */
		Item* getItem(string contents);

		/**
		 * Return the number of items currently stored in the hash table.
		 * @return the number of items stored in the hash table
		 */
		unsigned int size();

		/**
		 * Compute the hash value for an Item object. Uses the string contents
		 * member of Item to compute the hash. Uses the private hash function on
		 * string contents.
		 * @param Item the Item for which to compute the hash
		 * @return the hash computed by the private hash function
		 */
		unsigned int hash(Item i);

		/**
		 * Display a detailed view of the contents of the hash table. Format should be as follows:
		 *
		 * Items in hash table: hash_table_size
		 * [array_index] item_contents (item_count)
		 *
		 * NOTE: insert a TAB character after [array_index] and output item_contents into a field of
		 *       width 10
		 *
		 * EXAMPLE:
		 *
		 * Items in hash table: 4
		 * [0]	     apple (1) banana (2)
		 * [1]
		 * [2]	 		 blueberry (1)
		 * [3]
		 * [4]	     pear (1)
		 *
		 * @return a string containing a detailed view of the contents of the hash table.
		 */
		string printDetail();

	private:
		array<list<Item>, 5> items;

		/**
		 * Compute a hash value (unsigned integer) by summing the ASCII values
		 * of the characters in a string and modding to fit the hash table size.
		 * @param s the string to hash
		 * @return the hash value for the string
		 */
		unsigned int hash(string s);
};
