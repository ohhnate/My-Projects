
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <vector>

using std::cout;
using std:: endl;
using std::ifstream;
using std::string;
using std::istringstream;
using std::stringstream;
using std::vector;
using std::logic_error;

template <typename T>
class DList {
public:
  // Default constructor.
  // Initializes head to nullptr, size to 0.
  DList() {
    this->head = nullptr;
    this->tail = nullptr;
    size = 0;
  }

  // Destructor.
  // Invokes clear to free the memory associated with all nodes in the list.
  ~DList() {
    clear();
  }
  
  // Create a new node to contain value and insert the node
  // at the head of this DList. Increases the size by 1.
  void pushFront(T data) {
    Node* node = new Node(data);
    if (this->head == nullptr) {
      this->head = node;
      this->tail = node;
    } else {
      node->next = this->head;
      this->head->prev = node;
      this->head = node;
      this->size++;
    }
  }

  // Remove the head node.
  // Throws std::logic_error("EMPTY LIST") when list is empty
  void popFront() noexcept(false) {
    if (this->head == nullptr) {
    throw std::logic_error("EMPTY LIST");
  }
    Node* temp = this->head;
    this->head = this->head->next;
    delete temp;
    this->size--;
  }

  // Return the value stored in the head Node.
  // Throws std::logic_error("EMPTY LIST") when list is empty
  T front() noexcept(false) {
    if (this->head == nullptr){
		throw std::invalid_argument("NULL STRING POINTER");
	 }
    return this->head->data;
  }
  
  // Free the memory associated with all nodes in the list.
  // Resets head to nullptr and size to 0.
  void clear() {
    while(this->head != nullptr) {
      popFront();
    }
  }
  
  string toString() const {
    stringstream strout;
    Node* temp = this->head;
    while(temp != nullptr) {
      strout << temp->value;
      temp = temp->next;
      if (temp != nullptr) {
        strout << ",";
      }
    }
    return strout.str();
  }
  
private:
  unsigned int size; // the number of nodes in this list

  // A doubly-linked list node with a pointer to next and a data field.
  // Implements a constructor to initialize the data field to a param value
  // and the pointer to nullptr.
  struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(T data) {
      this->data = data;
      this->prev = nullptr;
      this->next = nullptr;
    }
  } *head, *tail; // a pointer to the first and last node in the list
};

void textOutput(string output) {
  cout << output << endl;
}

string commandIterator(string command) {
  vector<string> result;
  istringstream iss(command);
  for(command; iss >> command;) {
    result.push_back(command);
  }
  return result[1];
}

void commandController(string command) {
  std::transform(command.begin(), command.end(), command.begin(), ::tolower);
  if (command.at(0) == '#') {
    textOutput(command);
  } else if (command.at(0) == 'c') {
      DList<::pushFront(0);
      textOutput("LIST CREATED");
  } else if (command.at(0) == 'x') {
      DList::clear();
      textOutput("LIST CLEARED");
  } else if (command.at(0) == 'd') {
      textOutput("LIST DELETED");
  } else if (command.at(0) == 'i') {
      textOutput("VALUE n INSERTED");
  } else if (command.at(0) == 'f') {
      textOutput("VALUE N ADDED TO HEAD");
  } else if (command.at(0) == 'b') {
      textOutput("VALUE N ADDED TO TAIL");
  } else if (command.at(0) == 'e') {
      textOutput("VALUE N ELIMINATED OR NOT FOUND");
  } else if (command.at(0) == 'r') {
      textOutput("VALUE N REMOVED OR NOT FOUND");
  } else if (command.at(0) == 'g') {
      textOutput("VALUE N FOUND OR NOT FOUND");
  } else if (command.at(0) == 'a') {
      textOutput("VALUE N AT HEAD OR LIST EMPTY");
  } else if (command.at(0) == 'z') {
      textOutput("VALUE N AT TAIL OR LIST EMPTY");
  } else if (command.at(0) == 't') {
      textOutput("REMOVED HEAD OR LIST EMPTY");
  } else if (command.at(0) == 'k') {
      textOutput("REMOVED TAIL OR LIST EMPTY");
  } else if (command.at(0) == 'n') {
      textOutput("LIST SIZE IS N");
  } else if (command.at(0) == 'p') {
      textOutput("N1, N2, N3, OR LIST EMPTY");
  } else {
    textOutput("INVALID COMMAND");
  }
}

int main(int argc, char *argv[]) {
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
            commandController(nextline);
          }
          fin.close();
      }
    }
return 0;
}