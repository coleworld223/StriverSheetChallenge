class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int N = nums.size();
      vector <int> DP(N, 1);
      DP[0] = 1;
      for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
          DP[i] = max(DP[i], ((nums[i] > nums[j])? 1 + DP[j] : 1));
        }
      }
      return *max_element(DP.begin(), DP.end());
    }
};
