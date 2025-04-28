#include <bits/stdc++.h>
using namespace std;

vector<int> graph[6];
bool visited[6] = {false};

void dfs(int node)
{
    cout << node << " ";
    visited[node] = true;
    for (int neighbour : graph[node])
    {
        if (!visited[neighbour])
            dfs(neighbour);
    }
}

void bfs(int start)
{
    queue<int> q;
    bool visitedBfs[6] = {false};
    q.push(start);
    visitedBfs[start] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int neighbour : graph[node])
        {
            if (!visitedBfs[neighbour])
            {
                visitedBfs[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

int main()
{
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 5};
    graph[3] = {1};
    graph[4] = {1};
    graph[5] = {2};

    cout << "DFS:" << endl;
    dfs(0);
    cout << "\nBFS:" << endl;
    bfs(0);

    return 0;
}
