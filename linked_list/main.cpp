#include <stdio.h>
#include "linked_list.h"
#include "doubly_linked_list.h"

int main(int argc, char** argv) {
  LinkedList* llist = new LinkedList;
  DoublyLinkedList* dllist = new DoublyLinkedList;

  llist->push_back(1);
  llist->push_back(2);
  llist->push_back(3);
  llist->push_back(4);
  llist->push_back(5);
  printf("Size: %d\n", llist->get_size());
  llist->print();
  llist->reverse();
  llist->print();

  dllist->push_back(1);
  dllist->push_back(2);
  dllist->push_back(3);
  dllist->push_back(4);
  dllist->push_back(5);
  printf("Size: %d\n", dllist->get_size());
  dllist->print();
  dllist->reverse();
  dllist->print();
  return 0;
}
