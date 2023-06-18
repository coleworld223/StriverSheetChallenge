class Solution {
public:
    int longestCommonSubsequence(string T1, string T2) {
        int n = T1.size();
        int m = T2.size();
        vector <vector <int>> DP(n + 1, vector <int> (m + 1, 0));
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= m; j++) {
            if(T1[i - 1] == T2[j - 1]) {
              DP[i][j] = max(DP[i][j], 1 + DP[i - 1][j - 1]);
            }
            DP[i][j] = max(DP[i - 1][j], DP[i][j]);
            DP[i][j] = max(DP[i][j - 1], DP[i][j]);
          }
        }
        return DP[n][m];
    }
};
