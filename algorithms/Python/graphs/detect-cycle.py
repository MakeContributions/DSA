# Detect cycle in a directed graph
# Time Complexity: O(V+E)
# Space Complexity: O(V)

# The main idea is to use DFS and keep track of the path
# If we encounter a node that is already in the path, then there is a cycle


def has_cycle(graph):
    # visited is a set that keeps track of all the visited nodes
    # path is a set that keeps track of all the nodes in the current path
    visited = set()
    path = set()
    # here we are using nested function
    # It is a function inside a function
    # we are using it because we want to use visited and path variables
    # which are defined outside the function
    # if we don't use nested function then we have to pass visited and path as arguments
    # which is not a good practice
    # we can also use global keyword to use visited and path variables

    def dfs(vertex):
        visited.add(vertex)
        path.add(vertex)
        for neighbor in graph[vertex]:  # graph[vertex] is a list of all the neighbors of vertex
            if neighbor in path:
                return True
            if neighbor not in visited:
                if dfs(neighbor):  # if dfs(neighbor) returns True then return True
                    return True
        path.remove(vertex)
        return False

    for vertex in graph:
        if vertex not in visited:
            if dfs(vertex):
                return True

    return False


# Test cases for the function
# This graph has no cycles
graph = {
    'a': ['b', 'c'],
    'b': ['d'],
    'c': ['d'],
    'd': ['e'],
    'e': []
}
# This graph has a cycle
graph2 = {
    'a': ['b', 'c'],
    'b': ['d'],
    'c': ['d'],
    'd': ['e'],
    'e': ['a']
}

# calling the functions
print(has_cycle(graph))
print(has_cycle(graph2))
