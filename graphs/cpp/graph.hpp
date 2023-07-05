#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
#include <deque>


/*

Graph is essentially a weighted graph with a 

Vertex set containing all
nodes in the Graph, 

and an Edgeset which consists of all the vertices which are
connected 

*/

/*
Color coding for each node!

0: White: Undiscovered

1: Gray: Currently exploring

2: Black: Finished and fully discovered!
*/

class Graph {
    public:
        int vnum; 

        struct Node {
            int value;
            int color; 
            int index;
            int d;
            int f;
            Node(int val) : index(val) {}
        };

        std::vector<Node> vertexSet; 

        std::map<std::pair<int, int>, int> edgeSet; 

        Graph(int nodesize) : vnum(nodesize) {
            vertexSet.reserve(sizeof(Node) * nodesize); 
            for (int i = 0; i < nodesize; i++) 
                vertexSet.push_back(Node(i));
            
        }

        void createEdge(int node1, int node2, int weight) {
            edgeSet.insert(std::pair<std::pair<int, int>, int>(std::make_pair(node1, node2), weight)); 
            // return std::make_pair(node1, node2);
        }

        std::vector<int> bellmanFord() {
            vertexSet[0].value = 0;
            vertexSet[0].color = 2;
            std::deque<int> vals;
            vals.push_back(vertexSet[0].index);
            
            for (int i = 1; i < this->vnum; i++) {
                this->vertexSet[i].value = 10000; 
                this->vertexSet[i].color = 0; 
            }

            while (vals.size() != 0) {
                for (auto it = edgeSet.begin(); it != edgeSet.end(); it++) {
                    if (vals.front() == it->first.first) {
                        checkWeight(it, vertexSet[it->first.first], vertexSet[it->first.second]);
                        if (vertexSet[it->first.second].color != 3)
                            vals.push_back(vertexSet[it->first.second].index);
                    } else {
                        std::cout << "Searching vals.front() : " << vals.front() << "...\n" << std::endl; 
                    }
                }
                vertexSet[vals.front()].color = 3;
                printf("\n\nSize of the queue: %lu\nNODE %d HAS BECOME COMPLETE: HERE'S PROOF: COLOR = %d\n\n", vals.size(), vals.front(), vertexSet[vals.front()].color);
                vals.pop_front();
            }

            printf("\n--------------------------Final Results------------------------------\n\n");

            for (auto it2 = vertexSet.begin(); it2 != vertexSet.end(); it2++) 
                printf("\nNode %d final distance from entry is: %d\n\n", it2->index, it2->value);
            
            return {0, 2, 3};
        }

        bool checkWeight(std::map<std::pair<int,int>, int>::iterator it, Node &node1, Node &node2) {
            printf("\nNode %d Value: %d\nNode %d Value: %d\nWeight: %d\n\n\n", it->first.first, node1.value, it->first.second, node2.value, it->second);
            // if parent node is undiscovered, return false. 
            if (node1.color == 0) 
                return false;
            else if (node2.color < 3)
                node2.color = 2; // set child node to gray. 

            // if child node value is less than parent node + weight, then false. 
            if (node2.value > (node1.value + it->second)) {
                node2.value = node1.value + it->second;
                std::cout << "\nSuccessful value change!\nNode: " << node2.index << "\nValue: " << node2.value << std::endl;
                std::cout << "\n--------------------------------------------------------\n" << std::endl;
                return true;
            }
            std::cout << "\n--------------------------------------------------------\n" << std::endl;

            return false;

        }

        void printEdgeSet() {
            for (auto it = this->edgeSet.begin(); it != this->edgeSet.end(); it++) 
                printf("\n\nNode 1: %d\n\n Node 2: %d\n\n Weight: %d\n\n", it->first.first, it->first.second, it->second); 
        }

        // void DFS() {
        //     std::queue<int> grayPeople;
        //     std::vector<int> blackPeople; 

        //     grayPeople.push(0);

        //     int holder = 0; 
 
        //     while (grayPeople.size() != 0) {
        //         holder = grayPeople.front();
        //         printf("\nNode %d has finally achieved Black Person Status (BPS)\n\n", holder);
        //         for (auto it = this->edgeSet.begin(); it != this->edgeSet.end(); it++) {
        //             if (it->first.first == holder) {
        //                 grayPeople.push(it->first.second); 
        //                 printf("\nPushing node %d onto Gray People Queue (GPQ)\n\n", it->first.second);
        //             }
        //         }
        //         grayPeople.pop();
        //     }

        // }

};