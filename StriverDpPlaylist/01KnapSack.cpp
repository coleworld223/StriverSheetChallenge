class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector <vector <int>> DP(n + 1, vector <int> (W + 1, 0));
       for (int i = 1; i <= n; i++) {
           for (int j = 1; j <= W; j++) {
               if(j - wt[i - 1] >= 0) {
                   DP[i][j] = max(DP[i][j], DP[i - 1][j - wt[i - 1]] + val[i - 1]);
               }
               DP[i][j] = max(DP[i][j], DP[i - 1][j]);
           }
       }
       
       return DP[n][W];
    }
};
