#include <unordered_map>

#include <vector>
#include <string>

using namespace std;

bool findCycle(unordered_map<int, bool> &visited, unordered_map<int, bool> &DfsVisited,
               vector<vector<int>> &adjList, int node)
{
    visited[node] = true;
    DfsVisited[node] = true;

    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            if (findCycle(visited, DfsVisited, adjList, i))
            {
                return true;
            }
        }
        else if (DfsVisited[i])
        {
            return true;
        }
    }
    DfsVisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // Write your code here.
    unordered_map<int, bool> visited;
    unordered_map<int, bool> DfsVisited;
    vector<vector<int>> adjList(n + 1);

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool res = findCycle(visited, DfsVisited, adjList, i);
            if (res)
            {
                return 1;
            }
        }
    }
    return 0;
}