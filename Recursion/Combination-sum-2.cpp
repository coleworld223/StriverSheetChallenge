class Solution {
public:
    vector <vector <int>> ans;
    void AllSubset(int i, vector <int> &temp, int target, vector <int> &can){
      if(target == 0){
        ans.push_back(temp);
        return;
      }
      if(i == can.size()) return;
      if(target - can[i] >= 0){
        temp.push_back(can[i]);
        AllSubset(i + 1, temp, target - can[i], can);
        temp.pop_back();
      }
      else return;
      while(i + 1 < can.size() && can[i + 1] == can[i]){ //here if we have decided not to choose some element then we'll never choose any instance of that ele otherwise overcounting
        i++;
      }
      AllSubset(i + 1, temp, target, can);
      return;
    }
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        vector <int> temp;
        sort(can.begin(), can.end());
        AllSubset(0, temp, target, can);
        return ans;
    }
};
