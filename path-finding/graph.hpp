#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
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
            std::deque<Node> vals;
            vals.push_back(vertexSet[0]);
            
            for (int i = 1; i < this->vnum; i++) {
                this->vertexSet[i].value = 10000; 
                this->vertexSet[i].color = 0;
            }

            int count = 0;


            while (vals.size() != 0) {
                for (auto it = edgeSet.begin(); it != edgeSet.end(); it++) {
                    if (vals.front().index == it->first.first) {
                        checkWeight(it, vertexSet[it->first.first], vertexSet[it->first.second]);
                        if (vertexSet[it->first.second].color != 3)
                            vals.push_back(vertexSet[it->first.second]);
                    }

                    std::cout << "vals.front() : " << vals.front().index << "\n" << std::endl; 
                }
                vertexSet[vals.front().index].color = 3;
                vals.pop_front();
            }
            return {0, 2, 3};
        }

        bool checkWeight(std::map<std::pair<int,int>, int>::iterator it, Node &node1, Node &node2) {
            printf("\nNode 1: %d\nNode 2: %d\nWeight: %d\nNode %d val: %d\nNode %d val: %d\n\n\n\n", it->first.first, it->first.second, it->second, node1.index, node1.value, node2.index, node2.value);
            
            // if parent node is undiscovered, return false. 
            if (node1.color == 0) 
                return false;
            else    
                node2.color = 2; // set child node to gray. 

            
                
            // if child node value is less than parent node + weight, then false. 
            if (node2.value > (node1.value + it->second)) {
                node2.value = node1.value + it->second;
                std::cout << node2.index << ":" << node2.value << std::endl;
                return true;
            }

            return false;

        }


        void printEdgeSet() {
            for (auto it = this->edgeSet.begin(); it != this->edgeSet.end(); it++) 
                printf("\n\nNode 1: %d\n\n Node 2: %d\n\n Weight: %d\n\n", it->first.first, it->first.second, it->second); 
        }









        void BFS() {
            std::queue<int> grayPeople;
            std::vector<int> blackPeople; 

            grayPeople.push(0);

            int holder = 0; 
 
            while (grayPeople.size() != 0) {
                holder = grayPeople.front();
                printf("\nNode %d has finally achieved Black Person Status (BPS)\n\n", holder);
                for (auto it = this->edgeSet.begin(); it != this->edgeSet.end(); it++) {
                    if (it->first.first == holder) {
                        grayPeople.push(it->first.second); 
                        printf("\nPushing node %d onto Gray People Queue (GPQ)\n\n", it->first.second);
                    }
                }
                grayPeople.pop();
            }

        }


};