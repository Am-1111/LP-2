# Graph Algorithms: Dijkstra, Prim, Kruskal

import heapq

# 1. Dijkstra's Algorithm
def dijkstra(graph, start):
    heap = [(0, start)]
    dist = {node: float('inf') for node in graph}
    dist[start] = 0

    while heap:
        cost, node = heapq.heappop(heap)
        for neighbor, weight in graph[node]:
            if dist[neighbor] > cost + weight:
                dist[neighbor] = cost + weight
                heapq.heappush(heap, (dist[neighbor], neighbor))
    
    print("Dijkstra's Shortest Paths:", dist)

# 2. Prim's Algorithm
def prim(graph):
    start = next(iter(graph))
    visited = set([start])
    edges = [(weight, start, to) for to, weight in graph[start]]
    heapq.heapify(edges)
    mst_cost = 0

    while edges:
        weight, frm, to = heapq.heappop(edges)
        if to not in visited:
            visited.add(to)
            mst_cost += weight
            for to_next, weight_next in graph[to]:
                if to_next not in visited:
                    heapq.heappush(edges, (weight_next, to, to_next))
    
    print("Prim's MST cost:", mst_cost)

# 3. Kruskal's Algorithm
def kruskal(edges, n):
    parent = [i for i in range(n)]

    def find(u):
        if parent[u] != u:
            parent[u] = find(parent[u])
        return parent[u]

    mst_cost = 0
    edges.sort()

    for weight, u, v in edges:
        if find(u) != find(v):
            mst_cost += weight
            parent[find(u)] = find(v)

    print("Kruskal's MST cost:", mst_cost)

# --- Example Usage ---

# Graph for Dijkstra and Prim (Adjacency list)
graph = {
    0: [(1, 4), (2, 1)],
    1: [(3, 1)],
    2: [(1, 2), (3, 5)],
    3: []
}

# Edges for Kruskal (weight, u, v)
edges = [
    (4, 0, 1),
    (1, 0, 2),
    (2, 2, 1),
    (1, 1, 3),
    (5, 2, 3)
]

print("\n--- Dijkstra ---")
dijkstra(graph, 0)

print("\n--- Prim ---")
prim(graph)

print("\n--- Kruskal ---")
kruskal(edges, 4)
