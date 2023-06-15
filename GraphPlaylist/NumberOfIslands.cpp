class Solution {
  public:
    vector <vector <pair <int, int>>> P;
    vector <vector <int>> S;
    vector <vector <int>> L;
    vector <pair <int, int>> MM = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool F(int x, int y, int n, int m) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }
    
    void M_Node (int x, int y) {
        P[x][y] = {x, y};
        S[x][y] = 1;
    }
    
    pair <int, int> Boss_Node(pair <int, int> x) {
        if(P[x.first][x.second] == x) return x;
        else return P[x.first][x.second] = Boss_Node(P[x.first][x.second]);
    }
    
    void Merge_Node(pair <int, int> N1, pair <int, int> N2) {
        N1 = Boss_Node(N1);
        N2 = Boss_Node(N2);
        if(S[N1.first][N1.second] < S[N2.first][N2.second]) swap(N1, N2);
        P[N2.first][N2.second] = N1;
        S[N1.first][N1.second] += S[N2.first][N2.second];
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &O) {
        P.resize(n, vector <pair <int, int>> (m));
        S.resize(n, vector <int> (m, 0));
        L.resize(n, vector <int> (m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                M_Node(i, j);
            }
        }
        
        int k = O.size();
        vector <int> Ans(k);
        Ans[0] = 1;
        for (int i = 0; i < k; i++) {
            pair <int, int> x = {O[i][0], O[i][1]};
            if(L[x.first][x.second] == 1){
                Ans[i] = Ans[i - 1];
                continue;
            }
            L[x.first][x.second] = 1;
            if(i == 0) continue;
            set <pair <int, int>> st;
            for (auto val : MM) {
                pair <int, int> y = {x.first + val.first, x.second + val.second};
                if(F(y.first, y.second, n, m) && L[y.first][y.second] == 1) {
                    y = Boss_Node(y);
                    st.insert(y);
                    Merge_Node(x, y);
                }
            }
            int pre_ = Ans[i - 1];
            pre_ -= (int) st.size();
            pre_ += 1;
            Ans[i] = pre_;
        }
        return Ans;
    }
};
