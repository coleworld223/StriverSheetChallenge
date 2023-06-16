class Solution {
public:
    int minimumTotal(vector<vector<int>>& T) {
        int n = T.size();
        vector <vector <int>> DP (n);
        DP[0].resize(1);
        DP[0][0] = T[0][0];
        for (int i = 1; i < n; i++) {
          int n1 = T[i].size();
          DP[i].resize(n1, 1e4);
          cout << DP[i].size() << endl;
          DP[i][0] = DP[i - 1][0] + T[i][0];
          DP[i][n1 - 1] = DP[i - 1][n1 - 2] + T[i][n1 - 1];
          for (int j = 1; j < n1 - 1; j++) {
            DP[i][j] = min(DP[i - 1][j] + T[i][j],
             DP[i - 1][j - 1] + T[i][j]);
          }
        }
        int n1 = DP[n - 1].size();
        int Ans = 1e9;
        for (int i = 0; i < n1; i++) {
          Ans = min(Ans, DP[n - 1][i]);
        }
        return Ans;
    }
};
