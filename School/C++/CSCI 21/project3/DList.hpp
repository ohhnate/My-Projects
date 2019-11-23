//Project3 Doubly Linked Lists
//
//Programmer: Samuel Fuller
//Last Modified: 22 November 2019


#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using std::cout;
using std:: endl;
using std::ifstream;
using std::string;
using std::stringstream;
using std::istringstream;

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
  void pushFront(T value) {
    Node* node = new Node(value);
    if (this->head == nullptr) {
      this->head = node;
      this->tail = node;
      size++;
    } else {
      node->next = this->head;
      head->prev = node;
      head = node;
      size++;
    }
  }
  // Cratess node at the tail of list.
  void pushBack(T value){
    Node* node = new Node(value);
    if (this->head == nullptr){
      this->head = node;
      this->tail = node;
      size ++;
    } else {
      node->prev = this->tail;
      tail->next = node;
      tail = node;
      size ++;
    }
  }

  //Removes the head node.
  void popFront() {
    if (head != nullptr) {
      Node* temp = head;
      head = head->next;
      delete temp;
      size--;
    }
  }

  //Removes tail node
  void popBack() {
    if (tail != nullptr) {
      Node *temp = tail;
      tail = tail->prev;
      if (tail != nullptr) {
        tail->next = nullptr;
      } else {
        head = nullptr;
      }
      delete temp;
      size--;
    }
  }

  bool listChecker() {
    if (head == nullptr) {
      return false;
    } else {
      return true;
    }
  }

  // Return the value stored in the head Node.
  T front() {
    return this->head->value;
  }
  // Return the value stored in tail node.
  T back() {
    return this->tail->value;
  }

  // Free the memory associated with all nodes in the list.
  // Resets head to nullptr and size to 0.
  void clear() {
    while(this->head != nullptr) {
      popFront();
      head = nullptr;
      size = 0;
    }
  }

  // Prints values of list
  string toString() const {
    stringstream strout;
    if (head == nullptr) {
      strout << "LIST EMPTY";
      return strout.str();
    }
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

  //returns true if value exists
  bool getNumber(T value) {
    Node *temp = head;
    while (temp != nullptr) {
      if (temp->value == value) {
        return true;
      } else {
        temp = temp->next;
      }
    }
    return false;
  }

  // Removes first occurence of a value
  bool removeFirst(T value) {
    Node *temp = head;
    while (temp != nullptr){
      if (temp->value == value){
        break;
      } else if (temp->value != value){
        temp = temp->next;
      } else {
        return false;
        }
    }
    if (temp == nullptr) {
      return false;
    }
    Node *after = temp->next;
    Node *before = temp->prev;
    if (size == 1 || temp == head) {
      popFront();
      return false;
    } else if (head != temp && temp->next != nullptr) {
      after->prev = before;
      before->next = after;
      delete temp;
      size --;
      return true;
    } else popBack();
  }

  // Removes all occurences of a value. Ues getNumber to check if getNumber
  // still exists in list.
  bool removeAllOccurrences(T value){
    bool exists = false;
    while (getNumber(value) == true) {
      removeFirst(value);
      exists = true;
    }
    removeFirst(value);
    if (getNumber(value) == false) {
      exists == false;
    }
    return exists;
  }

  T listSize() {
    return size;
  }

  // Inserts a value into a sorted position. (i think)
  void insertNode(T value) {
    Node *temp = new Node(value);
    Node* current;
    temp->value = value;
    if (head == nullptr) {
      head = temp;
      tail = head;
      size++;
    } else if ( head->value >= temp->value) {
      temp->next = head;
      temp->next->prev = temp;
      head = temp;
    } else {
      current = head;
      while (current->next != nullptr && current->next->value < temp->value) {
        current = current->next;
      }
      temp->next = current->next;
      if (current->next != nullptr) {
        temp->next->prev = temp;
        current->next = temp;
        temp->prev = current;
        size++;
      } else {
        temp = temp->next;
      }
    }
  }

private:
  unsigned int size; // the number of nodes in this list

  // A doubly-linked list node with a pointer to next and a value field.
  // Implements a constructor to initialize the value field to a param value
  // and the pointer to nullptr.
  struct Node {
    T value;
    Node* prev;
    Node* next;

    Node(T value) {
      this->value = value;
      this->prev = nullptr;
      this->next = nullptr;
    }
  } *head, *tail; // a pointer to the first and last node in the list
};
