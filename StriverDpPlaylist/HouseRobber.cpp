class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        vector <vector <int>> DP(N, vector <int> (2, 0));
        DP[0][0] = 0;
        DP[0][1] = nums[0];

        for (int i = 1; i < N; i++) {
          DP[i][0] = max(DP[i - 1][0], DP[i - 1][1]);
          DP[i][1] = max(DP[i - 1][0] + nums[i], DP[i][1]);
        }
        return max(DP[N - 1][0], DP[N - 1][1]);
    }
};
