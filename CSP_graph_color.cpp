#include<bits/stdc++.h>
using namespace std;

// Graph adjacency matrix for a graph with 4 vertices
int graph[4][4] = {
    {0, 1, 1, 1}, // Vertex 0 is connected to 1, 2, 3
    {1, 0, 1, 0}, // Vertex 1 is connected to 0, 2
    {1, 1, 0, 1}, // Vertex 2 is connected to 0, 1, 3
    {1, 0, 1, 0}  // Vertex 3 is connected to 0, 2
};

// Check if it's safe to assign color c to the node
bool is_safe(int node, int color[], int c) {
    // Loop through all adjacent nodes
    for(int i = 0; i < 4; i++) {
        // If the node is connected and the adjacent node has the same color, return false
        if(graph[node][i] && color[i] == c)
            return false;
    }
    return true;  // No conflict found
}

// Backtracking function to assign colors to the nodes
void graphColoring(int node, int color[], int m) {
    // If all nodes are colored, print the color assignment
    if(node == 4) {
        for(int i = 0; i < 4; i++) cout << color[i] << " ";
        cout << endl;
        return;
    }

    // Try different colors for the current node
    for(int c = 1; c <= m; c++) {
        // If assigning color c to this node is safe
        if(is_safe(node, color, c)) {
            color[node] = c;  // Assign color to the node
            graphColoring(node + 1, color, m);  // Recurse for the next node
            color[node] = 0;  // Backtrack and reset the color
        }
    }
}

int main() {
    int color[4] = {0};  // Array to store color assignments for each node
    int m = 3;  // Number of colors allowed

    // Call the backtracking function to color the graph starting from node 0
    graphColoring(0, color, m);

    return 0;
}
