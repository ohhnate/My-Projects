#include "DList.hpp"

// function to consolidate and format text from the commands
void textOutput(string output, unsigned int value) {
  if (value == 9000) {
    cout << output << endl;
  } else if (output == "VALUE ADDED TO HEAD") {
    cout << "VALUE " << value << " ADDED TO HEAD" << endl;
  } else if (output == "VALUE ADDED TO TAIL") {
    cout << "VALUE " << value << " ADDED TO TAIL"  << endl;
  } else if (output == "VALUE ELIMINATED") {
    cout << "VALUE " << value << " ELIMINATED" << endl;
  } else if (output == "VALUE NOT FOUND") {
    cout << "VALUE " << value << " NOT FOUND" << endl;
  } else if (output == "VALUE INSERTED") {
    cout << "VALUE " << value << " INSERTED" << endl;
  } else if (output == "VALUE NOT FOUND") {
    cout << "VALUE " << value << " NOT FOUND" << endl;
  } else if (output == "VALUE FOUND") {
    cout << "VALUE " << value << " FOUND" << endl;
  } else if (output == "VALUE AT HEAD") {
    cout << "VALUE " << value << " AT HEAD" << endl;
  } else if (output == "VALUE AT TAIL") {
    cout << "VALUE " << value << " AT TAIL" << endl;
  } else if (output == "LIST EMPTY") {
    cout << "LIST EMPTY" << endl;
  } else if (output == "HEAD REMOVED") {
    cout << "REMOVED HEAD" << endl;
  } else if (output == "TAIL REMOVED") {
    cout << "REMOVED TAIL" << endl;
  } else if (output == "LIST SIZE") {
    cout << "LIST SIZE IS " << value << endl;
  } else if (output == "VALUE REMOVED") {
    cout << "VALUE " << value << " REMOVED" << endl;
  }
}
// commandIterator iterates over the text command and finds digits and converts
// them from strings to unsigned ints to be used as list values
int commandIterator(string command) {
  int value = 0;
  if (command.at(0) != '#') {
    if(command.size() > 2) {
      int pos = command.find(" ");
      int end = command.size();
      value = stoi(command.substr(pos, end));
    }
  }
  return value;
}

int main(int argc, char *argv[]) {
  DList<unsigned int> *list = nullptr;
  bool listInstance = false;
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
              textOutput(nextline, 9000);
            } else if (nextline.at(0) == 'c') {
                if(listInstance == true) {
                  list->clear();
                  delete list;
                  list = nullptr;
                }
                // Controll for all text commands. Was in function but had
                // issues so just put it all into main
                list = new DList<unsigned int>;
                listInstance = true;
                textOutput("LIST CREATED", 9000);
            } else if (nextline.at(0) == 'x') {
                if (listInstance == false) {
                  textOutput("MUST CREATE LIST INSTANCE", 9000);
                } else {
                  list->clear();
                  textOutput("LIST CLEARED", 9000);
                }
            } else if (nextline.at(0) == 'd') {
                if (listInstance == false) {
                  textOutput("MUST CREATE LIST INSTANCE", 9000);
                } else {
                  list->clear();
                  delete list;
                  list = nullptr;
                  listInstance = false;
                  cout << "LIST DELETED" << endl;
                }
            } else if (nextline.at(0) == 'i') {
                if (listInstance == false) {
                  textOutput("MUST CREATE LIST INSTANCE", 9000);
                } else {
                  list->insertNode(value);
                  textOutput("VALUE INSERTED", value);
                }
            } else if (nextline.at(0) == 'f') {
                if (listInstance == false) {
                  textOutput("MUST CREATE LIST INSTANCE", 9000);
                } else {
                  list->pushFront(value);
                  textOutput("VALUE ADDED TO HEAD", value);
                }
            } else if (nextline.at(0) == 'b') {
                if (listInstance == false) {
                  textOutput("MUST CREATE LIST INSTANCE", 9000);
                } else {
                  list->pushBack(value);
                  textOutput("VALUE ADDED TO TAIL", value);
                }
            } else if (nextline.at(0) == 'e') {
                if (listInstance == false) {
                  textOutput("MUST CREATE LIST INSTANCE", 9000);
                } else {
                  if (list->removeAllOccurrences(value) == true) {
                    textOutput("VALUE ELIMINATED", value);
                  } else {
                    textOutput("VALUE NOT FOUND", value);
                  }
                }
            } else if (nextline.at(0) == 'r') {
                if (listInstance == false) {
                  textOutput("MUST CREATE LIST INSTANCE", 9000);
                } else {
                  if (list->removeFirst(value) == true) {
                    textOutput("VALUE REMOVED", value);
                  } else {
                    textOutput("VALUE NOT FOUND", value);
                  }
                }
            } else if (nextline.at(0) == 'g') {
                if (listInstance == false) {
                  textOutput("MUST CREATE LIST INSTANCE", 9000);
                } else {
                  if (list ->getNumber(value) == false) {
                    textOutput("VALUE NOT FOUND", value);
                  } else {
                    textOutput("VALUE FOUND", value);
                  }
                }
            } else if (nextline.at(0) == 'a') {
                if (listInstance == false) {
                  textOutput("MUST CREATE LIST INSTANCE", 9000);
                } else {
                  if (list->listChecker() == false) {
                    textOutput("LIST EMPTY", value);
                  } else {
                    textOutput("VALUE AT HEAD", list->front());
                  }
                }
            } else if (nextline.at(0) == 'z') {
                if (listInstance == false) {
                  textOutput("MUST CREATE LIST INSTANCE", 9000);
                } else {
                  if (list->listChecker() == false) {
                    textOutput("LIST EMPTY", value);
                  } else {
                    textOutput("VALUE AT TAIL", list->back());
                  }
                }
            } else if (nextline.at(0) == 't') {
                if (listInstance == false) {
                  textOutput("MUST CREATE LIST INSTANCE", 9000);
                } else {
                  if (list->listChecker() == false) {
                    textOutput("LIST EMPTY", value);
                  } else {
                    list->popFront();
                    textOutput("HEAD REMOVED", value);
                  }
                }
            } else if (nextline.at(0) == 'k') {
                if (listInstance == false) {
                  textOutput("MUST CREATE LIST INSTANCE", 9000);
                } else {
                  if (list->listChecker() == false) {
                    textOutput("LIST EMPTY", value);
                  } else {
                    list->popBack();
                    textOutput("TAIL REMOVED", value);
                  }
                }
            } else if (nextline.at(0) == 'n') {
                if (listInstance == false) {
                  textOutput("MUST CREATE LIST INSTANCE", 9000);
                } else {
                  textOutput("LIST SIZE", list->listSize());
                }
            } else if (nextline.at(0) == 'p') {
                if (listInstance == false) {
                  textOutput("MUST CREATE LIST INSTANCE", 9000);
                } else {
                  cout << list->toString() << endl;
                }
            } else {
              textOutput("INVALID nextline", 9000);
            }
          }
          fin.close();
      }
    }
return 0;
}
