#include "functions.h"

vector<string> readFile(string filename) {
  string nextline;
  vector<string> lines;
  ifstream fin(filename);
  if(fin.is_open()) {
    while(getline(fin, nextline)) {
      lines.push_back(nextline);
  }
    fin.close();
  }
  return lines;
}

string toupper(string input) {
  for (char &c : input) {
    c = toupper(c);
  }
  return input;
}

string tolower(string input) {
  for (char &c : input) {
    c = tolower(c);
  }
  return input;
}

unsigned int digits(string input) {
  unsigned int dCount(0);
  for (const char &i : input) {
    if (isdigit(i)) {
      dCount++;
    }
  }
  return dCount;
}

unsigned int punctuation(string input) {
    unsigned int pCount(0);
    for (const char &i : input) {
      if (ispunct(i)) {
        pCount++;
      }
    }
    return pCount;
}

unsigned int vowels(string input) {
  unsigned int vCount(0);
  string vowels("aAeEiIoOuU");
  for (const char &i : input) {
    for (const char &c : vowels) {
      if (i == c) {
        vCount++;
      }
    }
  }
  return vCount;
}

unsigned int allCharacters(const vector<string>& v) {
  unsigned int cCount(0);
  for (const string &s : v) {
    for (const char &c : s) {
      cCount++;
    }
  }
  return cCount;
}

unsigned int allDigits(const vector<string>& v) {
  unsigned int dCount(0);
  for (const string &s : v) {
    dCount += digits(s);
  }
  return dCount;
}

unsigned int allPunctuation(const vector<string>& v) {
  unsigned int pCount(0);
  for (const string &s : v) {
    pCount += punctuation(s);
  }
  return pCount;
}

unsigned int allVowels(const vector<string>& v) {
  unsigned int vCount(0);
  for (const string &s : v) {
    vCount += vowels(s);
  }
  return vCount;
}
