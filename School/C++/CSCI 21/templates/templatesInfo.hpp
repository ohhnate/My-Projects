#pragma once

template <typename T>
class DList {
public:
  DList() {
      this->head = nullptr;
      this->tail = nullptr;
  }
  ~DList() {

  }
  void pushFront(T data) {
    Node* node = new Node(data);
    if (this->head == nullptr) {
      this->head = node;
      this->tail = node;
    } else {
      node->next = this->head;
      this->head->prev = node;
      this->head = node;
    }
  }

private:
  struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(T data) {
      this->data = data;
      this->prev = nullptr;
      this->next = nullptr;
    }
  } *head, *tail;
};
