class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector <vector <int>> DP(n + 1, vector <int> (m + 1, 1e9));
        //DP[i][j] = min No. of op to make equal till i{1} ans j{2}

        DP[0][0] = 0;
        for (int i = 1; i <= n; i++) {
          DP[i][0] = i;
        }
        for (int j = 1; j <= m; j++) {
          DP[0][j] = j;
        }
        
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= m; j++) {
            if(word1[i - 1] == word2[j - 1]) {
              DP[i][j] = DP[i - 1][j - 1];
            }
            DP[i][j] = min({1 + DP[i - 1][j - 1], 1 + DP[i - 1][j], 1 + DP[i][j - 1], DP[i][j]});
          }
        }
        return DP[n][m];
    }
};
