class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& I) {
        int n = I.size();
        sort(I.begin(), I.end(), [&](vector <int> &a, vector <int> &b) {
          return a[0] < b[0];
        });

        int C = 1;
        vector <vector <int>> Ans;
        vector <int> R = {I[0][0], I[0][1]};
        for (int i = 1; i < n; i++) {
          if(I[i][0] > R[1]) {
            Ans.push_back(R);
            R = I[i];
          }
          else{
            R[1] = max(R[1], I[i][1]);
          }
        } 
        Ans.push_back(R);
        return Ans;
    }
};
