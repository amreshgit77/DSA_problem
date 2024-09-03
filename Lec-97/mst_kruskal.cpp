#include<algorithm>
#include <vector>
using namespace std;
bool cmp(vector<int>& a ,vector<int>&b){
     return a[2]<b[2];
}
void makeSet(vector<int>&rank,vector<int>&parent,int n){
    for(int i = 0; i<n; i++){
        parent[i]=i;
        rank[i] =0;
    }
}
int findParent(vector<int>&parent, int node){
    if(parent[node] == node){
      return node;
    }
    return parent[node] = findParent(parent, parent[ node]) ;
}
void unionSet(vector<int>&rank,vector<int>&parent,int u,int v){
  u = findParent(parent, u);
  v = findParent(parent, v);

  if(rank[u]<rank[v]){
    parent[u]= v;
    
  }
  else if(rank[u]>rank[v]){
    parent[v]= u;
  }
  else{
    parent[v] =u;
    rank[u]++;
  }
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  vector<int>rank(n);
  vector<int>parent(n);
  makeSet(rank,parent,n);
  sort(edges.begin(),edges.end(),cmp);

int answeight =0;
  for(int i =0;i<edges.size() ; i++){
      int u = findParent(parent, edges[i][0]);
      int v = findParent(parent, edges[i][1]);
      int wt = edges[i][2];

      
      if(u!=v){
        answeight += wt;
        unionSet(rank, parent, u,v);
      }
  }
  return answeight;
}