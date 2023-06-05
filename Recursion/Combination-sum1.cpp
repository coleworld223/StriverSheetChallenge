class Solution {
public: 
    map <vector <int>, int> mp;
    void AllSubset(int i, vector <int> &temp, int target, vector <int> &can){
      if(i == can.size()){
        if(target == 0){
          vector <int> temp1 = temp;
          mp[temp]++;
          return;
        }
        else{
          return;
        }
      }
      if(target >= can[i]){
        temp.push_back(can[i]);
        AllSubset(i, temp, target - can[i], can);
        temp.pop_back();
      }
      AllSubset(i + 1, temp, target, can);
    }
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
      vector <int> temp;
      vector <vector <int>> ans;
      AllSubset(0, temp, target, can);
      for (auto ele : mp){
        ans.push_back(ele.first);
      }
      return ans;
    }
};
