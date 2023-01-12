#include <stdio.h>
#include "graph.hpp"
#include <vector>
#include <queue>


int main() {
    Graph newGraph = Graph(5);

    std::pair<Graph::Node, Graph::Node> edge = newGraph.createEdge(newGraph.vertexSet[0], newGraph.vertexSet[1], 5);

    printf("\nEdge stored is: %d\n", newGraph.edgeSet[std::make_pair(edge.first.index, edge.second.index)]);
}