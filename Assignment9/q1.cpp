//BFS
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);   
        vector<int> bfs;         
        queue<int> q;
        q.push(0);               
        vis[0] = 1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(int it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};
int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    vector<int> adj[V];
    cout << "Enter edges (u v):" << endl;
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    vector<int> result = obj.bfsOfGraph(V, adj);
    cout << "BFS Traversal: ";
    for(int x : result)
        cout << x << " ";
    cout << endl;
    return 0;
}
