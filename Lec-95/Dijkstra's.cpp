#include <bits/stdc++.h> 
#include<limits.h>
#include<unordered_map>
#include<vector>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>dist(V,INT_MAX);
        set<pair<int,int>>setA;
        
        dist[S]=0;
        setA.insert({0,S});
        
        while(!setA.empty()){
            pair<int,int> smallest = *(setA.begin());
            setA.erase(setA.begin());
            for(auto neighbour : adj[smallest.second]){
                int nextNode = neighbour[0];
                int weight = neighbour[1];
                if(weight+smallest.first<dist[nextNode] ){
                    
                    auto record = setA.find({dist[nextNode],nextNode});
                    
                    if(record!= setA.end()){
                        setA.erase(record);
                    }
                    dist[nextNode]= weight+smallest.first;
                    setA.insert({dist[nextNode],nextNode});
                }
            }
            
        }
        
        
        return dist;
    }