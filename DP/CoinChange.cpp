class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       int S = amount;
       int N = coins.size();

       vector <vector <int>> DP(N + 1, vector <int> (S + 1, 1e8));
       for (int i = 1; i <= N; i++) {
         DP[i][0] = 0;
         for (int j = 1; j <= S; j++) {
           DP[i][j] = min(DP[i][j], DP[i - 1][j]);
           if(j - coins[i - 1] >= 0) {
             DP[i][j] = min(DP[i][j], 1 + DP[i][j - coins[i - 1]]);
           }
         }
       } 
       return (DP[N][S] == 1e8 ? -1 : DP[N][S]);
    }
};
