class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        vector <vector <int>> DP(N, vector <int> (M, 2e9));
        DP[0][0] = grid[0][0];
        for (int i = 0; i < N; i++) {
          for (int j = 0; j < M; j++) {
            if(i - 1 >= 0) DP[i][j] = min(DP[i - 1][j] + grid[i][j], DP[i][j]);
            if(j - 1 >= 0) DP[i][j] = min(DP[i][j - 1] + grid[i][j], DP[i][j]);
          }
        }
        return DP[N - 1][M - 1];
    }
};
