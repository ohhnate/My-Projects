#include "slist.h"

// Default constructor.
// Initializes head to nullptr, size to 0.
SList::SList() {
  head = nullptr;
  size = 0;
}

SList::~SList() {
  clear();
}

// Create a new node to contain value and insert the node
// at the head of this SList. Increases the size by 1.
void SList::pushFront(int value) {
  Node* node = new Node(value);
  node->next = this->head;
  head = node;
  size++;
}

void SList::popFront() noexcept(false) {
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
int SList::front() noexcept(false) {
  if (this->head == nullptr){
		throw std::invalid_argument("NULL STRING POINTER");
	}
  return this->head->value;
}

// Return the number of nodes in this list.
unsigned int SList::getSize() const {
  return this->size;
}

// Check to see if this list is empty.
bool SList::empty() const {
  if (this->head == nullptr) {
    return true;
  }
  return false;
}

void SList::clear() {
  while(this->head != nullptr) {
    popFront();
  }
}

// Return a string representation of this list.
// Displays the values (starting from head) of each node in the list,
// separated by comma.
//
// EXAMPLE: "13,-1,0,99,-47"
string SList::toString() const {
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
