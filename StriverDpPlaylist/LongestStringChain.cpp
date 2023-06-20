class Solution {
public:
    bool Check(string &A, string &B) {
      //is A a predecessor of B
      int nA = A.size();
      int nB = B.size();
      int i = 0;
      int j = 0;
      if(nB - nA != 1) return false;
      int ct = 0;
      while(j < nB && i < nA) {
        if(A[i] == B[j]) {
          i++;
          j++;
        }
        else{
          j++;
          ct++;
        }
      }
      return (ct <= 1);
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [&] (string &A, string &B) {
          return A.size() < B.size();
        });
        vector <int> DP(n, 1);
        for (int i = n - 2; i >= 0; i--) {
          for (int j = i + 1; j < n; j++) {
            if(Check(words[i], words[j])) {
              if(DP[j] + 1 > DP[i]) {
                DP[i] = DP[j] + 1;
              }
            }
          }
        }
        return *max_element(DP.begin(), DP.end());
    }
};
