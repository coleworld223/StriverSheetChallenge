class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        vector <vector <int>> DP(N + 1, vector <int> (2, 0));
        DP[0][0] = 0;
        DP[0][1] = -1e9;
        for (int i = 1; i <= N; i++) {
          DP[i][0] = max(DP[i - 1][1] + prices[i - 1], DP[i - 1][0]);
          DP[i][1] = max(DP[i - 1][0] - prices[i - 1], DP[i - 1][1]);
        }
        return DP[N][0];
    }
};
