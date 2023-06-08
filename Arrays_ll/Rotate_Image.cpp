class Solution {
public:
    pair <int, int> G(pair <int, int> &P, int N) {
      //gives 90 deg rotated cell
      int R = P.first;
      int C = P.second;
      return {C, N - R - 1};
    }
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();

        for (int i = 0; i < (N / 2) + (N % 2 != 0); i++) {
          for (int j = 0; j < N / 2; j++) {
            pair <int, int> P = {i, j};
            int A = matrix[P.first][P.second];
            P = G(P, N);
            int B = matrix[P.first][P.second];
            P = G(P, N);
            int C = matrix[P.first][P.second];
            P = G(P, N);
            int D = matrix[P.first][P.second];
            pair <int, int> Q = {i, j};
            matrix[Q.first][Q.second] = D;
            Q = G(Q, N);
            matrix[Q.first][Q.second] = A;
            Q = G(Q, N);
            matrix[Q.first][Q.second] = B;
            Q = G(Q, N);
            matrix[Q.first][Q.second] = C;
          }
        }
        return;
    }
};
