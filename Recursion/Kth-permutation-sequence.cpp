//used hash variable for lesser time comp
//Alse one thing to note here is that recursion beautifully creates the permutations in order so no need to sort
class Solution {
public:
    vector <string> R;
    int K;
    void F(int i, int &H, string &A, int n) {
      if(i >= n){
        R.push_back(A);
        return;
      }
      for (int j = 1; j <= n; j++) {
        if(((H >> j) & 1) == 1)continue;
        A.push_back((j + '0'));
        H |= ((1 << j));
        F(i + 1, H, A, n);
        A.pop_back();
        H = (H & (~(1 << j)));
      }
    }
    string getPermutation(int n, int k) {
      int H = 0;
      string A = "";
      K = k;
      F(0, H, A, n);
      return R[k - 1];
    }
};
