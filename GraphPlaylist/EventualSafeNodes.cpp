class Solution {
  public:
    vector <int> V;
    vector <int> PV;
    bool D(int u, vector <int> adj[]) {
        V[u] = 1;
        PV[u] = 1;
        for (int v : adj[u]) {
            if(V[v] == 0) {
                if(D(v, adj) == false) return false;
            }
            else{
                if(PV[v] == 1) {
                    return false;
                }
            }
        }
        PV[u] = 0;
        return true;
    }
    vector<int> eventualSafeNodes(int N, vector<int> adj[]) {
        V.resize(N, 0);
        PV.resize(N, 0);
        
        for (int i = 0; i < N; i++) {
            if(V[i] == 0) {
                D(i, adj);
            }
        }
        vector <int> Ans;
        for (int i = 0; i < N; i++) {
            if(PV[i] == 0) {
                Ans.push_back(i);
            }
        }
        sort(Ans.begin(), Ans.end());
        return Ans;
    }
};
