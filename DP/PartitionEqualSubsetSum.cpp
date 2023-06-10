class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int S = 0;
        for (auto ele : nums) S += ele;
        int N = nums.size();
        if(S & 1) return false;
        vector <vector <bool>> DP(N + 1, vector <bool> (S + 1, false));
        DP[0][0] = 1;

        for (int i = 1; i <= N; i++) {
          DP[i][0] = true;
          for (int j = 1; j <= S; j++) {
            DP[i][j] = (DP[i][j] | DP[i - 1][j]);
            if(j - nums[i - 1] >= 0) {
              DP[i][j] = (DP[i][j] | (DP[i - 1][j - nums[i - 1]]));
            }
          }
        }
        return DP[N][S / 2];
    }
};
