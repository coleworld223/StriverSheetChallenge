class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_sum = 0;
        int max_sum = 0;
        int n = nums.size();
        bool allNeg = 1;
        int subAns = -1e8;

        for (int i = 0; i < n; i++) {
          if(cur_sum + nums[i] <= 0){
            cur_sum = 0;
          }
          else{
            cur_sum += nums[i];
          }
          if(nums[i] > 0) allNeg = 0;
          subAns = max(subAns, nums[i]);
          max_sum = max(max_sum, cur_sum);
        }
        if(allNeg){
          return subAns;
        }
        return max_sum;
    }
};
