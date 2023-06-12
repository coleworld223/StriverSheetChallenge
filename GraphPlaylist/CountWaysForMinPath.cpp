class Solution {
  public:
    int MOD = 1e9 + 7;
    vector <vector <pair <int, int>>> A;
    vector <long long> V;
    int countPaths(int n, vector<vector<int>>& roads) {
        A.resize(n);
        V.resize(n, 2e9);
        for (int i = 0; i < roads.size(); i++) {
            A[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            A[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        vector <long long> DP(n, 0);
        DP[0] = 1;
        
        set <pair <int, int>> S;
        int ans = 0;
        S.insert({0, 0});
        V[0] = 0;
        while(!S.empty()) {
            int C = (*S.begin()).second;
            int D = (*S.begin()).first;
            S.erase(S.begin());
            for (auto P : A[C]) {
                int v = P.first;
                int d = P.second;
                if(V[v] >= D + d) {
                    if(V[v] > D + d) {
                        DP[v] = DP[C];
                        V[v] = D + d;
                        S.insert({V[v], v});
                    }
                    else{
                        DP[v] += DP[C];
                        DP[v] %= MOD;
                    }
                }
            }
        }
        // for (int i = 0; i < n; i++) cout << V[i] << " ";
        // cout << endl;
        return DP[n - 1];
    }
};
