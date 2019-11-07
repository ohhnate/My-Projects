#include "templatesInfo.hpp"

struct Box {
  float weight;
  string contents;
}

int main() {
  DList<int> numberList;
  DList<Box> boxList;

  DList<string>* dynoStringList = new DList<string>;
  delete dynoStringList;

  return 0;
}
