class Solution {
public:
    vector <vector <int>> DP;
    vector <int> V; 
    int Of = 2e4 + 5;
    int F(int i, int T){
      if(i < 0) {
        if(T == 0) return 1;
        else return 0;
      }
      if(DP[i][T + Of] != -1) return DP[i][T + Of];
      return DP[i][T + Of] = (F(i - 1, T + V[i]) + F(i - 1, T - V[i]));
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        V = nums;
        DP.resize(n, vector <int> (2e5 + 50, -1));
        return F(n - 1, target);
    }
};
