class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector <int> Ans;
        Ans.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
          int idx = lower_bound(Ans.begin(), Ans.end(), nums[i]) - Ans.begin();
          if(idx >= Ans.size()) {
            Ans.push_back(nums[i]);
          }
          else{
            Ans[idx] = nums[i];
          }
        }
        return (int) Ans.size();
    }
};
