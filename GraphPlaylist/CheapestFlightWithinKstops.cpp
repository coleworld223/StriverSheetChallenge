class Solution {
  public:
    vector <vector <pair <int, int>>> A;
    vector <int> V;
    int CheapestFLight(int n, vector<vector<int>>& f, int src, int dst, int K)  {
        A.resize(n);
        V.resize(n, 1e9);
        for (int i = 0; i < f.size(); i++) {
            A[f[i][0]].push_back({f[i][1], f[i][2]});
        }
        
        set <vector <int>> S;
        S.insert({0, 0, src});
        V[src] = 0;
        
        while(!S.empty()) {
            auto u = (*S.begin());
            S.erase(S.begin());
            for (auto v : A[u[2]]) {
                if(V[v.first] > u[1] + v.second) {
                    V[v.first] = u[1] + v.second;
                    if(u[0] + 1 <= K){
                        vector <int> T = {u[0] + 1, V[v.first], v.first};
                        S.insert(T);
                    }
                }
            }
        }
        return (V[dst] == 1e9 ? -1 : V[dst]);
    }
};
