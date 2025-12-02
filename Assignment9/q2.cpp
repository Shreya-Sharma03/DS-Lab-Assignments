//DFS
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
        vis[node] = 1;          
        ls.push_back(node);     
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, ls);
            }
        }
    }
public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};   
        vector<int> ls;     
        int start = 0;      
        dfs(start, adj, vis, ls);
        return ls;
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
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    vector<int> result = obj.dfsOfGraph(V, adj);
    cout << "DFS Traversal: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;
    return 0;
}
