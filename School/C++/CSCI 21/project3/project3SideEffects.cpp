//DONT WRITE CODE LIKE THIS

// #include <iostream>
// using namespace std;
//
// //returns the result of x + y.
// int add(int x, int y) {
//   int result = x + y;
//
//   cout << x << " + " << y << " = " << endl;
//
//   return result;
// }
//
// int main() {
//   int result = add(1, 2);
//   return 0;
// }


#pragma once

template <typename T>
class DList {
  DList() {
    cout << "LIST CREATED" << endl;
    head = tail = nullptr;
    cout = 0;
  }

  bool find(T target) {
    if (found == true) {
      cout << "FOUND" << target << endl;
      return found;
    }
  }
};

int main() {
  DList<int> list;

  list.find(10);

  return 0;
}

