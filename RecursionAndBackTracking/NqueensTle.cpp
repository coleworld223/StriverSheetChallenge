//This code gives Tle on Test Case n = 9

class Solution {
public:
    void Fill(vector <vector <int>> &V, int R, int C) {
      int n = V.size();
      for (int i = 0; i < n; i++) {
        V[R][i] += 1;
        V[i][C] += 1;
      }
      for (int i = 0; i < n; i++) {
        if(R + i < n && C + i < n) {
          V[R + i][C + i] += 1;
        }
        if(R - i >= 0 && C - i >= 0) {
          V[R - i][C - i] += 1;
        }
        if(R + i < n && C - i >= 0) {
          V[R + i][C - i] += 1;
        }
        if(R - i >= 0 && C + i < n) {
          V[R - i][C + i] += 1;
        }
      }
      
    }

    void DeFill(vector <vector <int>> &V, int R, int C) {
      int n = V.size();
      for (int i = 0; i < n; i++) {
        V[R][i] -= 1;
        V[i][C] -= 1;
      }
      for (int i = 0; i < n; i++) {
        if(R + i < n && C + i < n) {
          V[R + i][C + i] -= 1;
        }
        if(R - i >= 0 && C - i >= 0) {
          V[R - i][C - i] -= 1;
        }
        if(R + i < n && C - i >= 0) {
          V[R + i][C - i] -= 1;
        }
        if(R - i >= 0 && C + i < n) {
          V[R - i][C + i] -= 1;
        }
      }
    }

    vector <vector <string>> R;
    map <set <pair <int, int>>, int> Done;
    set <pair <int, int>> State;
    void F(int n, vector <vector <int>> &T, vector <string> &V){
      if(n == 0) {
        R.push_back(V);
        return;
      }
      int N = V.size();
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          if(T[i][j] != 0) continue;
          V[i][j] = 'Q';
          State.insert({i, j});
          if(Done.count(State)) {
            State.erase({i, j});
            V[i][j] = '.';
            continue;
          }
          Fill(T, i, j);
          F(n - 1, T, V);
          Done[State] = 1;
          DeFill(T, i, j);
          V[i][j] = '.';
          State.erase({i, j});
        }
      }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector <string> V;
        vector <vector <int>> T(n, vector <int> (n, 0));
        for (int i = 0; i < n; i++) {
          string S;
          for (int j = 0; j < n; j++) {
            S.push_back('.');
          }
          V.push_back(S);
        }

        F(n, T, V);
        return R;
    }
};
