// Lab 14 -- binary search tree
//
// Programmer name: Samuel Fuller
// Date completed:  26 Nov 2019

#pragma once

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class BSTree {
public:
  // Default constructor.
  // Initialize the tree with size 0 and null root.
  BSTree()
    : size(0), root(nullptr) {}

  // Destructor.
  // Clear the tree.
  ~BSTree() {
    clear(this->root);
  }

  // Returns the size (number of nodes) of this tree.
  unsigned int getSize() {
    return this->size;
  }

  // Clear the tree of all nodes. Reset head to nullptr and size to 0.
  void clear() {
    clear(this->root);
  }

  // Insert the data in the tree. Returns true if the data is not a
  // duplicate, and can be inserted. Returns false otherwise.
  bool insert(T data) {
    return insert(data, this->root);
  }

  // Print the data in the tree to STDOUT, in-order (ascending).
  void printInOrder() {
    printInOrder(this->root);
  }

private:
  unsigned int size; // the number of nodes in the tree

  // A binary search tree node with constructor.
  struct Node {
    T data;
    Node *left;
    Node *right;

  // Initialization list
    Node(T newData) : data(newData), left(nullptr), right(nullptr) {}
  } * root; // the root of the tree

  // Helper functions to hide internal node pointers from the public API.

  void clear(Node *&troot) {
    if (troot != nullptr) {
      clear(troot->left);
      clear(troot->right);
      delete troot;
      troot = nullptr;
      this->size--;
    }
  }

  bool insert(T newData, Node *&troot) {
    if (troot == nullptr) {
      troot = new Node(newData);
      this->size++;
      return true;
    } else if (newData < troot->data) {
      return insert(newData, troot->left);
    } else if (newData > troot->data) {
      return insert(newData, troot->right);
    } else {
      return false;
    }
  }

  void printInOrder(Node *troot) {
    if (troot != nullptr) {
      printInOrder(troot->left);
      cout << troot->data << endl;
      printInOrder(troot->right);
    }
  }
};
