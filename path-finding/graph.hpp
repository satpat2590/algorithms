#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>


/*

Graph is essentially a weighted graph with a 

Vertex set containing all
nodes in the Graph, 

and an Edgeset which consists of all the vertices which are
connected 

*/

class Graph {

    public:
        struct Node {
            int value;
            int color; 
            int index;
            Node(int val) : index(val) {}
        };

        std::vector<Node> vertexSet; 

        std::map<std::pair<int, int>, int> edgeSet; 
        Graph(int nodesize) {
            vertexSet.reserve(sizeof(Node) * nodesize); 
            for (int i = 0; i < nodesize; i++) 
                vertexSet.push_back(Node(i));
            
        }


        std::pair<int, int> createEdge(int node1, int node2, int weight) {
            edgeSet.insert(std::pair<std::pair<int, int>, int>(std::make_pair(node1, node2), weight)); 
            return std::make_pair(node1, node2);
        }


    private:


};