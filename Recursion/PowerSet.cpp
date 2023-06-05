class Solution {
public:
    map <vector <int>, int> mp;
    void AllSubset(int i, vector <int> &temp, vector <int> &nums){
      if(i == nums.size()){
        vector <int> temp1 = temp;
        sort(temp1.begin(), temp1.end());
        mp[temp1]++;
        return;
      }
      temp.push_back(nums[i]);
      AllSubset(i + 1, temp, nums);
      temp.pop_back();
      AllSubset(i + 1, temp, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector <int> temp;
        vector <vector <int>> ans;
        int n = nums.size();
        AllSubset(0, temp, nums);
        for (auto vec : mp){
          ans.push_back(vec.first);
        }
        return ans;
    }
};
