// Lab 12 -- templated singly-linked list class
//
// Programmer name: Samuel Fuller
// Date completed:  7 November 2019

#include <sstream>
#include <stdexcept>
#include <string>
using std::logic_error;
using std::ostringstream;
using std::string;

template <typename T>
class SList {
public:
  // Default constructor.
  // Initializes head to nullptr, size to 0.
  SList() {
    head = nullptr;
    size = 0;
  }

  // Destructor.
  // Invokes clear to free the memory associated with all nodes in the list.
  ~SList() {
    clear();
  }

  // Create a new node to contain value and insert the node
  // at the head of this SList. Increases the size by 1.
  void pushFront(T value) {
    Node* node = new Node(value);
    node->next = this->head;
    this->head = node;
    this->size++;
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
    return this->head->value;
  }

  // Return the number of nodes in this list.
  unsigned int getSize() const {
    return this->size;
  }

  // Check to see if this list is empty.
  bool empty() const {
    if (this->head == nullptr) {
      return true;
    }
    return false;
  }

  // Free the memory associated with all nodes in the list.
  // Resets head to nullptr and size to 0.
  void clear() {
    while(this->head != nullptr) {
      popFront();
    }
  }

  // Return a string representation of this list.
  // Displays the values (starting from head) of each node in the list,
  // separated by comma.
  //
  // EXAMPLE: "13,-1,0,99,-47"
  string toString() const {
    ostringstream strout;
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

  // A singly-linked list node with a pointer to next and a data field.
  // Implements a constructor to initialize the data field to a param value
  // and the pointer to nullptr.
  struct Node {
    T value;
    Node* next;

    Node(T value) {
      this->value = value;
      this->next = nullptr;
    }
  } * head; // a pointer to the first node in the list
};
