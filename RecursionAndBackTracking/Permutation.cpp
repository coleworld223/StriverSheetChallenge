class Solution {
public:
    vector <vector <int>> R;
    void M(int i, int H, vector <int> &V, vector <int> &nums) {
      if(i == nums.size()) {
        R.push_back(V);
        return;
      }
      for (int it = 0; it < nums.size(); it++) {
        if(((H >> it) & 1) == 1)continue;
        V.push_back(nums[it]);
        H |= (1 << it);
        M(i + 1, H, V, nums);
        V.pop_back();
        H &= (~(1 << it));
      }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector <int> V;
        int H = 0;
        M(0, H, V, nums);
        return R;
    }
};
