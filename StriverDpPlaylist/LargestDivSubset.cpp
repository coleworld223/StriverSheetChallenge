class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector <pair <int, int>> DP(n);
        sort(nums.begin(), nums.end());
        DP[n - 1] = {1, n - 1};
        for (int i = n - 2; i >= 0; i--) {
          DP[i] = {1, i};
          for (int j = i + 1; j < n; j++) {
            if(nums[j] % nums[i] == 0) {
              if(1 + DP[j].first > DP[i].first) {
                 DP[i] = {1 + DP[j].first, j};
              } 
            }
          }
        }
        int Ans = 1; int idx = 0;
        for (int i = 0; i < n; i++) {
          if(DP[i].first > Ans) {
            Ans = DP[i].first;
            idx = i;
          }
        }
        vector <int> Sub;
        while(DP[idx].second != idx) {
          Sub.push_back(nums[idx]);
          idx = DP[idx].second;
        }
        Sub.push_back(nums[idx]);
        return Sub;
    }
};
