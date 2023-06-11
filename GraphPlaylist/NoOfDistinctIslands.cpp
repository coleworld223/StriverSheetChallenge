class Solution {
  public:
    int N, M;
    vector <vector <int>> V;
    vector <pair <int, int>> MM = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool F(int x, int y) {
        return x >= 0 && y >= 0 && x < N && y < M;
    }
    map <set <pair <int, int>>, int> C;
    set <pair <int, int>> St;
    void D(int R, int C, pair <int, int> &Root, vector <vector <int>> &grid) {
        V[R][C] = 1;
        St.insert({R - Root.first, C - Root.second});
        for (auto dr : MM) {
            int nR = R + dr.first;
            int nC = C + dr.second;
            if(F(nR, nC) && grid[nR][nC] == 1 && V[nR][nC] == 0) {
                D(nR, nC, Root, grid);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();
        V.resize(N, vector <int> (M, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(grid[i][j] == 1 && V[i][j] == 0) {
                    St.clear();
                    pair <int, int> Root = {i, j};
                    D(i, j, Root, grid);
                    C[St]++;
                }
            }
        }
        return C.size();
    }
};
