class Solution {
  public:
    vector <int> R;
    vector <int> vis;
    void D(int u, vector <int> adj[]){
        vis[u] = 1;
        R.push_back(u);
        for (auto v : adj[u]) {
            if(!vis[v]) {
                D(v, adj);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vis.resize(V);
        D(0, adj);
        return R;
    }
};
