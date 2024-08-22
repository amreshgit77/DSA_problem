
#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

// Topology Sort by DFS------------------------------------------------------------------>>>>>

void solve(vector<int> adj[], vector<int> &visited, vector<int> &ans, int node)
{
    visited[node] = 1;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            solve(adj, visited, ans, i);
        }
    }

    ans.push_back(node);
}
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> visited(V, 0);
    vector<int> ans;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            solve(adj, visited, ans, i);
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

// Topology Sort by BFS ( ** Kahn's Algorithm **  )------------------------------------------------------------------>>>>>

void solve(vector<vector<int>> &adjList, vector<int> &visited, int node, vector<int> &ans)
{
    visited[node] = 1;

    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            solve(adjList, visited, i, ans);
        }
    }

    ans.push_back(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{

    vector<vector<int>> adjList(v);

    vector<int> visited(v, 0);

    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int w = edges[i][1];
        adjList[u].push_back(w);
    }

    vector<int> ans;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            solve(adjList, visited, i, ans);
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}
