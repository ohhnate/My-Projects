// Project 4 
// Word class and implementation
//
// Programmer name: Samuel Fuller
// Last modified:  28 Nov 2019

#pragma once

#include <algorithm>
#include <iostream>
#include <string>
using std::ostream;
using std::string;

class Word {
public:
  // Default constructor.
  // Initialize the Word with empty string and 1 count.
  Word() {
    
  }

  // Overloaded constructor.
  // Initialize the Word with the string param and 1 count. Converts
  // the string param to all upper-case.
  Word(string word) {
    
  }

  // Set this Word's string attribute to the string param. Converts the
  // string to all upper-case.
  void setWord(string word) {
    
  }

  // Return this Word's string attribute.
  string getWord() const {
    
  }

  // Return this Word's integer attribute.
  unsigned int getCount() const {
    
  }

  // Add 1 to this Word's integer attribute.
  void incrementCount() {
    
  }

  // Returns true if the string attributes of the two Word objects are equivalent.
  // Case-insensitive.
  bool operator==(const Word &target) {
    
  }

  // Returns true if this Word object's string attribute comes (lexicographically)
  // after the target Word's string attribute. Case-insensitive.
  bool operator>(const Word &target) {
    
  }

  // Returns true if this Word object's string attribute comes (lexicographically)
  // before the target Word's string attribute. Case-insensitive.
  bool operator<(const Word &target) {
    
  }

  // Example: APPLE 3
  // Places a string representation of the Word on an output stream.
  friend ostream &operator<<(ostream &outs, const Word &src) {
    
  }

private:
  string word;
  unsigned int count;

  // Helper function. Return the string param in all upper-case.
  string upper(string s);
};
