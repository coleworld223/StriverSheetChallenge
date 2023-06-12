class Solution {
  public:
    vector <vector <int>> V;
    int n, m;
    vector <pair <int, int>> M = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool F(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }
    int MinimumEffort(vector<vector<int>>& H) {
        n = H.size();
        m = H[0].size();
        V.resize(n, vector <int> (m, 1e9));
        V[0][0] = 0;
        set <vector <int>> S;
        S.insert({0, 0, 0});
        
        while(!S.empty()) {
            auto u = (*S.begin());
            S.erase(S.begin());
            for (auto dr : M) {
                int nx = u[1] + dr.first;
                int ny = u[2] + dr.second;
                if(F(nx, ny)) {
                    int D = max(u[0], abs(H[u[1]][u[2]] - H[nx][ny]));
                    if(D < V[nx][ny]) {
                        V[nx][ny] = D;
                        vector <int> T = {D, nx, ny};
                        S.insert(T);
                    }
                }
            }
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << V[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return V[n - 1][m - 1];
    }
