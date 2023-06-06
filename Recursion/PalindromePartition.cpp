class Solution {
public:
    vector <vector <string>> A;
    void F(int i, vector <string> &V, string &s){
      if(i == s.size()) {
        A.push_back(V);
        return;
      }
      string temp = "";
      for (int j = i; j < s.size(); j++) {
        temp.push_back(s[j]);
        bool chk = 1;
        for (int k = 0; k < (int) temp.size() / 2; k++) {
          if(temp[k] != temp[(int) temp.size() - k - 1]) chk = 0;
        }
        if(chk) {
          V.push_back(temp);
          F(j + 1, V, s);
          V.pop_back();
        }
      }
    }
    vector<vector<string>> partition(string s) {
        vector <string> V;
        F(0, V, s);
        return A;
    }
};
