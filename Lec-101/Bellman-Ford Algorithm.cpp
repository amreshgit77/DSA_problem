#include<algorithm>
#include <vector>
using namespace std;
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int>dist(V,1e8);
        
        
        dist[S] =0;
        
        for(int i = 1; i<=V-1; i++){
            
            for(int j =0; j<edges.size(); j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                
                if(dist[u]!= 1e8 && (dist[u] + w < dist[v])){
                    dist[v] = w+dist[u];
                }
        }
        }
        bool flag = 0;
       for(int j =0; j<edges.size(); j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                
                if(dist[u]!= 1e8 && (dist[u] + w < dist[v])){
                    flag = 1;
                }
        }
        if(flag){
            return {-1};
        }
        return dist;
    }