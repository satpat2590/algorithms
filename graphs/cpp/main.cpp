#include <stdio.h>
#include "graph.hpp"
#include <vector>
#include <queue>
#include <string.h>

bool tryme = 1;
const int NODE = 10;

void graphInit(Graph &graphy) {
    int p_node;
    int c_node;
    int weight;
    char cont; 
    printf("\n\nWelcome to the path-finding example!\nThere are 10 nodes in this example graph [0-9]\n\n\tEnter a source and destination node along with weights...\n\n");
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
    
        graphy.createEdge(p_node, c_node, weight);

        printf("\nEnter another edge? [Y/n]\n");
        std::cin >> cont; 
        fflush(stdin);
        if ('Y' != cont)
            tryme = 0; 
    }

}

int main(int argc, char** argv) {
    Graph pathGraph = Graph(NODE);
    std::vector<int> vertexSet;
    int p_node;
    int c_node;
    int weight;
    char cont; 
    for (int i = 0; i < NODE; i++)
        vertexSet.push_back(pathGraph.vertexSet[i].index);

    /*
        Enter 0 for the original test case 

        Enter 1 for for custom edge mappings
    */


   if (!strcmp(argv[1], "0")) {
    pathGraph.createEdge(0, 1, -1);
    pathGraph.createEdge(0, 2, 4);
    pathGraph.createEdge(1, 2, 3);
    pathGraph.createEdge(1, 3, 2);
    pathGraph.createEdge(1, 4, 2);
    pathGraph.createEdge(3, 1, 1);
    pathGraph.createEdge(3, 2, 5);
    pathGraph.createEdge(4, 3, -3);
   } else {
        graphInit(pathGraph);
   }



    // graphInit(pathGraph);
    pathGraph.bellmanFord();
}