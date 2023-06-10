class Solution {
  public:
    vector <int> V;
    bool Cycle = 0;
    void D(int u, int p, vector <int> A[]) {
        V[u] = 1;
        for (int v : A[u]){
            if(V[v] == 0) {
                D(v, u, A);
            }
            else if(v != p) {
                Cycle = 1;
            }
        }
    }
    bool isCycle(int N, vector<int> adj[]) {
        V.resize(N, 0);
        for (int i = 0; i < N; i++) {
            if(V[i] == 0) {
                D(i, -1, adj);
            }
        }
        return Cycle;
    }
};
