#include <vector>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

/*
    Root of the tree must be BLACK

    All RED nodes must have only BLACK kids

    All height of BLACK leaf nodes must be same 
    from root
*/

class RBT {
    public:
        struct Node {
            int value; 
            int color;
            Node* p;
            Node* left;
            Node* right;  
        };

        std::vector<Node> redBlack;

        RBT(int numnodes) {
            for (int i = 0; i < numnodes; i++) 
                redBlack.push_back(Node());
        } 

        ~RBT() { this->redBlack.clear(); }


        void insert(Node n) {
            
            
        }



};