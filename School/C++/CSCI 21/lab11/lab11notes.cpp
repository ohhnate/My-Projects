#include <iostream>

class SList {
public:
  SList() {
    head = nullptr;
    count = 0;
  }

  ~SList() {
    clear();
  }

  void pushFront(int data) {
    Node* node = new Node(data);
    node->next = head;
    head = node;
    count++;
  }

  void popFront() noexcept(false) {
    if (this->head == nullptr) {
      throw std::logic_error("EMPTY LIST");
    }

    Node* temp = this->head;
    this->head = this->head->next;
    delete temp;
    count--;
  }

  void clear() {
    while(this->head != nullptr) {
      popFront();
    }
  }

  private:
    int count;

    struct Node {
      Node *next;
      int value;

      Node(int newValue) {
        next = nullptr;
        value = newValue;
      }
    }* head;
};
