#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdexcept>

using std::cout;
using std:: endl;
using std::ifstream;
using std::string;
using std::istringstream;
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
  
  *DList madeDynamicList() {
    Node* node(nullptr);
    node = new Node;
    return node;
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
  
  void textOutput(string output) {
    cout << output << endl;
  }
  
  void commandController(string command) {
    std::transform(command.begin(), command.end(), command.begin(), ::tolower);
    if (command.at(0) == '#') {
      textOutput(command);
    } else if (command.at(0) == 'c') {
        textOutput("LIST CREATED");
    } else if (command.at(0) == 'x') {
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