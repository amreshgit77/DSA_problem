
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

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    vector<int> ans;
    vector<vector<int>> adj(v + 1);
    vector<int>indegree(v,0);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
         
         for(int i = 0; i<v; i++){
             for(auto j : adj[i]){
                 indegree[j]++;
             }
         }
         
         queue<int>q;
         
         for(int i = 0; i<v; i++){
             if(indegree[i]==0){
                 q.push(i);
             }
         }
         
         int cnt = 0;
         while(!q.empty()){
             int node = q.front();
             q.pop();
             ans.push_back(node);
             for(auto i : adj[node]){
                 indegree[i]--;
                 if(indegree[i] == 0){
                     
                     q.push(i);
                 }
             }
         }

    return ans;
}
