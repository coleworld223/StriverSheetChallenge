class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector <int> DP(n);
        DP[0] = 1;
        for (int i = 1; i < n; i++) {
          DP[i] = 1;
          for (int j = i - 1; j >= 0; -- j) {
            if(nums[j] < nums[i]){
              DP[i] = max(DP[i], DP[j] + 1);
            }
          }
        }
  
        cout << endl;
        return *max_element(DP.begin(), DP.end());
    }
};
