// Lab 15 -- binary search tree
//
// Programmer name: Samuel Fuller
// Date completed:  3 December 2019

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

  // Find the target data in the tree. Returns true if target is found.
  // Returns false otherwise.
  bool find(T target) {
    return find(target, this->root);
  }

  // Remove the target data from the tree. Returns true if the target
  // is found and removed. Returns false otherwise.
  bool remove(T target) {
    return remove(target, this->root);
  }

  // Return a pointer to the target data. Returns nullptr if the target
  // data is not found.
  T *get(T target) {
    return get(target, this->root);
  }

  // Print the data in the tree to STDOUT, in-order (ascending).
  void printInOrder() {
    printInOrder(this->root);
  }

  // Print the data in the tree to STDOUT, reverse-order (descending).
  void printReverseOrder() {
    printReverseOrder(this->root);
  }

private:
  unsigned int size; // the number of nodes in the tree

  // A binary search tree node with constructor.
  struct Node {
    T data;
    Node *leftChild;
    Node *rightChild;

    Node(T newData) : data(newData), leftChild(nullptr), rightChild(nullptr) {}
  } * root; // the root of the tree

  // Helper functions to hide internal node pointers from the public API.

  void clear(Node *&troot) {
    if(troot != nullptr) {
      clear(troot->leftChild);
      clear(troot->rightChild);
      delete troot;
      troot = nullptr;
      this->size--;
    }
  }

  bool insert(T newData, Node *&troot) {
    if(troot == nullptr) {
      troot = new Node(newData);
      this->size++;
      return true;
    } else if(newData < troot->data) {
      return insert(newData, troot->leftChild);
    } else if(newData > troot->data) {
      return insert(newData, troot->rightChild);
    } else {
      return false;
    }
  }

  bool find(T target, Node *troot) {
    if(troot == nullptr) {
      return false;
    } else if(troot->data < target) {
      return find(target, troot->rightChild);
    } else if(troot->data > target){
      return find(target, troot->leftChild);
    } else {
      return true;
    }
  }

  bool remove(T target, Node *&troot) {
    if(troot == nullptr) {
      return false;
    } else if(target < troot->data) {
      return remove(target, troot->leftChild);
    } else if(troot->data < target) {
      return remove(target, troot->rightChild);
    } else {
      if(troot->leftChild == nullptr) {
        Node* temp = troot;
        troot = troot->rightChild;
        delete temp;
      } else {
        removeMax(troot->data, troot->leftChild);
      }
    }
    this->size--;
    return true;
  }

  void removeMax(T &removed, Node *&troot) {
    if (troot->rightChild == nullptr) {
      removed = troot->data;
      Node* temp = troot;
      troot = troot->leftChild;
      delete temp;
    } else {
      removeMax(removed, troot->rightChild);
    }
  }

  T *get(T target, Node *troot) {
    if(troot == nullptr) {
      return nullptr;
    } else if(troot->data < target) {
      return get(target, troot->rightChild);
    } else if(troot->data > target){
      return get(target, troot->leftChild);
    } else {
      return &troot->data;
    }
  }

  void printInOrder(Node *troot) {
    if (troot != nullptr) {
      printInOrder(troot->leftChild);
      cout << troot->data << endl;
      printInOrder(troot->rightChild);
  }
}

  void printReverseOrder(Node *troot) {
    if (troot != nullptr) {
      printReverseOrder(troot->rightChild);
      cout << troot->data << endl;
      printReverseOrder(troot->leftChild);
    }
  }
};
