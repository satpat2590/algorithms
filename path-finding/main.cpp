#include <stdio.h>
#include "graph.hpp"
#include <vector>
#include <queue>
#include <string.h>

bool tryme = 1;
const int NODE = 10;

int main() {
    Graph newGraph = Graph(NODE);
    std::vector<int> vertexSet;
    int p_node;
    int c_node;
    int weight;
    char cont; 

    for (int i = 0; i < NODE; i++)
        vertexSet.push_back(newGraph.vertexSet[i].index);

    while (tryme) {
        printf("\nEnter a parent node: ");
        std::cin >> p_node;
        fflush(stdin);
        printf("\nEnter a child node: ");
        std::cin >> c_node; 
        fflush(stdin);
        printf("\nEnter a weight: ");
        std::cin >> weight; 
        fflush(stdin);
    
        newGraph.createEdge(p_node, c_node, weight);

        printf("\nEnter another edge? [Y/n]\n");
        std::cin >> cont; 
        fflush(stdin);
        printf("\n\n%c\n\n", cont);
        if ('Y' != cont)
            tryme = 0; 
    }

    newGraph.printEdgeSet();


    newGraph.bellmanFord();




    /*
    Pick any 2 indices from 0 to n (Graph constructor parameter) and a weight 
    to create an edge 
    
    Call automatically updates Nodes and also spits back the shortest path 
    using any of the functions made in Graph.hpp
    */
}