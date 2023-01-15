#include <stdio.h> 
#include <stdlib.h> 
#include <vector> 
#include <iostream> 


class BSTMAX {
  private: 
    std::vector<int> A;

    int PARENT(int i) {
      return ((i-1) / 2); 
    }
      

    int RIGHT(int i) {
      return (i*2) + 2; 
    }

    int LEFT(int i) {
      return (i*2) + 1; 
    }

    void heapify_up(int i) { //Used when inserting a new node into the BST. Makes sure the BST conditions pass (child < root)
      int p = PARENT(i);
      int temp = A[p];
      if (i && A[i] > A[p]) {
        A[p] = A[i];
        A[i] = temp; 
        heapify_up(p);
      }
    }

    void heapify_down(int root) { //Used when you use pop() or removal of the top-most or lowest priority value a.k.a ROOT. 
      int r = RIGHT(root); 
      int l = LEFT(root); 
      int largest = root; 
      int tempSwap = A[root]; 
      
      if (r < A.size() && A[r] > A[largest]) 
        largest = r; 
      

      if (l < A.size() && A[l] > A[largest]) 
        largest = l; 
      
      
      if (largest != root) {
        A[root] = A[largest]; 
        A[largest] = tempSwap;
        heapify_down(largest);

      }
    }
    

  public: 

    void insert(int node) {
      int len = A.size();
      A.push_back(node); //Pushing node to the end of the BST 

      heapify_up(len); //Calling recursive function to determine node position 
    }

    void pop() {
      if (A.size() <= 0) {
        printf("\nSize of the BST is not large enough to perform removal operations...\n");
        return; 
      }
      A[0] = A.back();
      A.pop_back();
      heapify_down(0);
    }

    int top() {
      if (A.size() <= 0) {
        printf("\nSize of the BST is not large enough to perform removal operations...\n");
        return -1; 
      }
      
      return A[0]; 
    }


    
};
