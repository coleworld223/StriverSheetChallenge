class Solution {
  public:
    int N, M;
    vector <vector <int>> V;
    vector <vector <char>> G;
    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < N && y < M;
    }
    void D(int R, int C) {
        V[R][C] = 1;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if(isValid(R + dx, C + dy) && V[R + dx][C + dy] == 0
                && G[R + dx][C + dy] == '1') {
                    D(R + dx, C + dy);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        N = grid.size();
        M = grid[0].size();
        G = grid;
        int C = 0;
        V.resize(N, vector <int> (M, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(V[i][j] == 0 && G[i][j] == '1') {
                    D(i, j);
                    C++;
                }
            }
        }
        return C;
    }
};
