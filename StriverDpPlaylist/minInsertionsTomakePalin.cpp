class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        vector <vector <int>> DP(n + 1, vector <int> (n + 1));
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= n; j++) {
            if(s[i - 1] == t[j - 1]) {
              DP[i][j] = 1 + DP[i - 1][j - 1];
            }
            DP[i][j] = max({DP[i][j], DP[i - 1][j], DP[i][j - 1]});
          }
        }
        return n - DP[n][n];
    }
};
