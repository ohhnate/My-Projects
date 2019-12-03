#include "bst.hpp"
#include "word.hpp"

int main(int argc, char *argv[]) {
  BSTree<unsigned int> *tree = nullptr;
  bool treeInstance = false;
  unsigned int value = 0;

  if (argc != 2) {
    cout << "Usage: " << argv[0] << " FILENAME" << endl;
  } else {
      ifstream fin(argv[1]);
      if (!fin.is_open()) {
        cout << "Unable to open " << argv[1] << " for input" << endl;
      } else {
          string nextline;
          while(getline(fin, nextline)) {
            istringstream iss(nextline);
            value = commandIterator(nextline);
            std::transform(nextline.begin(), nextline.end(), nextline.begin(), ::tolower);
            if (nextline.at(0) == '#') {
            } else if (nextline.at(0) == 'c') {
                if(treeInstance == true) {
                  tree->clear();
                  delete tree;
                  tree = nullptr;
                }
                tree = new BSTree<unsigned int>;
                treeInstance = true;
                cout << "TREE CREATED" << endl;
            } else if (nextline.at(0) == 'x') {
                if (treeInstance == false) {
                  cout << "MUST CREATE TREE INSTANCE" << endl;
                } else {
                  tree->clear();
                  cout << "TREE CLEARED" << endl;
                }
            } else if (nextline.at(0) == 'd') {
                if (treeInstance == false) {
                  cout << "MUST CREATE TREE INSTANCE" << endl;
                } else {
                  tree->clear();
                  delete tree;
                  tree = nullptr;
                  treeInstance = false;
                  cout << "TREE DELETED" << endl;
                }
            } else if (nextline.at(0) == 'i') {
                if (treeInstance == false) {
                  cout << "MUST CREATE TREE INSTANCE" << endl;
                } else {
                  tree->insert(value);
                }
            } else if (nextline.at(0) == 'f') {
                if (treeInstance == false) {
                  cout << "MUST CREATE TREE INSTANCE" << endl;
                } else {
                  tree->findWord(value);
                }
            } else if (nextline.at(0) == 'r') {
                if (treeInstance == false) {
                  cout << "MUST CREATE TREE INSTANCE" << endl;
                } else {
                  if (tree->removeFirst(value) == true) {
                    textOutput("VALUE REMOVED", value);
                  } else {
                    textOutput("VALUE NOT FOUND", value);
                  }
                }
            } else if (nextline.at(0) == 'g') {
                if (treeInstance == false) {
                  cout << "MUST CREATE TREE INSTANCE" << endl;
                } else {
                  if (tree->getNumber(value) == false) {
                    textOutput("VALUE NOT FOUND", value);
                  } else {
                    textOutput("VALUE FOUND", value);
                  }
                }
            } else if (nextline.at(0) == 'n') {
                if (treeInstance == false) {
                  cout << "MUST CREATE TREE INSTANCE" << endl;
                } else {
                  cout << tree->getSize() << endl;
                }
            } else if (nextline.at(0) == 'o') {
                if (treeInstance == false) {
                  cout << "MUST CREATE TREE INSTANCE" << endl;
                } else {
                  cout << tree->printInOrder() << endl;
                }
            } else if (nextline.at(0) == 'e') {
                if (treeInstance == false) {
                  cout << "MUST CREATE TREE INSTANCE" << endl;
                } else {
                  cout << tree->printReverse() << endl;
                }
            } else {
              cout << "INVALID NEXTLINE" << endl;
            }
          }
          fin.close();
      }
    }
return 0;
}
