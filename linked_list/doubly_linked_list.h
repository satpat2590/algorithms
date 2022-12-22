struct DNode {
  int data;
  DNode* next;
  DNode* prev;

  DNode(int data) : data(data), next(nullptr), prev(nullptr) { }
};

struct DoublyLinkedList {
  DNode* head;

  DoublyLinkedList() {
    head = new DNode(0);
  };

  DoublyLinkedList(int data) {
    head = new DNode(data);
  };

  void print();
  int get_size();
  void push_back(int data);
  void insert(int data, int index);
  void push_front(int data);
  void reverse();
  void sort();
};
