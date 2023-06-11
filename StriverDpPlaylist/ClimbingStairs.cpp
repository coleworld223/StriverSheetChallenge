class Solution {
public:
    int climbStairs(int n) {
        vector <int> DP(n + 1);
        DP[0] = 1;
        for (int i = 1; i <= n; i++) {
           if(i - 1 >= 0) DP[i] += DP[i - 1];
           if(i - 2 >= 0) DP[i] += DP[i - 2];
        }
        return DP[n];
    }
};
