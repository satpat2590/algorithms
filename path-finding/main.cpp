#include <stdio.h>
#include "graph.hpp"
#include <vector>
#include <queue>


const int NODE = 2;

int main() {
    Graph newGraph = Graph(5);
    std::vector<int> vertexSet;

    for (int i = 0; i < NODE; i++)
        vertexSet.push_back(newGraph.vertexSet[i].index);

    std::pair<int, int> edge = newGraph.createEdge(newGraph.vertexSet[0].index, newGraph.vertexSet[1].index, 5);

    printf("\nEdge stored is: %d\n", newGraph.edgeSet[std::make_pair(edge.first, edge.second)]);


    /*
    Pick any 2 indices from 0 to n (Graph constructor parameter) and a weight 
    to create an edge 
    
    Call automatically updates Nodes and also spits back the shortest path 
    using any of the functions made in Graph.hpp
    */
}