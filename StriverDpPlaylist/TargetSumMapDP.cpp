class Solution {
public:
    map <pair <int, int>, int> DP;
    vector <int> V; 
    int F(int i, int T){
      if(i < 0) {
        if(T == 0) return 1;
        else return 0;
      }
      if(DP.count({i, T})) return DP[{i, T}];
      return DP[{i, T}] = (F(i - 1, T - V[i]) + F(i - 1, T + V[i]));
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        V = nums;
        return F(n - 1, target);
    }
};
