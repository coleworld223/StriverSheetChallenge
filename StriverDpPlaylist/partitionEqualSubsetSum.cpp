class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int N = nums.size();
        int S = 0;
        for (int i = 0; i < N; i++) {
          S += nums[i];
        }
        if(S % 2 != 0) return false;
        vector <vector <int>> DP(N, vector <int> (S + 1, 0));
        DP[0][0] = 1;
        DP[0][nums[0]] = 1;
        S /= 2;
        for (int i = 1; i < N; i++) {
          for (int j = 0; j <= S; j++) {
            if(DP[i - 1][j]) DP[i][j] = 1;
            if(j - nums[i] >= 0) {
              if(DP[i - 1][j - nums[i]] == 1)DP[i][j] = 1;
            }
          }
        }
        return DP[N - 1][S];
    }
};
