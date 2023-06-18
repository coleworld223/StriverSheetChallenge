class Solution {
public: 
    string S1, S2;
    int N, M;
    vector <vector <long long>> DP;

    int F(int i, int j){
      if(i < 0) {
        if(j < 0) return true;
        else return false;
      }
      if(j < 0) {
        return 1;
      }
      if(DP[i][j] != -1) return DP[i][j];
      int ret = 0;
      if(S1[i] == S2[j]) {
        ret += F(i - 1, j - 1);
      }
      ret += F(i - 1, j);
      return DP[i][j] = ret;
    }
    int numDistinct(string s, string t) {
      S1 = s;
      S2 = t;
      N = s.size();
      M = t.size();
      DP.resize(N + 1, vector <long long> (M + 1, 0));  

      DP[0][0] = 1;
      for (int i = 1; i <= M; i++) {
        DP[0][i] = 0;
      }  
      for (int i = 1; i <= N; i++) {
        DP[i][0] = 1;
      }

      for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
          if(S1[i - 1] == S2[j - 1]) {
            DP[i][j] += DP[i - 1][j - 1];
          }
          if(DP[i][j] > INT_MAX)continue; //otherwise overflow think why
          DP[i][j] += DP[i - 1][j];
        }
      }
      return DP[N][M];
    }
};
