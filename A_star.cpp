#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int heuristic(pii a, pii b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void a_star(pii start, pii goal)
{
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> open_set;
    open_set.push({0, start});
    map<pii, int> g_score;
    g_score[start] = 0;
    while (!open_set.empty())
    {
        pii current = open_set.top().second;
        open_set.pop();
        if (current == goal)
        {
            cout << "Path found!" << endl;
            return;
        }
        vector<pii> neighbors = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto [dx, dy] : neighbors)
        {
            pii neighbor = {current.first + dx, current.second + dy};
            if (neighbor.first >= 0 && neighbor.second >= 0 && neighbor.first < 5 && neighbor.second < 5)
            {
                int temp_g = g_score[current] + 1;
                if (!g_score.count(neighbor) || temp_g < g_score[neighbor])
                {
                    g_score[neighbor] = temp_g;
                    int f_score = temp_g + heuristic(neighbor, goal);
                    open_set.push({f_score, neighbor});
                }
            }
        }
    }
    cout << "Path not found!" << endl;
}

int main()
{
    pii start = {0, 0};
    pii goal = {4, 4};
    a_star(start, goal);
    return 0;
}

//......................................................................................//
// A* Maze solver

#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <cmath>
#include <set>
using namespace std;

typedef pair<int, int> pii;

// Directions: up, down, left, right
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int heuristic(pii a, pii b)
{
    // Manhattan Distance
    return abs(a.first - b.first) + abs(a.second - b.second);
}

vector<pii> astar(vector<vector<int>> &maze, pii start, pii end)
{
    priority_queue<tuple<int, int, pii, vector<pii>>, vector<tuple<int, int, pii, vector<pii>>>, greater<>> pq;
    set<pii> visited;

    pq.push({heuristic(start, end), 0, start, {start}});

    while (!pq.empty())
    {
        auto [est_total, cost, current, path] = pq.top();
        pq.pop();

        if (current == end)
            return path;

        if (visited.count(current))
            continue;
        visited.insert(current);

        for (auto &d : dir)
        {
            int nx = current.first + d[0];
            int ny = current.second + d[1];

            if (nx >= 0 && ny >= 0 && nx < maze.size() && ny < maze[0].size() && maze[nx][ny] == 0)
            {
                vector<pii> new_path = path;
                new_path.push_back({nx, ny});
                pq.push({cost + 1 + heuristic({nx, ny}, end), cost + 1, {nx, ny}, new_path});
            }
        }
    }
    return {};
}

int main()
{
    vector<vector<int>> maze = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0}};

    pii start = {0, 0};
    pii end = {4, 4};

    vector<pii> path = astar(maze, start, end);
    if (!path.empty())
    {
        cout << "Path found: ";
        for (auto [x, y] : path)
            cout << "(" << x << "," << y << ") ";
        cout << endl;
    }
    else
    {
        cout << "No path found." << endl;
    }
}
