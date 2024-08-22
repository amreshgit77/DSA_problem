#include <bits/stdc++.h>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	vector<int>visited(n+1,0);
	unordered_map<int,int>parent;
	vector<int>ans;
	vector<vector<int>>adjList(n+1);
	for(int i =0; i<m; i++){
		int u = edges[i].first;
		int v = edges[i].second;

		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	queue<int>q;
	q.push(s);
	parent[s] =-1;
    visited[s]=1;
	while(!q.empty()){
		int frontNode = q.front();
		q.pop();
		for(auto i : adjList[frontNode]){
			if(!visited[i]){
				q.push(i);
				parent[i] = frontNode;
				visited[i]=1;
				if (i == t) {
                    break; // Early exit if we reach the target node
                }
			}
		}
	}

	int currNode = t;
	ans.push_back(currNode);

	while(currNode!= s){
		currNode = parent[currNode];
		ans.push_back(currNode);
	}

    reverse(ans.begin(),ans.end());
	return ans;

	
}