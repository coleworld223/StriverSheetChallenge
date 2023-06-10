class Solution {
public:
    string T1, T2;
    vector <vector <int>> DP;

    int F(int i, int j) {
      if(i < 0 || j < 0) {
        return 1 + max(i, j);
      }
      if(DP[i][j] != -1) return DP[i][j];
      int R = 1e8;
      if(T1[i] == T2[j]) R = min(R, F(i - 1, j - 1));
      R = min(R, 1 + min(F(i - 1, j), F(i, j - 1)));
      R = min(R, 1 + F(i - 1, j - 1));
      return DP[i][j] = R;
    }
    int minDistance(string word1, string word2) {
        int N = word1.size();
        int M = word2.size();
        T1 = word1;
        T2 = word2;
        DP.resize(N, vector <int> (M, -1));
        int Ans = F(N - 1, M - 1);
        return Ans;
    }
};
