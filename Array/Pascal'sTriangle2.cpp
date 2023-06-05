//tc -> O(3 * n * n)
//sc -> O(n * n)
class Solution {
public:
    vector <vector <int>> dp;
    int nCr (int n, int r){
      if(dp[n][r] != -1)return dp[n][r];
      if(r > n) return 0;
      if(n == 1)return 1;
      if(r == 0)return 1;
      return dp[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
    }
    vector<vector<int>> generate(int numRows) {
        vector <vector <int>> ans;
        int n = numRows;
        dp.resize(n + 5, vector <int> (n + 5, -1));

        for (int i = 0; i < numRows; i++) {
          vector <int> tt;
          for (int j = 0; j < i + 1; j++) {
            tt.push_back(nCr(i, j));
          }
          ans.push_back(tt);
        }
        return ans;
    }
};
