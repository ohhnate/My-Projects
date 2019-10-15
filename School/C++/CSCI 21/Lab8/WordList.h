// Lab 8 -- WordList with std::vector
//
// Programmer name: Samuel Fuller
// Date completed:  15 Oct 2019

#include <sstream>
#include <string>
#include <vector>
using std::ostringstream;
using std::string;
using std::vector;

class WordList {
public:
  // Add a word to the words vector.
  void addWord(string word);

  // Remove a word from the words vector.
  // Return true on success.
  bool removeWord(string word);

  // Return true if the words vector contains the word.
  bool hasWord(string word);

  // Return the number of words, i.e., size of the vector.
  unsigned int getWordCount();

  // Clear all of the contents of the list.
  void clear();

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
  string toString();

private:
  vector<string> words;
};
