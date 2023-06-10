class Solution {
public:
    vector <vector <int>> DP;
    int minPathSum(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        DP.resize(N, vector <int> (M, 1e8));
        DP[0][0] = grid[0][0];
        for (int i = 0; i < N; i++) {
          for (int j = 0; j < M; j++) {
            if(i - 1 >= 0) {
              DP[i][j] = min(DP[i][j], grid[i][j] + DP[i - 1][j]);
            }
            if(j - 1 >= 0) {
              DP[i][j] = min(DP[i][j], grid[i][j] + DP[i][j - 1]);
            }
          }
        }
        return DP[N - 1][M - 1];
    }
};
