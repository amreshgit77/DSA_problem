#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

void findDFS(unordered_map<int, bool> &visited, vector<vector<int>> &edges, vector<int> &component, int node)
{
    component.push_back(node);
    visited[node] = true;

    for (auto i : edges[node])
    {
        if (!visited[i])
        {
            findDFS(visited, edges, component, i);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    vector<vector<int>> adjList(V);
    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for (int i = 0; i < V; i++)
    {
        vector<int> component;
        if (!visited[i])
        {
            findDFS(visited, adjList, component, i);
            ans.push_back(component);
        }
    }
    return ans;
}