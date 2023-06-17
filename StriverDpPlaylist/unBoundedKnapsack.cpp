class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector <vector <int>> DP(N + 1, vector <int> (W + 1, 0));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= W; j++) {
                if(j - wt[i - 1] >= 0) {
                    DP[i][j] = max(DP[i][j - wt[i - 1]] + val[i - 1], DP[i][j]);
                }
                DP[i][j] = max(DP[i][j], DP[i - 1][j]);
            }
        }
        return DP[N][W];
    }
};
