# Simple Graph Coloring using Backtracking

# Graph adjacency matrix for a graph with 4 vertices
graph = [
    [0, 1, 1, 1],  # Vertex 0 is connected to 1, 2, 3
    [1, 0, 1, 0],  # Vertex 1 is connected to 0, 2
    [1, 1, 0, 1],  # Vertex 2 is connected to 0, 1, 3
    [1, 0, 1, 0]   # Vertex 3 is connected to 0, 2
]

# Check if it's safe to assign color c to the node
def is_safe(node, color, c):
    for i in range(4):
        # If the node is connected and the adjacent node has the same color
        if graph[node][i] == 1 and color[i] == c:
            return False
    return True  # No conflict found

# Backtracking function to assign colors to the nodes
def graph_coloring(node, color, m):
    # If all nodes are colored, print the color assignment
    if node == 4:
        print("Coloring:", color)
        return

    
    for c in range(1, m + 1):
        # If assigning color c to this node is safe
        if is_safe(node, color, c):
            color[node] = c  # Assign color to the node
            graph_coloring(node + 1, color, m) 
            color[node] = 0  # Backtrack and reset the color

# Main function
def main():
    color = [0] * 4  # Array to store color assignments for each node
    m = 3  # Number of colors allowed

    # Call the backtracking function to color the graph starting from node 0
    graph_coloring(0, color, m)

if __name__ == "__main__":
    main()
