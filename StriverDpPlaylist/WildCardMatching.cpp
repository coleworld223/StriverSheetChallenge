class Solution {
public:
    string S1, S2;
    int N, M;
    vector <vector <int>> DP;
    bool F(int i, int j) {
      if(i < 0 || j < 0) {
        if(i < 0 && j < 0) return true;
        else {
          if(i >= 0 && j < 0) {
            bool ch = 1;
            for (int k = 0; k <= i; k++) {
              if(S1[k] != '*') ch = 0;
            }
            return ch;
          }
          if(j >= 0 && i < 0) {
            bool ch = 1;
            for (int k = 0; k <= j; k++) {
              if(S2[k] != '*') {
                ch = 0;
              }
            }
            return ch;
          }
        }
      }
      if(DP[i][j] != -1) {
        return DP[i][j];
      }
      bool R = 0;
      if(S1[i] == '?' || S2[j] == '?') {
        R |= F(i - 1, j - 1);
      }
      if(S1[i] == S2[j]) {
        R |= F(i - 1, j - 1);
      }
      if(S1[i] == '*') {
        for (int k = j; k >= -1; k--) {
          R |= F(i - 1, k);
        }
      } 
      if(S2[j] == '*') {
        for (int k = i; k >= -1; k--) {
          R |= F(k, j - 1);
        }
      }
      return DP[i][j] = R;
    }
    bool isMatch(string s, string p) {
      N = s.size();
      M = p.size();
      S1 = s;
      S2 = p;   
      DP.resize(N, vector <int> (M, -1));
      return F(N - 1, M - 1);   
    }
};
