// Lab 7 -- STL string/vector
//
// Programmer name: Samuel Fuller
// Date last modified: 8 Oct 2019

#pragma once

#include <cctype>
#include <fstream>
#include <string>
#include <vector>
using std::ifstream;
using std::string;
using std::vector;

// FILE PROCESSING

// Read each line of a file into a vector.
vector<string> readFile(string filename);

// STRING PROCESSING -- ALL CASE-INSENSITIVE

// Return input with all characters in uppercase.
string toupper(string input);

// Return input with all characters in lowercase.
string tolower(string input);

// Return a count of all digits in the input.
unsigned int digits(string input);

// Return a count of all punctuation characters in the input.
unsigned int punctuation(string input);

// Return a count of all vowels (AEIOU) in the input.
unsigned int vowels(string input);

// VECTOR PROCESSING FUNCTIONS

// Compute total number of characters of all strings in a vector.
unsigned int allCharacters(const vector<string>& v);

// Compute total number of digits in all strings in a vector.
unsigned int allDigits(const vector<string>& v);

// Compute total number of punctuation characters in all strings
// in a vector.
unsigned int allPunctuation(const vector<string>& v);

// Compute total number of vowels in all strings in a vector.
unsigned int allVowels(const vector<string>& v);
