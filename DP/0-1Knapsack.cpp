class Solution
{
    public:
    vector <vector <int>> DP;
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       DP.resize(n + 1, vector <int> (W + 1, 0));
       for (int i = 1; i <= n; i++) {
           for (int j = 1; j <= W; j++) {
               DP[i][j] = max(DP[i][j], DP[i - 1][j]);
               if(j - wt[i - 1] >= 0) {
                   DP[i][j] = max(DP[i][j], DP[i - 1][j - wt[i - 1]] + val[i - 1]);
               }
           }
       }
       return DP[n][W];
    }
};
