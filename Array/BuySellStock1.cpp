class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = 1e8;
        int mx_profit = 0;
        for (int i = 0; i < prices.size(); i++) {
          mx_profit = max(mx_profit, prices[i] - mn);
          mn = min(mn, prices[i]);
        }
        return mx_profit;
    }
};
