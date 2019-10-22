//string* pStr; - uninitialized pointer
//string* pStr(nullptr); - initialized pointer
  //if (pStr != nullptr){} - nullptr allows you to use conditionals

//string str; - Static

//pStr = new string; - Dynamic
//pStr = new string("Apple"); - Dynamic

//cout << pStr->size(); - dereference
//cout << (*pStr).size(); - dereference

//*pStr = "orange"; - reassign

//cout << (*pStr) [0]; - first character dereference
//cout << pStr->at(1); - first character dereference

//for (char c: *pStr) {}

//delete pStr; - removes pStr from memory
//pStr = nullptr; - null out after removing from memory

//pStr = new string[10]; - allocating array of strings in memory

#include <iostream>
#include <string>
using namespace std;

struct Box {
  double weight;
  string contents;

  Box() { cerr << "Box created" << endl; }
  Box(const Box& b) { cerr << "Box copy created" << endl; }

  ~Box() { cerr << "Box destroyed" << endl; }
};

void printBox(Box b){
  cout << "box being printed" << endl;
}

int main() {

  Box b1;
  Box *pBox(nullptr);

  printBox(b1);

  pBox = new Box;
  printBox(*pBox);
  delete pBox;
  pBox = nullptr;

  return 0;
}
