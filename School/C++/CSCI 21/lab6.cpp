// Lab 6 -- argc and argv, file input
//
// Programmer name: Samuel Fuller
// Date completed: 1 Oct 2019

#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <sstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::istringstream;


struct Item {
  string name;
  unsigned int quantity;
};

void printItem(const Item &item) {
  cout << item.name << ", quantity: " << item.quantity << endl;
}

// void initItem(Item &item, string name, int quantity) {
//   item.name = name;
//   item.quantity = quantity;
// }

// Add functions as wanted/needed to help with file processing
//
// void stringSplit(char str[], Item &item) {
//
//   char * token;
//   token = strtok(str, ":");
//   item.name = token;
// }

int main(int argc, char *argv[]) {

  Item item;
  // If a filename argument has been passed via argv,
  // attempt to open the file and read its contents.
  //
  // Absence of a filename via argv should produce an error message.
  // A non-existent file should produce an error message.
  //
  if (argc != 2) {
    cout << "Usage " << argv[0] << " FILENAME" << endl;
  } else {
      ifstream fin(argv[1]);
      if (!fin.is_open()) {
        cout << "Unable to open " << argv[1] << " for input" << endl;
      } else {
          string nextline;
          string name;
          string quantity;
          while(getline(fin, nextline)) {
            istringstream iss(nextline);
            getline(iss, name, ':');
            getline(iss, quantity, ':');
            item.name = name;
            item.quantity = stoi(quantity);
            printItem(item);
          }
          fin.close();
      }
  }

  // If the file can be opened, assume that it has an unknown
  // number of lines, with each line containing a NAME:QUANTITY
  // pair. (ex., "apples:10")
  //
  // Parse each line and populate the data fields in item,
  // then pass item to the printItem function. The output
  // of the function serves as confirmation that file and data
  // processing are functioning properly.

  return 0;
}
