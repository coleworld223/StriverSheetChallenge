class Solution {
public:
    int change(int T, vector<int>& coins) {
        int n = coins.size();
        vector <int> DP(T + 1, 0);
        DP[0] = 1;
        for (int i = 0; i < n; i++) {
          for (int j = 1; j <= T; j++) {
            if(j - coins[i] >= 0) {
              DP[j] += DP[j - coins[i]];
            }
          }
        }
        return DP[T];
    }
};
