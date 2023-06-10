class Solution {
  public:
    vector <vector <int>> A;
    vector <int> vis;
    
    void D(int u) {
        vis[u] = 1;
        for (auto v : A[u]) {
            if(vis[v] == 0) {
                D(v);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        A.resize(V);
        vis.resize(V);
        for (int i = 0; i < adj.size(); i++) {
            for (int j = 0; j < adj[0].size(); j++) {
                if(adj[i][j] == 1) {
                    A[i].push_back(j);
                }
            }
        }
        int C = 0;
        for (int i = 0; i < V; i++) {
            if(vis[i] == 0) {
                D(i);
                C++;
            }
        }
        return C;
    }
};
