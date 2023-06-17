class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int S = 0;
        for (int i = 0; i < n; i++) {
            S += arr[i];
        }
        if((S + d) % 2 != 0) {
            return 0;
        }
        int T = (S + d) / 2;
        if(T > S)return 0;
        vector <vector <int>> DP(n + 1, vector <int> (T + 1, 0));
        
        DP[0][0] = 1;
        int M = 1e9 + 7;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= T; j++) {
                if(j - arr[i - 1] >= 0) {
                    DP[i][j] += DP[i - 1][j - arr[i - 1]];
                    DP[i][j] %= M;
                }
                DP[i][j] += DP[i - 1][j];
                DP[i][j] %= M;
            }
        }
        return DP[n][T];
    }
};
