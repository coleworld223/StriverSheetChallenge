class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector <vector <int>> DP(n + 1, vector <int> (m + 1));
        // DP[i][j] = lcsubstring ending at i and j 
        int Ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if(S1[i - 1] == S2[j - 1]) {
                    DP[i][j] = max(DP[i][j], 1 + DP[i - 1][j - 1]);
                }
                Ans = max(Ans, DP[i][j]);
            }
        }
        return Ans;
    }
};
