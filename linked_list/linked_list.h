struct Node {
  int data;
  Node* next;

  Node(int data) : data(data), next(nullptr) { }
};

struct LinkedList {
  Node* head;

  LinkedList() {
    head = new Node(0);
  };

  LinkedList(int data) {
    head = new Node(data);
  };

  void print();
  int get_size();
  void push_back(int data);
  void insert(int data, int index);
  void push_front(int data);
  void reverse();
  void sort();
};
