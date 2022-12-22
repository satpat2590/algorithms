#include <stdio.h>
#include "doubly_linked_list.h"

void DoublyLinkedList::print() {
  DNode* curr = this->head;
  while (curr->next) {
    printf("%d->", curr->data);
    curr = curr->next;
  }
  printf("%d\n", curr->data);
}

int DoublyLinkedList::get_size() {
  int size = 0;
  DNode* curr = this->head;
  while (curr) {
    curr = curr->next;
    ++size;
  }
  return size;
}

void DoublyLinkedList::push_back(int data) {
  DNode* curr = this->head;
  while (curr->next) {
    curr = curr->next;
  }
  DNode* tmp = new DNode(data);
  curr->next = tmp;
  tmp->prev = curr;
}

void DoublyLinkedList::insert(int data, int index) {
  int i = 0;
  DNode* curr = this->head;
  while (i < index && curr->next) {
    ++i;
    curr = curr->next;
  }
  DNode* tmp = new DNode(data);
  tmp->next = curr->next;
  tmp->prev = curr;
  curr->next->prev = tmp;
  curr->next = tmp;
}

void DoublyLinkedList::push_front(int data) {
  DNode* new_head = new DNode(data);
  new_head->next = this->head;
  this->head->prev = new_head;
  this->head = new_head;
}

void DoublyLinkedList::reverse() {
  DNode* curr = this->head;
  DNode* tmp = nullptr;
  while (curr) {
    tmp = curr->prev;
    curr->prev = curr->next;
    curr->next = tmp;
    curr = curr->prev;
  }
  if (tmp) this->head = tmp->prev;
}

void DoublyLinkedList::sort() {
}
