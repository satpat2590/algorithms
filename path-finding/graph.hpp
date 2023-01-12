
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

class Graph {

    public:
        struct Node {
            int value;
            int color; 
            int index;
            Node(int val) : index(val) {}
        };

        // Vertex Set containing various Nodes
        std::vector<Node> vertexSet; 

        // Edge set containing various connections between Nodes
        // std::map<std::pair<Node, Node>, int> edgeSet; 
        std::map<std::pair<int, int>, int> edgeSet; 
        Graph(int nodesize) {
            // Reserve space for the number of nodes initialized
            vertexSet.reserve(sizeof(Node) * nodesize); 
            // Create initialized number of Nodes within the vector 
            for (int i = 0; i < nodesize; i++) {
                vertexSet.push_back(Node(i));
            }
        }


        std::pair<Node, Node> createEdge(Node node1, Node node2, int weight) {
            // Insert edge into map!
            edgeSet.insert(std::pair<std::pair<int, int>, int>(std::make_pair(node1.index, node2.index), weight)); 

            return std::make_pair(node1, node2);
        }


    private:


};