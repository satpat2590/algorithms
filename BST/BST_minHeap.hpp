#include <stdio.h>
#include <stdlib.h>
#include <vector> 
#include <iostream> 


/*
 * Our purpose is to generate a min-heap data structure. All basic operations are permitted, but they must
 * comply with the definition of the min-heap. It is essentially a priority queue that is generated based on 
 * a list of nodes that are sorted from lowest to highest. 
 *
 * In our sorted list from lowest to highest, we consider each node to have two children nodes (left and right) which
 * are a part of a complete Binary Tree. In order to make our traversal much better, achieving log(n) time for operations 
 * whereas certain algorithms such as a Binary Search from a sorted Array yield a linear time. Only the search function is able
 * to be run in log(n) time for a Binary Search from a sorted array. 
 *
 * Insertions and removals take O(n) time for a typical sorted Array, Linked List, or even an unsorted Array. 
 * For a BST however, since the runtime of the operations are based on the height of the overall tree, and the height is 
 * essentially a logarithmic style calculation since at each depth of the tree, where the height of the tree is the max number of depths, each depth is 
 * depicted as an integer 'i'. At each depth of the BST, the number of node that are present are 2^i. At the first depth, 0, there are 2^0 nodes, which holds
 * true as there is only 2^0 = 1 nodes (the root). At the second depth, there are 2^1 nodes, which are 2 (left and right child of the root). As you 
 * continue down the depths until the max height, you can see the number of nodes increasing as the exponential power increases as well. 
 *
 * To calculate the runtime, you need to find the height of a tree. You can do this manually by drawing out a BST and counting the number of nodes at each 
 * depth and adding them together, or you can use the formula: 
 *
 *      2^h = n 
 *      h = log(n)
 *
 * Our job is to essentially check condition for the left and right child of each sub-tree root, and then decide which one to choose based on the conditions. 
 * You're effectively only going down ONE subtree, which eliminates the need to check all n nodes, which yields a logarithmic runtime. 
*/



class BSTMIN {
    private: 
        std::vector<int> A; 


        int PARENT(int i) {
            return ((i-1) / 2);
        }

        int LEFT(int i) {
            return ((i*2) + 1);
        }
        
        int RIGHT(int i) {
            return ((i*2) + 2);
        }

        void heapify_up(int i) {
            int p = PARENT(i);

            int temp = A[p];

            if (A[i] < A[p]) {
                A[p] = A[i];
                A[i] = temp; 
                heapify_up(p); 
            }
        }

        void heapify_down(int i) {
            int l = LEFT(i);
            int r = RIGHT(r); 
            int smallest = i; 
            int temp = A[i]; 

            if (l < A.size() && A[l] < A[smallest])
                smallest = l; 

            if (r < A.size() && A[r] < A[smallest])
                smallest = r; 

            if (smallest != i) {
                A[i] = A[smallest]; 
                A[smallest] = temp; 
                heapify_down(smallest);

            }
        }



    public: 

        void insert(int node) {
            int len = A.size(); 
            A.push_back(node); 
            
            heapify_up(len);
        }

        void pop() {
            if (A.size() <= 0) //If the size of the BST is 0 or less, then return. 
                return;

            A[0] = A.back(); //Set the root node equal to the last node. 
            A.pop_back(); //Removing the last node in the BST by popping it. 
            heapify_down(0); //Calling the recursive 'heapify_down', which ascertains the properties of a min-heap. 
        }

        int top() {
            if (A.size() <= 0) //If the size of the BST is less than or equal to 0, then return -1; 
                return -1;
            
            return A[0]; //Return the root node, as it is the top-most node. 
        }

};
