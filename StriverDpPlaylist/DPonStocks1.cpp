class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Ans = 0;
        int C_min = 1e9;
        for (int i = 0; i < prices.size(); i++) {
          Ans = max(Ans, prices[i] - C_min);
          C_min = min(C_min, prices[i]);
        }
        return Ans;
    }
};
