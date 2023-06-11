class Solution {
  public:
    vector <int> V, PV;
    bool F = 0;
    void D(int u, vector <int> adj[]) {
        V[u] = 1;
        PV[u] = 1;
        for (int v : adj[u]) {
            if(V[v] == 0) {
                D(v, adj);
            }
            else if(PV[v] == 1) {
                F = 1;
            }
        }
        PV[u] = 0;
    }
    bool isCyclic(int N, vector<int> adj[]) {
        V.resize(N, 0);
        PV.resize(N, 0);
        for (int i = 0; i < N; i++) {
            if(V[i] == 0) {
                D(i, adj);
            }
        }
        return F;
    }
};
