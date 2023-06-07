class Solution {
public:
    vector <vector <string>> R;
    map <set <pair <int, int>>, int> Dne;
    void F(int I, vector <string> &V, set <pair <int, int>> &U) {
      if(I == V.size()) {
        R.push_back(V);
        return;
      }
      int n = V.size();
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          bool f = 1;
          for (auto ele : U) {
            if(ele.first == i || ele.second == j || abs(ele.first - i) == abs(ele.second - j)) {
              f = 0;
              break;
            }
          }
          if(f) {
            U.insert({i, j});
            if(Dne.count(U) != 0) {
              U.erase({i, j});
              continue;
            }
            V[i][j] = 'Q';
            F(I + 1, V, U);
            Dne[U] = 1;
            V[i][j] = '.';
            U.erase({i, j});
          }
        }
      }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector <string> V;
        for (int i = 0; i < n; i++) {
          string S;
          for (int j = 0; j < n; j++) {
            S.push_back('.');
          }
          V.push_back(S);
        }
        set <pair <int, int>> U;
        F(0, V, U);
        // for (auto vec : RES) {
        //   R.push_back(vec);
        // }
        return R;
    }
};
