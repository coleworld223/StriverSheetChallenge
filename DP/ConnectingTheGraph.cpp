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
        P[b] = a; S[a] += b;
    }
    int Solve(int n, vector<vector<int>>& edge) {
        P.resize(n);
        S.resize(n);
        int E_edges = 0;
        for (int i = 0; i < n; i++) {
            I(i);
        }
        
        for (int i = 0; i < edge.size(); i++) {
            int u = edge[i][0];
            int v = edge[i][1];
            u = F(u);
            v = F(v);
            if(u != v) {
                M(u, v);
            }
            else{
                E_edges++;
            }
        }
        int Cc = 0;
        set <int> St;
        for (int i = 0; i < n; i++) {
            St.insert(F(i));
        }
        Cc = (int) St.size();
        if(Cc - 1 > E_edges) return -1;
        else{
            return Cc - 1;
        }
    }
};
