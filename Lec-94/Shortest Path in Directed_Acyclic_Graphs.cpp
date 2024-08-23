#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
#include <limits.h>
using namespace std;

class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;
    void addEdge(int u, int v, int weight)
    {
        adj[u].emplace_back(v, weight); // More concise way to add the pair
    }

    void PrintGraph()
    {
        for (auto &i : adj)
        {
            cout << i.first << " -> ";
            for (auto &p : i.second)
            {
                cout << "[" << p.first << ", " << p.second << "] ";
            }
            cout << endl;
        }
    }

    void DFS(stack<int> &s, vector<int> &visited, int node)
    {
        visited[node] = 1;

        for (auto &i : adj[node])
        {
            if (!visited[i.first])
            {
                DFS(s, visited, i.first);
            }
        }
        s.push(node);
    }

    void shortestPath(vector<int> &dist, stack<int> &topo, int src)
    {
        dist[src] = 0;
        while (!topo.empty())
        {
            int top = topo.top();
            topo.pop();
            if (dist[top] != INT_MAX)
            {
                for (auto &i : adj[top])
                {
                    if (dist[top] + i.second < dist[i.first])
                    {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
};

int main()
{
    graph G;
    G.addEdge(1, 3, 6);
    G.addEdge(1, 2, 2);
    G.addEdge(0, 1, 5);
    G.addEdge(0, 2, 3);
    G.addEdge(3, 4, -1);
    G.addEdge(2, 4, 4);
    G.addEdge(2, 5, 2);
    G.addEdge(2, 3, 7);
    G.addEdge(4, 5, -2);

    int n = 6; // Total number of nodes

    cout << "Printing graph->>>" << endl;
    G.PrintGraph();

    vector<int> visited(n, 0);
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            G.DFS(s, visited, i);
        }
    }

    int src = 1; // Source node
    vector<int> dist(n, INT_MAX);
    G.shortestPath(dist, s, src);

    cout << "Printing shortest path distances from source node " << src << ":" << endl;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INT_MAX)
        {
            cout << "Node " << i << " is unreachable" << endl;
        }
        else
        {
            cout << "Distance to node " << i << " is " << dist[i] << endl;
        }
    }

    return 0;
}
