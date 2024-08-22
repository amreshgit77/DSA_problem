#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;
void bfs(vector<vector<int>> adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        int frontNode = q.front();
        ans.push_back(frontNode);
        q.pop();

        for (auto i : adjList[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    vector<int> ans;
    unordered_map<int, bool> visited;

    bfs(adj, visited, ans, 0);

    return ans;
}
int main(){
    
    cout<<10%10;
    return 0;
}