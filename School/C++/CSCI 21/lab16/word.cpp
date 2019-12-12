#include "word.h"

// Default constructor.
// Initialize the Word with empty string and 1 count.
Word::Word() {
  word = "";
  count = 1;
};

// Overloaded constructor.
// Initialize the Word with the string param and 1 count. Converts
// the string param to all upper-case.
Word::Word(string word) {
  this->word = upper(word);
  this->count = 1;
}

// Set this Word's string attribute to the string param. Converts the
// string to all upper-case.
void Word::setWord(string word) {
  this->word = upper(word);
}

// Return this Word's string attribute.
string Word::getWord() const {
  return this->word;
}

// Return this Word's integer attribute.
unsigned int Word::getCount() const {
  return this->count;
}

// Add 1 to this Word's integer attribute.
void Word::incrementCount() {
  this->count++;
}

// Returns true if the string attributes of the two Word objects are equivalent.
// Case-insensitive.
bool Word::operator==(const Word &target) {
  if(this->word == target.word) {
    return true;
  }
  return false;
}

// Returns true if this Word object's string attribute comes (lexicographically)
// after the target Word's string attribute. Case-insensitive.
bool Word::operator>(const Word &target) {
  if(this->word > target.word) {
    return true;
  }
  return false;
}

// Returns true if this Word object's string attribute comes (lexicographically)
// before the target Word's string attribute. Case-insensitive.
bool Word::operator<(const Word &target) {
  if(this->word < target.word) {
    return true;
  }
  return false;
}

// Example: APPLE 3
// Places a string representation of the Word on an output stream.
ostream &operator<<(ostream &outs, const Word &src) {
  outs << src.word << " " << src.count;
  return outs;
}

// Helper function. Return the string param in all upper-case.
string Word::upper(string s) {
  transform(s.begin(), s.end(), s.begin(), ::toupper);
  return s;
}
