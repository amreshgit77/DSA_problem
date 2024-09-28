#include <bits/stdc++.h> 
#include<limits.h>
#include<unordered_map>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    vector<vector<int>> adj[n + 1];

    for(int i = 0; i<m; i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int>key(n+1,INT_MAX);
    vector<bool>mst(n+1,false);
    vector<int>parent(n+1,-1);

    key[1] =0;
    parent[1]= -1;


    for(int i = 1; i <= n; i++) {
        int mini = INT_MAX;
        int u;

        // Pick the minimum key vertex not in MST
        for(int v = 1; v <= n; v++) {
            if(!mst[v] && key[v] < mini) {
                mini = key[v];
                u = v;
            }
        }

        // Include vertex `u` in MST
        mst[u] = true;

        // Update the keys of adjacent vertices
        for(auto it : adj[u]) {
            int v = it[0];
            int weight = it[1];
            if(!mst[v] && key[v] > weight) {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

     
       vector<pair<pair<int, int>, int>>ans;
       for(int i =2; i<=n; i++){
                ans.push_back({{parent[i],i},key[i]});
       }
       return ans;

}