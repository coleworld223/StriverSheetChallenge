class Solution {
public:
    int longestCommonSubsequence(string T1, string T2) {
        int N = T1.size();
        int M = T2.size();

        vector <vector <int>> DP(N + 1, vector <int> (M + 1, 0));
        for (int i = 1; i <= N; i++) {
          for (int j = 1; j <= M; j++) {
            DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            if(T1[i - 1] == T2[j - 1]) {
              DP[i][j] = max(DP[i][j], 1 + DP[i - 1][j - 1]);
            }
          }
        }
        return DP[N][M];
    }
};
