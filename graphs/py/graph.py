import collections
import heapq

class Node():
  i = 65 # Character increment via ASCII
  def __init__(self, value):
    self.value = value # Value, could be theoretically anything
    self.neighbors = [] # Connected nodes
    self.key = chr(Node.i) # Key, or the character value
    Node.i += 1 # Increment 'i' by one each time instantiated


# Directed graph!
class Graph():
  def __init__(self):
    self.vset = []
    self.v2set = {}

  def add_node(self, node):
    self.vset.append(node)
    self.v2set[node.key] = node.neighbors

  def get_node(self, key):
    for node in self.vset:
      if node.key == key:
        return node

  def dfs(self, root='A'):
    print([x.key for x in self.vset]) #prints out the vertex set currently
    stack = [root]
    visited = []

    while stack:
      traverse = stack.pop()
      if traverse not in visited:
        visited.append(traverse)
        for x, y in self.get_node(traverse).neighbors:
          if x not in visited:
            stack.append(x)
        print(f"Value of traverse: {traverse}")

  def bfs(self, root='A'):
    queue = collections.deque([root])
    visited = []

    while queue:
      traverse = queue.popleft()
      if traverse not in visited:
        visited.append(traverse)
        for x, y in self.get_node(traverse).neighbors:
          if x not in visited:
            queue.append(x)

        print(f"Value of traverse: {traverse}")

  def djikstra(self, root='A'):
    # Initialize all of the total distances of vertices
    for x in self.vset:
      if x.key == root:
        x.value = 0
      else:
        x.value = 100000

    # Create the min heap by adding (root.d, root.key)
    mheap = [(self.get_node(root).value, root)]

    # Create the visited set
    visited = set()

    # While the mheap is NOT empty
    while mheap:
      # Pop out the min distance and key pair from the heap (min is at root)
      d, pop = heapq.heappop(mheap)
      # Retrieve the node instance from the key
      traverse = self.get_node(pop)

      # If the popped value (traverse) is NOT in the visited set
      if traverse.key not in visited:
        visited.add(traverse.key)
        # Loop through all edges connecting traverse
        for x, y in traverse.neighbors:
          # If the value + the weight of traverse is < value at X, then change it
          if self.get_node(x).value > d + y:
            self.get_node(x).value = d + y
            # Only push into the heap if NOT visited already
            if x not in visited:
              print(f"Traverse: {traverse.key}: \n\tx-val: {x} and the new value of {x}: {self.get_node(x).value}")
              heapq.heappush(mheap, (self.get_node(x).value, x))








  # Takes in key which maps to key2, directed graph!
  def neighboring(self, key, key2, d=None):
    keyset = [x.key for x in self.vset]
    if key in keyset and key2 in keyset:
      #self.get_node_from_key(key).neighbors.append(self.get_node_from_key(key2))
      self.get_node(key).neighbors.append((self.get_node(key2).key, d))
    else:
      print("There is no such key within the vset! Try again.\n\n")

  def print_neighbors(self, key):
    neighborset = [(x, y) for x, y in self.get_node(key).neighbors]
    print(key, neighborset)






# Creating our individual nodes!
nn = Node(50) # 'A'
n2 = Node(60) # 'B'
n3 = Node(70) # 'C'
n4 = Node(80) # 'D'
n5 = Node(50) # 'E'
n6 = Node(60) # 'F'
n7 = Node(70) # 'G'
n8 = Node(80) # 'H'

# Holding all vertices
vertices = [chr(x + 65) for x in range(8)]
print(f"Vertices: {vertices}")

# Creating our graph and adding all pertinent nodes
graph = Graph()

graph.add_node(nn)
graph.add_node(n2)
graph.add_node(n3)
graph.add_node(n4)
graph.add_node(n5)
graph.add_node(n6)
graph.add_node(n7)
graph.add_node(n8)

graph.neighboring('A', 'C', 5)
graph.neighboring('A', 'F', 6)
graph.neighboring('A', 'D', 2)
graph.neighboring('A', 'B', 1)
graph.neighboring('B', 'C', 5)
graph.neighboring('C', 'F', 6)
graph.neighboring('D', 'E', 2)
graph.neighboring('F', 'H', 1)
graph.neighboring('E', 'G', 2)
graph.neighboring('B', 'F', 10)
graph.neighboring('C', 'E', 8)


for c in vertices:
  graph.print_neighbors(c)

graph.djikstra()
