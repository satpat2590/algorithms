#include <stdio.h>
#include "linked_list.h"

void LinkedList::print() {
  Node* curr = this->head;
  while (curr->next) {
    printf("%d->", curr->data);
    curr = curr->next;
  }
  printf("%d\n", curr->data);
}

int LinkedList::get_size() {
  int size = 0;
  Node* curr = this->head;
  while (curr) {
    curr = curr->next;
    ++size;
  }
  return size;
}

void LinkedList::push_back(int data) {
  Node* curr = this->head;
  while (curr->next) {
    curr = curr->next;
  }
  curr->next = new Node(data);
}

void LinkedList::insert(int data, int index) {
  int i = 0;
  Node* curr = this->head;
  while (i < index && curr->next) {
    ++i;
    curr = curr->next;
  }
  Node* tmp = new Node(data);
  tmp->next = curr->next;
  curr->next = tmp;
}

void LinkedList::push_front(int data) {
  Node* new_head = new Node(data);
  new_head->next = this->head;
  this->head = new_head;
}

void LinkedList::reverse() {
  Node* curr = this->head;
  Node* next = nullptr;
  Node* prev = nullptr;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  this->head = prev;
}

void LinkedList::sort() {
}
