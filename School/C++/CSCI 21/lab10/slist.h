// Lab 10 -- singly-linked list
//
// Programmer name: Samuel Fuller
// Date completed:  5 November 2019

#pragma once

#include <cstdint>
#include <sstream>
#include <stdexcept>
#include <string>
using std::logic_error;
using std::ostringstream;
using std::string;

class SList {
public:
  // Default constructor.
  // Initializes head to nullptr, size to 0.
  SList();

  // Create a new node to contain value and insert the node
  // at the head of this SList. Increases the size by 1.
  void pushFront(int value);

  // Return the value stored in the head Node.
  // Throws std::logic_error("EMPTY LIST") when list is empty
  int front() noexcept(false);

  // Return the number of nodes in this list.
  unsigned int getSize() const;

  // Check to see if this list is empty.
  bool empty() const;

  // Return a string representation of this list.
  // Displays the values (starting from head) of each node in the list,
  // separated by comma.
  //
  // EXAMPLE: "13,-1,0,99,-47"
  string toString() const;

private:
  unsigned int size; // the number of nodes in this list

  // A singly-linked list node with a pointer to next and a data field.
  // Implements a constructor to initialize the data field to a param value
  // and the pointer to nullptr.
  struct Node {
    Node *next;
    int value;

    Node(int newValue) {
      next = nullptr;
      value = newValue;
    }
  } * head; // a pointer to the first node in the list
};
