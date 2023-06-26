## Python Graph Examples!

### To run, simply do...

python3 graph.py 

### Explanation: 

This Graph file implemented in Python shows how to create a Node class which stores the value of the node itself, a neighboring set which contains nodes which are 
linked (neighbors), as well as a key which is given in alphabetic terms to denote each node. 

All created nodes are then stored within the Graph class, which stores a list of different Nodes within a vset (standard list) OR a v2set (mapping of nodes). 

You are also given the opportunity to hard code neighboring nodes for each node, and an implementation class is present within the Graph class itself. 

Once the nodes are initialized, you can perform Djikstra's algorithm on the set of nodes in the graph, which effectively finds the shortest path from a root node to each of the other nodes in the graph. The algorithm makes use of the min-heap principles, which makes sure that the next node picked out from the heap is the smallest node.value (distance). 


Note that Python makes use of a lot of abstracted features such as tuple unpacking and list comprehension, which makes the solutions (imho) much simpler to read and implement than any other language. I would suggest using the Python implementations as a basis for study and then actual implementation within another language. 