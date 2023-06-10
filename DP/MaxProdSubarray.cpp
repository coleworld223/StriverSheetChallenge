class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int N = nums.size();
        vector <int> DP(N);
        vector <int> DP1(N);

        DP[0] = nums[0];
        DP1[0] = nums[0];

        for (int i = 1; i < N; i++) {
          DP[i] = max(nums[i], max(nums[i] * DP[i - 1], nums[i] * DP1[i - 1]));
          DP1[i] = min(nums[i], min(nums[i] * DP[i - 1], nums[i] * DP1[i - 1]));
        }
        return *max_element(DP.begin(), DP.end());
    }
};
