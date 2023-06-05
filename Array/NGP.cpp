class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int x = nums[n - 1];
        if(n == 1) return;
        
        for (int i = n - 2; i >= 0; i--) {
          int id = -1;
          int cr_min = 1e8;
          for (int j = i + 1; j < n; j++) {
            if(nums[j] > nums[i]){
              if(nums[j] < cr_min){
                cr_min = nums[j];
                id = j;
              }
            }
          }
          if(id != -1){
            swap(nums[i], nums[id]);
            sort(nums.begin() + i + 1, nums.end());
            return;
          }
        }
        sort(nums.begin(), nums.end());
        return;
    }
};
