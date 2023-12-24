
# Tree:

**Tree** is a non-linear simple hierarchical data structure for which average time complexity is O(log<sub>2</sub>n). If time complexity in worst case becomes O(n), then it can be converted into O(log<sub>2</sub>n) with some modification.

**Tree** is also called recursive data structure. The topmost node of the tree is called the root, and the nodes below it are called the child nodes. Each node can have multiple child nodes, and these child nodes can also have their own child nodes, forming a recursive structure.


Top most node of the tree is called root and all the nodes below root is called child notes. All the nodes wich does not have any child is called leave nodes.

![Treedatastructure](https://github.com/1711naveen/DSA/assets/139497591/808f7a04-4a02-4908-9319-09f7a664499a)
<p align="center">Tree Data Structure.</p>

# Basic terminology in Tree Data Structure:



- **Root Node:** The top most node of the tree is called root node. Root node does not have any parent. In the above image {A} is the root of the tree.

- **Parent Node:** The node which is a predecessor of a node is called the parent node of that node. {B} is the parent node of {D, E} in the above image.

- **Child Node:** The node which is the immediate successor of a node is called the child node of that node. Examples: {D, E} are the child nodes of {B} in the image.

- **Siblings:** Nodes which have the same parent are called siblings. In the above image {D,E} are called siblings.

- **Descendant:** Any successor node on the path from the leaf node to that node. {E,I} are the descendants of the node {B}.

- **Descendant:** Descendant are the set of nodes which can be reached from a particular nodes. {D, E, H, I, K, L, M, N} are descendant of node {B}.

- **Internal node:** A node with at least one child is called Internal Node.

- **Leaf Node or External Node:** The nodes which do not have any child nodes are called leaf nodes. {K, L, M, N, O, P, G} are the leaf nodes of the tree.


