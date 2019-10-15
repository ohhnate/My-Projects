#include "WordList.h"

// Add a word to the words vector.
void WordList::addWord(string word) {
  words.push_back(word);
}

// Remove a word from the words vector.
// Return true on success.
bool WordList::removeWord(string word) {
  bool contains = false;
  for (vector<string>::iterator i = words.begin(); i != words.end();) {
    if (*i == word) {
      words.erase(i);
      contains = true;
    } else {
      i++;
    }
  }
  return contains;
}

// Return true if the words vector contains the word.
bool WordList::hasWord(string word) {
  for (string i : words) {
    if (i == word) {
      return true;
    }
  }
  return false;
}

// Return the number of words, i.e., size of the vector.
unsigned int WordList::getWordCount() {
  return words.size();
}

// Clear all of the contents of the list.
void WordList::clear() {
  words.erase(words.begin(), words.end());
}

// Return a string representation of the word list.
// String will contain a numbered list, one word per line.
/*
 * EXAMPLE:
 *
 * [1] apple
 * [2] grapefruit
 * [3] orange
 *
 */
string WordList::toString() {
  ostringstream strout;
  int count = 0;
  for (string i : words) {
    count++;
    strout << "["<< count << "] " << i <<"\n";
  }
  return strout.str();
}
