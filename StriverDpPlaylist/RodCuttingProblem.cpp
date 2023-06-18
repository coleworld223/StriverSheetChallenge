class Solution{
  public:
    int cutRod(int price[], int n) {
        vector <int> DP(n + 1, 0);
        DP[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if(i - j >= 0) {
                    DP[i] = max(DP[i], DP[i - j] + price[j - 1]);
                }
            }
        }
        return DP[n];
    }
};
