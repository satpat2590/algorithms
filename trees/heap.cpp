#include "BST_maxHeap.hpp"
#include "BST_minHeap.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

int main() {
  BSTMAX newBST;
  newBST.insert(10);
  newBST.insert(12);
  newBST.insert(15);
  newBST.insert(25);
  newBST.insert(100);

  int retNode = newBST.top();

  std::cout << retNode << std::endl;
  
  BSTMIN newMin; 
 
  newMin.insert(10);
  newMin.insert(15);
  newMin.insert(56);
  newMin.insert(3);
  newMin.insert(27);
  newMin.insert(17);
  newMin.insert(25);
  newMin.insert(14);
  newMin.insert(7);
  
  std::cout << newMin.top() << std::endl; 
 
  newMin.pop();

  std::cout << newMin.top() << std::endl; 

}
