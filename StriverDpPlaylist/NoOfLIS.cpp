class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector <pair <int, int>> DP(n);
        DP[0] = {1, 1};
        for (int i = 1; i < n; i++) {
          DP[i] = {1, 0};
          for (int j = i - 1; j >= 0; j--) {
            if(nums[j] < nums[i]) {
              if(1 + DP[j].first > DP[i].first) {
                DP[i].first = 1 + DP[j].first;
              }
            }
          }
          for (int j = i - 1; j >= 0; j--) {
            if(nums[j] < nums[i]) {
              if(1 + DP[j].first == DP[i].first) {
                DP[i].second += DP[j].second;
              }
            }
          }
          if(DP[i].second == 0) DP[i].second += 1;
        }
        int Ans = 1;
        for (int i = 0; i < n; i++) {
          Ans = max(Ans, DP[i].first);
        }
        cout << Ans << endl;
        for (int i = 0; i < n; i++) {
          cout << DP[i].first << " " << DP[i].second << endl;
        }
        cout << endl;
        int No_ = 0;
        for (int i = 0; i < n; i++) {
          if(DP[i].first == Ans) {
            No_ += DP[i].second;
          }
        }
        return No_;
    }
};
