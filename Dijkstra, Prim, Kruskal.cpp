// Graph Algorithms: Dijkstra, Prim, Kruskal

#include <bits/stdc++.h>
using namespace std;

// 1. Dijkstra's Algorithm
void dijkstra(vector<pair<int, int>> graph[], int n, int start)
{
    vector<int> dist(n, 1e9);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [cost, node] = pq.top();
        pq.pop();
        for (auto [neighbor, weight] : graph[node])
        {
            if (dist[neighbor] > cost + weight)
            {
                dist[neighbor] = cost + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    cout << "Dijkstra's Shortest Paths:\n";
    for (int i = 0; i < n; i++)
        cout << "Node " << i << ": " << dist[i] << endl;
}

// 2. Prim's Algorithm
void prim(vector<pair<int, int>> graph[], int n)
{
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    visited[0] = true;
    for (auto [neighbor, weight] : graph[0])
        pq.push({weight, neighbor});

    int mst_cost = 0;
    while (!pq.empty())
    {
        auto [weight, node] = pq.top();
        pq.pop();
        if (!visited[node])
        {
            visited[node] = true;
            mst_cost += weight;
            for (auto [neighbor, w] : graph[node])
                if (!visited[neighbor])
                    pq.push({w, neighbor});
        }
    }
    cout << "Prim's MST cost: " << mst_cost << endl;
}

// 3. Kruskal's Algorithm
int find_parent(vector<int> &parent, int u)
{
    if (parent[u] != u)
        parent[u] = find_parent(parent, parent[u]);
    return parent[u];
}

void kruskal(vector<tuple<int, int, int>> &edges, int n)
{
    sort(edges.begin(), edges.end());
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    int mst_cost = 0;

    for (auto [weight, u, v] : edges)
    {
        if (find_parent(parent, u) != find_parent(parent, v))
        {
            mst_cost += weight;
            parent[find_parent(parent, u)] = find_parent(parent, v);
        }
    }
    cout << "Kruskal's MST cost: " << mst_cost << endl;
}

int main()
{
    int n = 4;
    vector<pair<int, int>> graph[4];
    graph[0] = {{1, 4}, {2, 1}};
    graph[1] = {{3, 1}};
    graph[2] = {{1, 2}, {3, 5}};

    vector<tuple<int, int, int>> edges = {
        {4, 0, 1},
        {1, 0, 2},
        {2, 2, 1},
        {1, 1, 3},
        {5, 2, 3}};

    cout << "\n--- Dijkstra ---\n";
    dijkstra(graph, n, 0);

    cout << "\n--- Prim ---\n";
    prim(graph, n);

    cout << "\n--- Kruskal ---\n";
    kruskal(edges, n);
}
