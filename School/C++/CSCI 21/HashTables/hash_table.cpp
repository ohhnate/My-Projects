// Final -- hash table
// hash_table.cpp

#include "hash_table.h"

/*
 * Insert an item into the hash table.
 * @param i the Item to be inserted
 */
void HashTable::insert(Item i) {
  Item *got = getItem(i.contents);
  if(got == nullptr) {
    this->items[hash(i)].push_back(i);
  } else {
    got->count++;
  }
}

/*
 * Remove an item from the hash table.
 * @param contents the contents of the Item to remove
 * @return true if an Item with the contents was removed, or false if no matching Item is found
 */
bool HashTable::remove(string contents) {
  unsigned int i = hash(contents);
  if(getItem(contents) == nullptr) {
    return false;
  }
  for (auto it = items[i].begin(); it != items[i].end(); it++) {
    if(it->contents == contents) {
      items[i].erase(it);
      return true;
    }
  }
  return false;
}

/*
 * Return a pointer to an Item in the hash table, by contents.
 * @param contents the contents of the Item to return
 * @return a pointer to the Item with the contents, or nullptr if no Item matches the contents
 */
Item HashTable::*getItem(string contents) {
  for(list<Item> &l : items) {
    for(Item& i : l) {
      if(i.contents == contents) {
        return &i;
      }
    }
  }
  return nullptr;
}

/*
 * Return the number of items currently stored in the hash table.
 * @return the number of items stored in the hash table
 */
unsigned int HashTable::size() {
  unsigned int count = 0;
  for(list<Item> l : items) {
    count += list.size();
  }
  return count;
}

/*
 * Compute the hash value for an Item object. Uses the string contents
 * member of Item to compute the hash. Uses the private hash function on
 * string contents.
 * @param Item the Item for which to compute the hash
 * @return the hash computed by the private hash function
 */
unsigned int HashTable::hash(Item i) {
  return hash(i.contents);
}

/*
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
string HashTable::printDetail() {
  stringstream ss;
  ss << "Items in hash table: " << size() << "\n";
  for(int i(0); i < items.size(); i++) {
    ss << "[" << i << "]\t";
    for(Item j : items[i]) {
      ss << j.contents << "(" << j.count; << ") ";
    }
    ss << endl;
  }
  return ss.str();
}

/*
 * Compute a hash value (unsigned integer) by summing the ASCII values
 * of the characters in a string and modding to fit the hash table size.
 * @param s the string to hash
 * @return the hash value for the string
 */
unsigned int HashTable::hash(string s) {
  unsigned int sum = 0;
  for (char c : data) {
    sum += c;
  }
  return sum % items.size();
}
