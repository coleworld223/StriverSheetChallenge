class Solution {
public:
    int MOD = 2e9 + 7;
    using ll = long long;
    int uniquePathsWithObstacles(vector<vector<int>>& O) {
        int N = O.size();
        int M = O[0].size();
        vector <vector <ll>> DP(N, vector <ll> (M, 0));
        if(O[0][0] == 0) {
          DP[0][0] = 1;
        }
        cout << DP[0][0] << endl;
        for (ll i = 0; i < N; i++) {
          for (ll j = 0; j < M; j++) {
            if(O[i][j] == 1)continue;
            if(i - 1 >= 0) DP[i][j] += DP[i - 1][j];
            DP[i][j] %= MOD;
            if(j - 1 >= 0) DP[i][j] += DP[i][j - 1];
            DP[i][j] %= MOD;
          }
        }
        cout << DP[0][0] << endl;
        return DP[N - 1][M - 1];
    }
};
