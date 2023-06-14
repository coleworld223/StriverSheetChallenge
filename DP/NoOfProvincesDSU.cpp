class Solution {
  public:
    vector <int> P;
    vector <int> S;
    
    void I(int x) {
        P[x] = x;
        S[x] = 1;
    }
    
    int F(int x) {
        if(P[x] == x) return x;
        else return P[x] = F(P[x]);
    }
    
    void M(int a, int b) {
        a = F(a); b = F(b);
        if(S[a] < S[b]) swap(a, b);
        P[b] = a; S[a] += S[b];
    }
    
    
    int numProvinces(vector<vector<int>> adj, int V) {
        P.resize(V);
        S.resize(V);
        
        for (int i = 0; i < V; i++) I(i);
        
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if(adj[i][j] == 1) {
                    if(F(i) != F(j)) {
                        M(i, j);
                    }
                }
            }
        }
        set <int> St;
        for (int i = 0; i < V; i++) {
            int parr = F(i);
            St.insert(parr);
        }
        
        return (int) St.size();
    }
};
