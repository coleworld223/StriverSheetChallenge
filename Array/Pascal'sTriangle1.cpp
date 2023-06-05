class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector <int>> ans;
        vector <int> temp = {1};
        vector <int> temp1 = {1, 1};
        ans.push_back(temp);
        if(numRows == 1) return ans;
        ans.push_back(temp1);
        if(numRows == 2) return ans;
        

        for (int i = 2; i < numRows; i++) {
          vector <int> tt;
          tt.push_back(1);
          for (int j = 0; j < i - 1; j++) {
            tt.push_back(ans[i - 1][j] + ans[i - 1][j + 1]);
          }
          tt.push_back(1);
          ans.push_back(tt);
        }
        return ans;
    }
};
