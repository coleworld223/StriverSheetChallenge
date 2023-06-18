class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector <vector <int>> DP(n + 1, vector <int> (m + 1));
        vector <vector <pair <int, int>>> From(n + 1, vector <pair <int, int>> (m + 1));
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= m; j++) {
            if(str1[i - 1] == str2[j - 1]) {
              DP[i][j] = 1 + DP[i - 1][j - 1];
              From[i][j] = {i - 1, j - 1};
            }
            DP[i][j] = max({DP[i][j], DP[i - 1][j], DP[i][j - 1]});
            if(DP[i][j] == DP[i - 1][j]) {
              From[i][j] = {i - 1, j};
            }
            if(DP[i][j] == DP[i][j - 1]) {
              From[i][j] = {i, j - 1};
            }
          }
        }
        cout << DP[n][m] << endl;
        pair <int, int> Mover = {n, m};
        vector <int> S1;
        vector <int> S2;
        while(Mover.first > 0 && Mover.second > 0) {
          pair <int, int> N_Node = From[Mover.first][Mover.second];
          if(N_Node.first - Mover.first == -1 && N_Node.second - Mover.second == -1) {
            S1.push_back(Mover.first - 1);
            S2.push_back(Mover.second - 1);
          }
          Mover = N_Node;
        }
        reverse(S1.begin(), S1.end());
        reverse(S2.begin(), S2.end());
        for (auto ele : S1) cout << ele << " ";
        cout << endl;
        for (auto ele : S2) cout << ele << " ";
        cout << endl;
        string Ans = "";
        int i1 = 0;
        int i2 = 0;
        for (int i = 0; i < S1.size(); i++) {
          int x = S1[i];
          int y = S2[i];
          while(i1 < x) {
            Ans.push_back(str1[i1++]);
          }
          while(i2 < y) {
            Ans.push_back(str2[i2++]);
          }
          Ans.push_back(str1[i1++]);
          i2++;
        }
        while(i1 < n) {
          Ans.push_back(str1[i1++]);
        }
        while(i2 < m) {
          Ans.push_back(str2[i2++]);
        }
        return Ans;
    }
};
