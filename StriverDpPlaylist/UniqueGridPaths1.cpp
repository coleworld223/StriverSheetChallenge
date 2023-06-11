class Solution {
public:
    int M = 2e9 + 7;
    using ll = long long;
    int uniquePaths(int n, int m) {
      vector <vector <ll>> DP(n, vector <ll> (m, 0));
      DP[0][0] = 1;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if(i - 1 >= 0)DP[i][j] += DP[i - 1][j];
          DP[i][j] %= M;
          if(j - 1 >= 0)DP[i][j] += DP[i][j - 1];
          DP[i][j] %= M;
        }
      }
      return DP[n - 1][m - 1];
    }
};
