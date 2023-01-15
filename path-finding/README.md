# PATH FINDING ALGORITHMS

*_Noted below are the algorithms implemented within the Graph.hpp header_*

## Bellman-Ford

Bellman-Ford tests each individual node from the vertex set V for all of the 
corresponding edges, "relaxing" their values each time. 

Once a node neighboring the index node is found, it's color becomes GRAY 
and it is inserted within the vertex queue. 

After all neighboring nodes are visited, the search runs again on the 
next vertex in the queue as the new index. 

All nodes are relaxed multiple times throughout all N outer loops throughout 
each edge. The final output is the value of each node in the graph, which, 
if done correctly, would be the shortest distance the from the source node "s" 
to that node. 


## How to use and modify!

From the root directory (path-finding/), simply run 

```bash
make
```

to compile the main.cpp file into an executable in the 'bin' folder (path-finding/bin/)


To run the program, run

```bash
./bin/MAIN 0
```

which will run the main.cpp file in "normal mode", which tests a hard coded set of values. 

To run custom edge cases, yielding in a custom Graph, run

```bash
./bin/MAIN 1
```



_If you want to modify an algorithm or create additional ones, just insert them within the 
graph.hpp header file_ 