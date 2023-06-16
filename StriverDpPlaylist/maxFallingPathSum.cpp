class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();

        vector <vector <int>> DP(N, vector <int> (M, -1e8));
        for (int i = 0; i < N; i++) {
          for (int j = 0; j < M; j++) {
            if(i == 0) DP[i][j] = matrix[i][j];
            else{
              if(j - 1 >= 0) DP[i][j] = max(DP[i][j], DP[i - 1][j - 1] + matrix[i][j]);
              if(j + 1 < M) DP[i][j] = max(DP[i][j], DP[i - 1][j + 1] + matrix[i][j]);
              DP[i][j] = max(DP[i][j], DP[i - 1][j] + matrix[i][j]);
            }
          }
        }
        int Ans = -1e9;
        for (int i = 0; i < M; i++) {
          Ans = max(Ans, DP[N - 1][i]);
        }
        return Ans;
    }
};
