#include <bits/stdc++.h>
#include <vector>
#include <string>
///           <<<< -------------------------- Using Kahn's Algorithm ---------------------------------------->>>>
using namespace std;
bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
         vector<int>indegree(V,0);
         
         for(int i = 0; i<V; i++){
             for(auto j : adj[i]){
                 indegree[j]++;
             }
         }
         
         queue<int>q;
         
         for(int i = 0; i<V; i++){
             if(indegree[i]==0){
                 q.push(i);
             }
         }
         
         int cnt = 0;
         while(!q.empty()){
             int node = q.front();
             q.pop();
             cnt++;
             for(auto i : adj[node]){
                 indegree[i]--;
                 if(indegree[i] == 0){
                     
                     q.push(i);
                 }
             }
         }
        
        if(cnt == V){
            return false;
        }
        else{
            return true;
        }
    }