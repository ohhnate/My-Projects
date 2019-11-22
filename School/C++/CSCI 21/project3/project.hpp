// Project 3 -- File Processing & Doubly-Linked Lists
//
// Derek Bergman
// 6 Nov 2019

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

template <typename T>
class DList {
  public:
    // Constructor
    // Initializes head & tail to nullptr. Sets size to 0.
    DList(){
      this->head = nullptr;
      this->tail = nullptr;
      size = 0;
    }

    void clear(){
      while(head != nullptr){
        Node *temp = head;
        head = head->next;
        delete temp;
      }
      head = nullptr;
      tail = nullptr;
      size = 0;
    }

    // Destructor.
    // Clears all nodes and all memory associated with a list.
    ~DList(){
      while(head != nullptr){
        Node *temp = head;
        head = head->next;
        delete temp;
      }
    }

    void insert(T value){
      Node *node = new Node(value);
      if(head == nullptr){
        head = node;
        tail = node;
        size ++;
      } 
      if(size == 1){
        if(node->value < head->value)
          pushFront(node->value);
        if(node->value > head->value)
          pushBack(node->value);
      } else {
        Node *temp = head;
        while(temp != nullptr){
          if(node->value < temp->value){
            node->prev = temp->prev;
            node->next = temp;
            temp->prev = node;
            node->prev->next = node;

            size ++;
            break;
          } else pushBack(node->value);
        }
      }
    }
          
    void pushFront(T value){
      Node* node = new Node(value);
      if(this->head == nullptr){
        head = node;
        tail = node;
        size ++;
      } else {
        node->next = head;
        head->prev = node;
        head = node;
        size ++;
      }
    }


    void pushBack(T value){
      Node* node = new Node(value);
      if(this->head == nullptr){
        head = node;
        tail = node;
        size ++;
      } else {
        node->prev = tail;
        tail->next = node;
        tail = node;
        size ++;
      }
    }


    bool elimAll(T value){
      bool deleted = false;
      while(elimFirst(value)){
        deleted = true;
      }
      return deleted;
    }

    bool elimFirst(T value) { 
      Node *temp = head;
      bool found = false;

      while(temp != nullptr){
        if(temp->value == value){
          found = true;
          break;
        } else if(temp->value != value){
          temp = temp->next;
        } else return false;
      }
      if(temp == nullptr)
        return false;
      
      Node *after = temp->next;
      Node *before = temp->prev;
      if(size == 1 || temp == head) {
        found = popFront();       
      } else if(head != temp && temp->next != nullptr) {
        after->prev = before;
        before->next = after;
        delete temp;
        size --;
        found = true;
      } else popBack();
      return found;
    }

    // findValue searches for a value and states if it was found
    void findValue(T value){
      bool found = false;
      Node* temp = head;

      while(temp != nullptr){
        if(temp->value == value)
          found = true;
        temp = temp->next;
      }
      if(found)
        cout << "VALUE " << value << " FOUND";
      if(!found)
        cout << "VALUE " << value << " NOT FOUND";
    }


    // getFront outputs the value of the head node
    void getFront(){
      if(this->head == nullptr){
        cout << "LIST EMPTY";
      } else {
        cout << "VALUE " << head->value << " AT HEAD";
      }
    }

    // getBack outputs the value of the tail node
    void getBack(){
      if(head == nullptr){
        cout << "LIST EMPTY";
      } else {
        cout << "VALUE " << tail->value << " AT TAIL";
      }
    }

    bool popFront() {
      bool removed = false;
      Node* temp = head;
      
      if(this->head == nullptr){
        removed = false;
      } else {
        head = head->next;
        delete temp;
        size --;
        removed = true;
      }
      return removed;
    }

    // popBack removes the tail node
    bool popBack() {
      Node* temp = tail;
      bool removed = false;

      if(size == 0){
        removed = false;
      } else if( size == 1){
        tail = head;
        delete temp;
        tail = nullptr;
        head = nullptr;
        size = 0;
      } else if(tail->prev != nullptr) {
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        size --;
        removed = true;
      }
      return removed;
    }

    T getSize(){
      return size;
    }

    void printList() const {
      if(head == nullptr)
        cout << "LIST EMPTY";
      else {
        ostringstream sout;
        Node* temp = head;

        while(temp != nullptr){
          sout << temp->value;
          temp = temp->next;
          if(temp != nullptr)
            sout << ",";
        }
      cout << sout.str();
      }
    }

  private:
    unsigned int size;
    struct Node {
      T value;
      Node *prev;
      Node *next;

      Node(T newValue){
        this->prev = nullptr;
        this->next = nullptr;
        value = newValue;
      }
    } *head, *tail;
};
