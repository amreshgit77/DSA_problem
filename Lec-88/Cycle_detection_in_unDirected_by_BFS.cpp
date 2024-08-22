#include <unordered_map>
#include <queue>
#include <vector>
#include <string>
using namespace std;

bool findCycle(unordered_map<int, bool> &visited, unordered_map<int, int> &parent,
               vector<vector<int>> &adjList, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    parent[node] = -1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto i : adjList[frontNode])
        {
            if (visited[i] && parent[frontNode] != i)
            {
                return true;
            }
            else if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
                parent[i] = frontNode;
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    vector<vector<int>> adjList(n + 1);
    string ans = "";

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool res = findCycle(visited, parent, adjList, i);
            if (res)
            {
                return "Yes";
            }
        }
    }
    return "No";
}
