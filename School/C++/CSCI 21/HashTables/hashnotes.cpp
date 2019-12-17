#include <array>
#include <iostream>
using namespace std;

unsigned int hash(string data, unsigned int max) {
  //return data.size();
  unsigned int sum = 0;
  for (char c : data) {
    sum += c;
  }
  return sum % max;
}

int main() {
  array<vector<string>, 10> database;

  string s1("cat");
  string s2("rat");

  // database[hash(s1, array.size())] = s1;
  //
  // database[hash(s2, array.size())] = s2;
  //
  // cout << "cat ->" << database[hash("cat")] << endl;
  // cout << "rat ->" << database[hash("rat")] << endl;

  // cout << s1 << " hashes to " << hash(s1, array.size()) << endl;

  database[hash(s1, database.size())].push_back(s1);

  return 0;
}
